#include "Settings.hpp"
#include "MemManager.h"
#include "netvars.h"
#include "Radar.h"

#define BYTE1(Entities)       (*((char *)(&Entities) + 1))

/*
Still a prototype of what it would look like
I don't know where they actually get the Entities_unk variable
Also i don't know anything about byte_4FBF0C, doesn't seem that important
*/

void radar_thread() {
    int Entities[157];

	cheat_thread_state::radar_thread_status = 1;

    return; //don't wanna cause errors
    while (1)
    {
        while (!Mem::csgo_found || !settings::radar_bool || !Mem::client_dll_found) //|| !byte_4FBF0C) Don't know about this byte
            Sleep(5u);

        for (int i = 0; i <= 63 && Mem::csgo_found == 1 && Mem::client_dll_found == 1; i++)//For every player in the map.        //&& byte_4FBF0C == 1; ++i) Same byte as before
        {
            //memcpy(Entities, (char*)&Entities_unk + 628 * i, sizeof(Entities));
            if (BYTE1(Entities[146])
                && LOBYTE(Entities[141])
                && LOBYTE(Entities[78])
                && BYTE1(Entities[118]) != 1
                && BYTE1(Entities[99]) != 1
                //&& Entities[4] != dword_4FBEF0
                && (Mem::RPM<unsigned __int8>(Entities[120] + Netvars::m_bSpotted) != 1)) // If ennemy is not spotted
                //&& (unsigned __int8)RPM((LPCVOID)(Entities[120] + m_bSpotted)) != 1)
            {
                //Mem::WPM_test((LPVOID)(Entities[120] + Netvars::m_bSpotted), 1);
                //WPM((LPVOID)(Entities[120] + m_bSpotted), 1);// Set entity is spotted
            }
        }
        Sleep(1u);
    }

}