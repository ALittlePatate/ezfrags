#pragma once

namespace settings {
	bool glow_esp_bool = 1;
	int trigger_mode_switch_1 = 0;
	int trigger_mode_switch_2 = 0;
	int trigger_delay = 30;
	bool aimlock_bool = 1;
	int aimlock_bone = 6; //8 : chest,   6 : head
	bool radar_bool = 1;
	bool aim_assist_bool = 1;
	int aim_assist_bone = 6; //8 : chest,   6 : head
	float aim_fov = 25.0;
	bool bunnyhop_bool = 1;
	bool kill_message_bool = 1;
	bool no_flash_bool = 1;
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