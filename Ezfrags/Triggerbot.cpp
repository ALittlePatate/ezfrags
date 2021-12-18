#include "Settings.hpp"
#include "Triggerbot.h"

void trigger_thread() {
	cheat_thread_state::trigger_thread_status = 1;
}