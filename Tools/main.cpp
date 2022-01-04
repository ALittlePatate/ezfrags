
#include <iostream>
#include <defs.h>

void Decrypt(int a1, int size)
{
    unsigned int i; // [esp+10h] [ebp-4h]

    for (i = 0; i <= (size - 2); ++i)
        *(char*)(a1 + i) ^= (char)i + 3;
    *(char*)(a1 + (size - 1)) = 0;
}


int main()
{
    char string[] = "Pgdhiagm+jb|/";

    Decrypt((int)string, sizeof(string));

    std::cout << string << std::endl;

    return 0;
}
