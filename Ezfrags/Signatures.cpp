#include "MemManager.h"
#include "netvars.h"
#include "Signatures.h"
#include <stdio.h>
#include <iostream>

namespace get_sigs {
	//https://github.com/HeathHowren/Pattern-Scanning/blob/master/patternscanexternal/Source.cpp

	void start() {
		//Netvars
		DWORD dwGetAllClasses = Mem::FindAddress(L"client.dll", "\xA1\x00\x00\x00\x00\xC3\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xA1\x00\x00\x00\x00\xB9","x????xxxxxxxxxxxx????x", 1, 0) + (uintptr_t)Mem::dw_client_address.modBaseAddr;
		DWORD dwGetAllClasses_deref = Mem::RPM<DWORD>(dwGetAllClasses);
		DWORD dwGetAllClasses_offset = dwGetAllClasses_deref - (uintptr_t)Mem::dw_client_address.modBaseAddr;

		std::unique_ptr<NetvarsClass> NetvarManager(new NetvarsClass((uintptr_t)Mem::dw_client_address.modBaseAddr + dwGetAllClasses_offset));
		Netvars::m_fFlags = NetvarManager->NETVAR("DT_CSPlayer", "m_fFlags");
		Netvars::m_flFlashMaxAlpha = NetvarManager->NETVAR("DT_CSPlayer", "m_flFlashMaxAlpha");
		Netvars::m_bSpotted = NetvarManager->NETVAR("DT_BaseEntity", "m_bSpotted");
		
		//Signatures
		Signatures::dwLocalPlayer = Mem::FindAddress(L"client.dll", "\x8D\x34\x85\x00\x00\x00\x00\x89\x15\x00\x00\x00\x00\x8B\x41\x08\x8B\x48\x04\x83\xF9\xFF", "xxx????xx????xxxxxxxxx", 3, 4);
		Signatures::dwForceJump = Mem::FindAddress(L"client.dll", "\x8B\x0D\x00\x00\x00\x00\x8B\xD6\x8B\xC1\x83\xCA\x02", "xx????xxxxxxx", 2, 0);
	}
}
