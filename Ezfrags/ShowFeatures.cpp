#include <iostream>
#include <Windows.h>
#include "ShowFeatures.h"
#include "Settings.hpp"

time_t Time;

void update() {
	system("cls");

	std::cout << "EZfrags CS:GO multihack v9.65 public [www.EZfrags.co.uk]" << "\n";

	time(&Time);
	if (Time - 1591304279 > 864000)             // If our version is older than 10 days
	{
		std::cout << '\n' << "!!! WARNING !!!: This version is more than 10 days old.";
		std::cout << '\n' << "You should go and download a new build from www.EZfrags.co.uk" << std::endl;
	}

	std::cout << '\n' << "The hack has been loaded. Have fun!" << std::endl;

	std::cout << "\n" << "TRIGGERBOT ";
	if (settings::trigger_mode_switch_2 && settings::trigger_mode_switch_1 != 1)
	{
		std::cout << "AUTO";
	}
	else if (settings::trigger_mode_switch_2 != 1 && settings::trigger_mode_switch_1)
	{
		std::cout << "HOLD";
	}
	else if (settings::trigger_mode_switch_2 != 1 && settings::trigger_mode_switch_1 != 1)
	{
		std::cout << "OFF";
	}

	std::cout << " @ " << settings::trigger_delay << " MS";

	std::cout << std::endl;

	std::cout << "AIM ASSIST " << settings::aim_assist_bool << " @ ";
	if (settings::aim_assist_bone == 8) {
		std::cout << "CHEST" << std::endl;
	}
	else {
		std::cout << "HEAD" << std::endl;
	}

	std::cout << "AIMLOCK " << settings::aimlock_bool << " @ ";
	if (settings::aimlock_bone == 8) {
		std::cout << "CHEST" << std::endl;
	}
	else {
		std::cout << "HEAD" << std::endl;
	}

	std::cout << "GLOW ESP " << settings::glow_esp_bool << std::endl;

	std::cout << "RADAR HACK " << settings::radar_bool << std::endl;

	std::cout << "NO FLASH HACK " << settings::no_flash_bool << std::endl;

	std::cout << "BUNNY HOP " << settings::bunnyhop_bool << std::endl;

	std::cout << "KILL MESSAGE " << settings::kill_message_bool;
}