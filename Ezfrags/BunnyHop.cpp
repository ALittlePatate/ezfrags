#include "Settings.hpp"
#include "MemManager.h"
#include "Signatures.h"
#include "BunnyHop.h"
#include "Signatures.h"

#include <iostream>
#include <Windows.h>

//This function is about 90% decompiled
void bunnyhop_thread() {
	cheat_thread_state::bunnyhop_thread_status = 1;
	while (1) {
		while (!settings::bunnyhop_bool || !Mem::csgo_found || !Mem::client_dll_found) {
			Sleep(5u);
		}

		//Mem::RPM<int>(Mem::client + get_sigs::dwLocalPlayer)
		bool player_alive = true;
		if (player_alive && GetAsyncKeyState(32) < 0)// If we're alive and we're pressing space
		{
			Mem::WPM<int>(Mem::client + Signatures::dwForceJump, 5);// force jump
			Sleep(10u);
			Mem::WPM<int>(Mem::client + Signatures::dwForceJump, 4);// unjump
		}
		Sleep(1u);

		/*
		while ( !bunnyhop_bool || !csgo_module || !client_module_found || !byte_4FBF0C || LocalPlayer_notsure == 1 )
		  Sleep(5u);
		if ( ReadProcessMemory_2(player, v2, v3, v4, v5) && GetAsyncKeyState(32) < 0 )// If we're alive and we're pressing space
		{
		  write_memory((LPVOID)(client + dwForceJump), 5);// force jump
		  Sleep(10u);
		  write_memory((LPVOID)(client + dwForceJump), 4);// unjump
		}
		Sleep(1u);
		*/
	}
}