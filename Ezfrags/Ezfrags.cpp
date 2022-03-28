#include <iostream>
#include <Windows.h>

#include "MemManager.cpp"
#include "Signatures.cpp"
#include "ShowFeatures.cpp"
#include "WaitForKeys.cpp"

#include "AimAssist.cpp"
#include "Aimlock.cpp"
#include "BunnyHop.cpp"
#include "GlowESP.cpp"
#include "KillMessage.cpp"
#include "NoFlash.cpp"
#include "Radar.cpp"
#include "Triggerbot.cpp"

#include "Settings.hpp"
#include "Ezfrags.h"

#include "StringObfuscation.hpp"

time_t TimeUpdate;
time_t current_time; // eax

int main()
{
	start_obfuscation();
	current_time = time(0);                     // current time in seconds
	srand((unsigned int)current_time);			// sets the seed for random numbers to the current time
                                                // randomness will be used later for the kill message

	std::cout << console_title << std::endl;
	SetConsoleTitleA("EZfrags CS:GO multihack v9.65 public [www.EZfrags.co.uk]"); //Ezfrag premium ++ spinbout edition
	std::cout << "EZfrags CS:GO multihack v9.65 public [www.EZfrags.co.uk]" << "\n";

	time(&TimeUpdate);
	if (TimeUpdate - 1591304279 > 864000)             // If our version is older than 10 days
	{
		std::cout << '\n' << "!!! WARNING !!!: This version is more than 10 days old.";
		std::cout << '\n' << "You should go and download a new build from www.EZfrags.co.uk" << std::endl;
	}

	std::cout << '\n' << "The hack will start loading once CS:GO is started." << std::endl;

	std::cout << "\n" << "Loading csgo.exe";
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Mem::get_csgo, 0, 0, 0);

	//All this instant thing is just from me, that doesn't figure in the original code
	//So yeah that's to change ig
	bool instant_csgo = true;
	while (!Mem::csgo_found)
	{
		Sleep(250);

		if (Mem::csgo_found)
		{
			break;
		}

		std::cout << ".";

		instant_csgo = false;
	}

	if (instant_csgo) {
		std::cout << "....";
	}

	std::cout << std::endl;

	std::cout << "Loading client.dll";
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Mem::get_client_base_address, 0, 0, 0);

	bool instant_client = true;
	while (!Mem::client_dll_found)
	{
		Sleep(250);

		if (Mem::client_dll_found)
		{
			break;
		}

		std::cout << ".";

		instant_client = false;
	}

	if (instant_client) {
		std::cout << "....";
	}

	std::cout << std::endl;


	std::cout << "Loading engine.dll";
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Mem::get_engine_base_address, 0, 0, 0);

	bool instant_engine = true;
	while (!Mem::engine_dll_found)
	{

		Sleep(250);

		if (Mem::engine_dll_found)
		{
			break;
		}
		std::cout << ".";

		instant_engine = false;
	}

	if (instant_engine) {
		std::cout << "....";
	}

	std::cout << std::endl;

	std::cout << "\n" << "Scanning for offsets...";

	get_sigs::start();

	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)radar_thread, 0, 0, 0);// Stuck
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)aim_assist_thread, 0, 0, 0);//
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)no_flash_thread, 0, 0, 0);// Done !
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)bunnyhop_thread, 0, 0, 0);// Done !
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)aimlock_thread, 0, 0, 0);//
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)glow_esp_thread, 0, 0, 0);//
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)kill_message_thread, 0, 0, 0);//
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)trigger_thread, 0, 0, 0);//
	while (!cheat_thread_state::aim_assist_thread_status
		|| !cheat_thread_state::aimlock_thread_status
		|| !cheat_thread_state::no_flash_thread_status
		|| !cheat_thread_state::glow_esp_thread_status
		|| !cheat_thread_state::radar_thread_status
		|| !cheat_thread_state::bunnyhop_thread_status
		|| !cheat_thread_state::trigger_thread_status
		|| !cheat_thread_state::kill_message_thread_status)
		Sleep(100u);

	settings::glow_esp_bool = 1;
	settings::trigger_mode_switch_1 = 0;
	settings::aimlock_bool = 1;
	settings::radar_bool = 1;
	settings::aim_assist_bool = 1;
	settings::trigger_mode_switch_2 = 0;
	settings::bunnyhop_bool = 1;
	settings::kill_message_bool = 1;
	settings::no_flash_bool = 1;
	update();

	while (WaitForSingleObject(Mem::process_handle, 0)) {
		wait_for_keys();
	}
	CloseHandle(Mem::process_handle);
	exit(0);
}

