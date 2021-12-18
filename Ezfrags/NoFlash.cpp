#include "Settings.hpp"
#include "MemManager.h"
#include "Signatures.h"
#include "Get.h"
#include "NoFlash.h"

//This function has been 100% decompiled !
//Not actually, still remains :
/*
 while ( !csgo_module || !client_module_found || !byte_4FBF0C )
      Sleep(5u);
*/
//But i simplified it here
//No idea what byte_4FBF0C is, seems used in the GetEngine function of Ezfrags, it's yet to be decompiled

void no_flash_thread() {
	cheat_thread_state::no_flash_thread_status = 1;

    while (1)
    {
        while (!Mem::csgo_found || !Mem::client_dll_found)
            Sleep(5u);

        if (settings::no_flash_bool)
        {
            /*
            if (ReadProcessMemory_0((char*)player + m_flFlashMaxAlpha) > 0.0)// If flash value is > 0
                WriteProcessMemory_0((char*)player + m_flFlashMaxAlpha, (float)0.0);// We put anti flash
            */
            if (Mem::RPM<float>(Get::LocalPlayer() + Netvars::m_flFlashMaxAlpha) > 0.0f)
                Mem::WPM<float>(Get::LocalPlayer() + Netvars::m_flFlashMaxAlpha, 0.0f);
        }

        /*
        else if (0.0 == ReadProcessMemory_0((char*)player + m_flFlashMaxAlpha))// We need to reset the flash value to 255
        {
            WriteProcessMemory_0((char*)player + m_flFlashMaxAlpha, (float)255.0);// Yop
        }
        */

        else if (Mem::RPM<float>(Get::LocalPlayer() + Netvars::m_flFlashMaxAlpha) == 0.0f) {
            Mem::WPM<float>(Get::LocalPlayer() + Netvars::m_flFlashMaxAlpha, 255.0f);
        }

        //std::cout << Mem::RPM<float>(Signatures::dwLocalPlayer + Netvars::m_flFlashMaxAlpha) << std::endl;
        //Sleep(300);
        Sleep(1u);
    }
}