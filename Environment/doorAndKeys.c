#include <stdbool.h>
#include <stdio.h>
#include "map.h"
#include "player.h"

extern bool getKey = false;

void collectKey() {
    if(map[player.position_x][player.position_y] == 'K') {
        getKey = true;
        map[player.position_x][player.position_y] = 'X';
 
    }
}

void printInventory(){
    printf("\t\tInventory:");
    if (getKey == true)
    {
        printf("🗝️");
    }
    
}