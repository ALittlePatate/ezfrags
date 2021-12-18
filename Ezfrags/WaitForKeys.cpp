#include <iostream>
#include <Windows.h>
#include "WaitForKeys.h"
#include "ShowFeatures.h"
#include "Settings.hpp"

void wait_for_keys()
{
    if (GetAsyncKeyState(16) >= 0 && GetAsyncKeyState(117) < 0)// 
                                                  // F6 - cycle through triggerbot modes (autofire, hold key, disabled - default)
                                                  // SHIFT+F6 - cycle through triggerbot delays (10, 30 - default, 50, 80, 110, 140)
    {
        while (GetAsyncKeyState(16) >= 0 && GetAsyncKeyState(117) < 0)
            Sleep(75u);
        if (settings::trigger_mode_switch_2 && settings::trigger_mode_switch_1 != 1)// mode switching (f6)
        {
            settings::trigger_mode_switch_2 = 0;
            settings::trigger_mode_switch_1 = 1;
        }
        else if (settings::trigger_mode_switch_2 != 1 && settings::trigger_mode_switch_1)
        {
            settings::trigger_mode_switch_2 = 0;
            settings::trigger_mode_switch_1 = 0;
        }
        else if (settings::trigger_mode_switch_2 != 1 && settings::trigger_mode_switch_1 != 1)
        {
            settings::trigger_mode_switch_2 = 1;
            settings::trigger_mode_switch_1 = 0;
        }
        update();
    }
    if (GetAsyncKeyState(16) < 0 && GetAsyncKeyState(117) < 0)
    {
        while (GetAsyncKeyState(16) < 0 && GetAsyncKeyState(117) < 0)
            Sleep(75u);
        if (settings::trigger_delay == 140)                 // Delay switching (shift + f6)
        {
            settings::trigger_delay = 10;
        }
        else if (settings::trigger_delay == 10 || settings::trigger_delay == 30)
        {
            settings::trigger_delay += 20;
        }
        else
        {
            settings::trigger_delay += 30;
        }
        update();
    }
    if (GetAsyncKeyState(16) >= 0 && GetAsyncKeyState(118) < 0)// 
                                                  // F7 - toggle aim assist
                                                  // SHIFT+F7 - toggle aim assist mode (rage/legit)
    {
        while (GetAsyncKeyState(16) >= 0 && GetAsyncKeyState(118) < 0)
            Sleep(75u);
        settings::aim_assist_bool = settings::aim_assist_bool == 0;
        update();
    }
    if (GetAsyncKeyState(16) < 0 && GetAsyncKeyState(118) < 0)
    {
        while (GetAsyncKeyState(16) < 0 && GetAsyncKeyState(118) < 0)
            Sleep(75u);
        if (settings::aim_assist_bone == 8)                 // mode switching (shift + f7)
        {
            settings::aim_assist_bone = 6;                      // switching between bones, head and chest
            settings::aim_fov = 25.0;                           // switching between 25.0 and 100.0 fov
        }
        else
        {
            settings::aim_assist_bone = 8;
            settings::aim_fov = 100.0;
        }
        update();
    }
    if (GetAsyncKeyState(16) >= 0 && GetAsyncKeyState(119) < 0)// 
                                                  // F8 - toggle aimlock 119
                                                  // SHIFT+F8 - toggle aimlock target (head/chest)
    {
        while (GetAsyncKeyState(16) >= 0 && GetAsyncKeyState(119) < 0)
            Sleep(75u);
        settings::aimlock_bool = settings::aimlock_bool == 0;
        update();
    }
    if (GetAsyncKeyState(16) < 0 && GetAsyncKeyState(119) < 0)
    {
        while (GetAsyncKeyState(16) < 0 && GetAsyncKeyState(119) < 0)
            Sleep(75u);
        if (settings::aimlock_bone == 8)                    // switching between bones, head and chest
            settings::aimlock_bone = 6;
        else
            settings::aimlock_bone = 8;
        update();
    }
    if (GetAsyncKeyState(16) >= 0 && GetAsyncKeyState(120) < 0)// 
                                                  // F9 - toggle GlowESP 120
                                                  // SHIFT+F9 - toggle radar hack
    {
        while (GetAsyncKeyState(16) >= 0 && GetAsyncKeyState(120) < 0)
            Sleep(75u);
        settings::glow_esp_bool = settings::glow_esp_bool == 0;
        update();
    }
    if (GetAsyncKeyState(16) < 0 && GetAsyncKeyState(120) < 0)
    {
        while (GetAsyncKeyState(16) < 0 && GetAsyncKeyState(120) < 0)
            Sleep(75u);
        settings::radar_bool = settings::radar_bool == 0;
        update();
    }
    if (GetAsyncKeyState(121) < 0)              // 
                                                  // F10 - toggle no flash hack
    {
        while (GetAsyncKeyState(121) < 0)
            Sleep(75u);
        settings::no_flash_bool = settings::no_flash_bool == 0;
        update();
    }
    if (GetAsyncKeyState(16) >= 0 && GetAsyncKeyState(122) < 0)// 
                                                  // F11 - toggle bunny hop 122
                                                  // SHIFT+F11 - toggle kill message
    {
        while (GetAsyncKeyState(16) >= 0 && GetAsyncKeyState(122) < 0)
            Sleep(75u);
        settings::bunnyhop_bool = settings::bunnyhop_bool == 0;
        update();
    }
    if (GetAsyncKeyState(16) < 0 && GetAsyncKeyState(122) < 0)
    {
        while (GetAsyncKeyState(16) < 0 && GetAsyncKeyState(122) < 0)
            Sleep(75u);
        settings::kill_message_bool = settings::kill_message_bool == 0;
        update();
    }
    Sleep(25u);
}