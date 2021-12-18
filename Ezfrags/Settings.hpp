#pragma once

namespace settings {
	bool glow_esp_bool;
	int trigger_mode_switch_1;
	int trigger_mode_switch_2;
	int trigger_delay = 30;
	bool aimlock_bool;
	int aimlock_bone = 6; //8 : chest,   6 : head
	bool radar_bool;
	bool aim_assist_bool;
	int aim_assist_bone = 6; //8 : chest,   6 : head
	float aim_fov = 25.0;
	bool bunnyhop_bool;
	bool kill_message_bool;
	bool no_flash_bool;
};

namespace cheat_thread_state {
	bool aim_assist_thread_status = 0;
	bool aimlock_thread_status = 0;
	bool no_flash_thread_status = 0;
	bool glow_esp_thread_status = 0;
	bool radar_thread_status = 0;
	bool bunnyhop_thread_status = 0;
	bool trigger_thread_status = 0;
	bool kill_message_thread_status = 0;
}