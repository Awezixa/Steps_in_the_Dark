#include <stdio.h>
#include <stdbool.h>
#include "projectile.h"
#include "box.h"
#include "player.h"
#include "map.h"

struct projectile WIP = {6, 10, false, 0, 15};
bool thrown = false;
/*
features:

- thrown 3 tiles in direction facing/ moving towards
- star shaped radius of 3 tiles. reduce after 3 steps to 1 tile, after 3 more steps extinguish
- if its wall will stop behind/ next to the wall
- limited 1 per level
*/


//Xavier
void collectProjectile(){
   if (WIP.collected)
        WIP.collected = false;
    else {

        // 0 = left | 1 = up | 2 = right | 3 down
        if (player.position_x + 1 == WIP.position_x && player.position_y == WIP.position_y) {
                    WIP.direction = 1;
                    WIP.collected = true;
                    map[WIP.position_x][WIP.position_y] = 'Z';
            } 
            else if (player.position_x - 1 == WIP.position_x && player.position_y == WIP.position_y) {
               
                    WIP.direction = 3;
                    WIP.collected = true;
                    map[WIP.position_x][WIP.position_y] = 'Z';   
            } 
            else if (player.position_y - 1 < MAP_ROWS && player.position_x == WIP.position_x && player.position_y - 1 == WIP.position_y) {
                    WIP.direction = 0;
                    WIP.collected = true;
                    map[WIP.position_x][WIP.position_y] = 'Z';
            } 
            else if (player.position_y + 1 < MAP_ROWS && player.position_x == WIP.position_x && player.position_y + 1 == WIP.position_y) {
                WIP.direction = 2;
                WIP.collected = true;
                map[WIP.position_x][WIP.position_y] = 'Z';
                
            }
    } 
}




//Xavier
void throwProjectile(){
    // 0 = left | 1 = up | 2 = right | 3 down
    switch (WIP.direction)
    {
    case 0:
        thrown = true;
        WIP.position_x = player.position_x;
        WIP.position_y = player.position_y;
        WIP.position_x = WIP.position_x;
        WIP.position_y = WIP.position_y - 3;
        WIP.collected = false;
        break;
    case 1:
        thrown = true;
        WIP.position_x = player.position_x + 3;
        WIP.position_y = player.position_y;
        WIP.position_x = WIP.position_x + 3;
        WIP.position_y = WIP.position_y;
        WIP.collected = false;
        break;
    case 2:
        thrown = true;
        WIP.position_x = player.position_x;
        WIP.position_y = player.position_y + 3;
        WIP.position_x = WIP.position_x;
        WIP.position_y = WIP.position_y + 3;
        WIP.collected = false;
        break;
    case 3:
        thrown = true;
        WIP.position_x = player.position_x - 3;
        WIP.position_y = player.position_y;
        WIP.position_x = WIP.position_x - 3;
        WIP.position_y = WIP.position_y;
        WIP.collected = false;
        break;
    
    default:
        break;
}
}




void WIPDisplay() {
    printf("\n");
    printf("WIP Meter: ");
    if(WIP.projectileLevel == 15){
        printf("[🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩]");
    }
    if(WIP.projectileLevel == 14){
        printf("[🟩🟩🟩🟩🟩🟩🟩🟩🟩⬛]");
    }
    if(WIP.projectileLevel == 13){
        printf("[🟩🟩🟩🟩🟩🟩🟩🟩⬛⬛]");
    }
    if(WIP.projectileLevel == 12){
        printf("[🟩🟩🟩🟩🟩🟩🟩⬛⬛⬛]");
    }
    if(WIP.projectileLevel == 11){
        printf("[🟩🟩🟩🟩🟩🟩⬛⬛⬛⬛]");
    }
    if(WIP.projectileLevel == 10){
        printf("[🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛]");
    }
    if(WIP.projectileLevel == 9){
        printf("[🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛]");
    }
    if(WIP.projectileLevel == 8){
        printf("[🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛]");
    }
    if(WIP.projectileLevel == 7){
        printf("[🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛]");
    }
    if(WIP.projectileLevel == 6){
        printf("[🟥⬛⬛⬛⬛⬛⬛⬛⬛⬛]");
    }
    if(WIP.projectileLevel < 6){
        printf("[⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛]");
    }
    
}

void projDim(){
    WIP.projectileLevel--;
    if (WIP.projectileLevel == 0)
    {
        printf("Projectile ran out\n");
    }
     
}