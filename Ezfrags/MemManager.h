#pragma once
#include <iostream>
#include <thread>
#include <Windows.h>
#include <TlHelp32.h>

namespace Mem {
    static bool csgo_found = false;
    static bool client_dll_found = false;
    static bool engine_dll_found = false;
    static uintptr_t client;
    static uintptr_t engine;
    static DWORD dw_process_id;
    static MODULEENTRY32 dw_client_address;
    static MODULEENTRY32 dw_engine_address;
    static HANDLE process_handle;
    static uint8_t* client_bytes;
    static uint8_t* engine_bytes;

	inline MODULEENTRY32 get_module(const char* modName, DWORD proc_id);
    inline void get_csgo();
    inline void get_client_base_address();
    inline void get_engine_base_address();
    DWORD FindAddress(const wchar_t* moduleName, const char* pattern, const char* mask, const int offset, const int extra);
    DWORD FindPattern(char* base, size_t size, const char* pattern, const char* mask);

    template<typename T> T RPM(SIZE_T address);
    template<typename T> void WPM(SIZE_T address, T buffer);
}
