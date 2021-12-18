#include <iostream>
#include <thread>
#include <Windows.h>
#include <TlHelp32.h>
#include "MemManager.h"

namespace Mem {
    inline MODULEENTRY32 get_module(const char* modName, DWORD proc_id) {
        HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, proc_id);
        if (hSnap != INVALID_HANDLE_VALUE) {
            MODULEENTRY32 modEntry;
            modEntry.dwSize = sizeof(modEntry);
            if (Module32First(hSnap, &modEntry)) {
                do {
                    if (!strcmp(modEntry.szModule, modName)) {
                        CloseHandle(hSnap);
                        return modEntry;
                    }
                } while (Module32Next(hSnap, &modEntry));
            }
        }
        MODULEENTRY32 module = { (DWORD)-1 };
        return module;
    }

    inline void get_csgo() {
        while (1) {
            //Get a window handle to csgo
            HWND hw_csgo = FindWindowA(NULL, "Counter-Strike: Global Offensive - Direct3D 9");

            if (hw_csgo) {
                csgo_found = true;
                //Get csgo's process ID using the handle (No need to make some big function for procid like every other paster does)
                GetWindowThreadProcessId(hw_csgo, &dw_process_id);
                Mem::process_handle = OpenProcess(PROCESS_VM_READ | PROCESS_VM_OPERATION | PROCESS_VM_WRITE, false, dw_process_id);
                break;
            }
        }
        
    }

    inline void get_client_base_address() {
        while (1) {
            Mem::dw_client_address = get_module("client.dll", dw_process_id);
            Mem::client_bytes = new uint8_t[Mem::dw_client_address.modBaseSize]; //making a variable size of the module
            
            Mem::client = (uintptr_t)dw_client_address.modBaseAddr;

            if (Mem::client_bytes) {
                client_dll_found = true;
                break;
            }

            DWORD bytes_read;
            ReadProcessMemory(process_handle, Mem::dw_client_address.modBaseAddr, Mem::client_bytes, Mem::dw_client_address.modBaseSize, &bytes_read); //reading the module and storing as bytes_read
            if (bytes_read != Mem::dw_client_address.modBaseSize) throw; //checking that the size of bytes read is = to size of bytes in the module
            delete[] Mem::client_bytes;
        }
    }

    inline void get_engine_base_address() {
        while (1) {
            MODULEENTRY32 dw_engine_address = get_module("engine.dll", dw_process_id);
            engine_bytes = new uint8_t[dw_engine_address.modBaseSize]; //making a variable size of the module

            Mem::engine = (uintptr_t)dw_engine_address.modBaseAddr;

            if (engine_bytes) {
                engine_dll_found = true;
                break;
            }

            DWORD bytes_read;
            ReadProcessMemory(process_handle, dw_engine_address.modBaseAddr, engine_bytes, dw_engine_address.modBaseSize, &bytes_read); //reading the module and storing as bytes_read
            if (bytes_read != dw_engine_address.modBaseSize) throw; //checking that the size of bytes read is = to size of bytes in the module
            delete[] Mem::engine_bytes;
        }
    }

    //https://github.com/Made0x0000000a/nyfox/blob/main/csgoCheat/patternscan.cpp
    DWORD FindAddress(const wchar_t* moduleName, const char* pattern, const char* mask, const int offset=0, const int extra=0) {
        const MODULEENTRY32 moduleEntry = Mem::dw_client_address;
        const HANDLE hProcess = Mem::process_handle;

        // No Module Entry found
        if (!moduleEntry.th32ModuleID) {
            return NULL;
        }  

        // Module base address = scan starting point
        uintptr_t base = (uintptr_t)moduleEntry.modBaseAddr;
        // Size of Module = scan end point
        uintptr_t size = base + moduleEntry.modBaseSize;

        uintptr_t curChunk = base;
        SIZE_T bytesRead;
        DWORD res;
        int res_plus_offset = 0;

        while (curChunk < size) {
            // Area to scan
            char buffer[4096];

            // Change read protection, raed memory and change read protection back to the original
            DWORD oProtect;
            VirtualProtectEx(hProcess, (LPVOID)curChunk, sizeof(buffer), PAGE_EXECUTE_READWRITE, &oProtect);
            ReadProcessMemory(hProcess, (LPVOID)curChunk, &buffer, sizeof(buffer), &bytesRead);
            VirtualProtectEx(hProcess, (LPVOID)curChunk, sizeof(buffer), oProtect, &oProtect);

            // No bytes read
            if (bytesRead == 0) {
                return NULL;
            }

            DWORD internalAddr = Mem::FindPattern((char*)&buffer, bytesRead, pattern, mask);

            if (internalAddr != NULL) {
                // Calculate real address
                uintptr_t offsetFromBuffer = (uintptr_t)internalAddr - (uintptr_t)&buffer;
                res = (DWORD)(curChunk + offsetFromBuffer);
                res_plus_offset = Mem::RPM<int>(res + offset); //Adding the offset
                return res_plus_offset - (DWORD)Mem::dw_client_address.modBaseAddr + extra; //adding the extra
            }
            else {
                // Next chunk
                curChunk += bytesRead;
            }
        }
        return NULL;
    }

    // Find matching pattern
    DWORD FindPattern(char* base, size_t size, const char* pattern, const char* mask) {
        size_t patternLen = strlen(mask);

        for (DWORD i = 0; i < size - patternLen; i++) {
            bool found = true;

            for (DWORD j = 0; j < patternLen; j++) {

                if (mask[j] != '?' && pattern[j] != *(base + i + j)) {
                    found = false;
                    break;
                }
            }

            if (found) {
                return (DWORD)(base + i);
            }
        }

        return NULL;
    }

    template<typename T> T RPM(SIZE_T address) {
        T buffer;
        ReadProcessMemory(process_handle, (LPCVOID)address, &buffer, sizeof(T), NULL);
        return buffer;
    }

    template<typename T> void WPM(SIZE_T address, T buffer) {
        WriteProcessMemory(process_handle, (LPVOID)address, &buffer, sizeof(buffer), NULL);
    }

}