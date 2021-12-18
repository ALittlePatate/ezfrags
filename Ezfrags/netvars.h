#pragma once
#include <Windows.h>
#include <iostream>
#include <string>

#include "MemManager.h"

class NetvarsClass {
private:
	class RecvTable {
	public:
		std::string GetTableName() {
			DWORD offset = Mem::RPM<DWORD>((DWORD)this + 0xC);
			char tableName[128];
			ReadProcessMemory(Mem::process_handle, (LPCVOID)offset, &tableName, sizeof(tableName), 0);
			return std::string(tableName);
		}
		void* GetProperty(int i) { // RecvProp*
			return (void*)(Mem::RPM<DWORD>((DWORD)this) + 0x3C * i);
		}
		int GetMaxProp() {
			return Mem::RPM<int>((DWORD)this + 0x4);
		}
	};
	class ClientClass {
	public:
		void* GetTable() { // RecvTable*
			return Mem::RPM<void*>((DWORD)this + 0xC);
		}
		void* GetNextClass() { // ClientClass*
			return Mem::RPM<void*>((DWORD)this + 0x10);
		}
	};
	class RecvProp {
	public:
		std::string GetVarName() {
			DWORD offset = Mem::RPM<DWORD>((DWORD)this);
			char vName[128];
			ReadProcessMemory(Mem::process_handle, (LPCVOID)offset, &vName, sizeof(vName), 0);
			return std::string(vName);
		}
		int GetOffset() {
			return Mem::RPM<int>((DWORD)this + 0x2C);
		}
		void* GetDataTable() { // RecvTable*
			return Mem::RPM<void*>((DWORD)this + 0x28);
		}
	};
	DWORD CheckProps(RecvTable* DataTable, std::string NetVarName) {
		for (int i = 0; i < DataTable->GetMaxProp(); i++) {
			auto pRecvProp = reinterpret_cast<RecvProp*>(DataTable->GetProperty(i));
			auto VarName = pRecvProp->GetVarName();
			if (isdigit(VarName[0])) continue;
			if (NetVarName.compare(VarName) == 0) return pRecvProp->GetOffset();
			if (auto DataTable2 = reinterpret_cast<RecvTable*>(pRecvProp->GetDataTable()))
				if (auto Offset = CheckProps(DataTable2, NetVarName)) return Offset;
		}
		return NULL;
	}
	DWORD dwGetAllClasses;
	
public:
	NetvarsClass(DWORD Base) : dwGetAllClasses(Base) {}
	 DWORD NETVAR(std::string ClassName, std::string NetVarName) {
		if (auto pClass = reinterpret_cast<ClientClass*>(dwGetAllClasses))
			for (; pClass != NULL; pClass = reinterpret_cast<ClientClass*>(pClass->GetNextClass()))
				if (auto Table = reinterpret_cast<RecvTable*>(pClass->GetTable()))
					if (Table->GetTableName().compare(ClassName) == 0)
						if (auto Offset = CheckProps(Table, NetVarName)) return Offset;
		return NULL;
	}
};