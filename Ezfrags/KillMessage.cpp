#include "Settings.hpp"
#include "KillMessage.h"

void kill_message_thread() {
	cheat_thread_state::kill_message_thread_status = 1;
}