# Ezfrags
Ezfrags was the first cheat of a lot of people, and probably their last. This cheat is so popular that it became a meme in the CS:GO community.

# Why ?
I wanted to start this project because a lot of people are not sure if Ezfrags is a virus, if it's detected etc.. Also because the updates are slow to arrive. And obviously because i couldn't resist to make the code of this masterpiece public.
The point is that we can update the cheat, make it undetected, paste it, or just play with a clean version. It's also a training for me who'se learning reverse engineering.

# How ?
I'm currently using IDA 7.5 to decompile this cheat, [the database is avalaible in the repo](https://github.com/ALittlePatate/ezfrags/blob/master/Reversing/ezfrags.exe.idb).
Then you just have to read the code, try to understand and with some time you'll get there.
The version of Ezfrags i'm using here is the v9.65, from 05/06/2020. We don't need to use newer version as they just patch the signatures/structs.
I'm trying to replicate the function as close as they were written but a lot of them are very hard to understand (especially for a begginer like me).
Also the strings are obfuscated but idk how, i know where, but not how.
All the memory related things aren't decompiled yet so i'm using some pasted stuff for the Netvars/Signatures dump.

# Decompilation state :
* ### UI : 100%
* ## Cheats
  * ### [Triggerbot](https://github.com/ALittlePatate/ezfrags/blob/master/Ezfrags/Triggerbot.cpp) : 0%
  * ### [AimAssist](https://gith](https://github.com/ALittlePatate/ezfrags/blob/master/Ezfrags/Aimlock.cpp)ub.com/ALittlePatate/ezfrags/blob/master/Ezfrags/AimAssist.cpp) : 0%
  * ### [Aimlock](https://github.com/ALittlePatate/ezfrags/blob/master/Ezfrags/Aimlock.cpp) : 0%
  * ### [GlowESP](https://github.com/ALittlePatate/ezfrags/blob/master/Ezfrags/GlowESP.cpp) : ~10-20% (see the IDA database)
  * ### [Radar](https://github.com/ALittlePatate/ezfrags/blob/master/Ezfrags/Radar.cpp) : ~60% (see the IDA database)
  * ### [Noflash](https://github.com/ALittlePatate/ezfrags/blob/master/Ezfrags/NoFlash.cpp) : 99% (missing 1 single variable)
  * ### [Bhop](https://github.com/ALittlePatate/ezfrags/blob/master/Ezfrags/BunnyHop.cpp) : 99% (missing 1 single variable)
  * ### [KillMessage](https://github.com/ALittlePatate/ezfrags/blob/master/Ezfrags/KillMessage.cpp) : 0%
* ### [Memory Management](https://github.com/ALittlePatate/ezfrags/blob/master/Ezfrags/MemManager.cpp) : 2%

# The tools
I provided in the [Tools/ folder](https://github.com/ALittlePatate/ezfrags/tree/master/Tools) all the tools i'm using for this project.

## Contact

You can add me on discord at patate#1252

## Contributing

Note: before contrubuting please make sure that your code is as close as the IDA database as you can, also try to stick to the general structure of the project.
Open an [issue](https://github.com/ALittlePatate/ezfrags/issues/new) or make a [pull request](https://github.com/ALittlePatate/ezfrags/pulls), i'll be glad to improve my project with you !
