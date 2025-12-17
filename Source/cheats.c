#include <stdio.h>
#include "cheats.h"
#include <stdbool.h>

bool cheats = false;

// Xavier
void printCheats()
{
    if (cheats == true)
    {
        printf("\n");
        printf("Cheat Menu");
        printf("\n");
        printf("F: Light Up full map");
        printf("\n");
        printf("G: Rest lighting back to normal");
        printf("\n");
        printf("K: Give player the Key");
    }
}