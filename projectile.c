#include <stdio.h>
#include "projectile.h"
#include "box.h"
#include "player.h"
#include "map.h"

struct projectile WIP = {8, 10, false, 0, 15};

/*
features:

- thrown 3 tiles in direction facing/ moving towards
- star shaped radius of 3 tiles. reduce after 3 steps to 1 tile, after 3 more steps extinguish
- if its wall will stop behind/ next to the wall
- limited 1 per level
*/


// void grabBox(){
//     // We need to check if the player is close to the box.
//     if (box1.beingGrabbed)
//         box1.beingGrabbed = false;
//     else {

//         // 0 = left | 1 = up | 2 = right | 3 down
//         if (player.position_x + 1 == box1.position_x && player.position_y == box1.position_y) {
               
//                     box1.direction = 1;
//                     box1.beingGrabbed = true;
                
//             } else if (player.position_x - 1 == box1.position_x && player.position_y == box1.position_y) {
               
//                     box1.direction = 3;
//                     box1.beingGrabbed = true;
                
//             } else if (player.position_y - 1 < MAP_ROWS && player.position_x == box1.position_x && player.position_y - 1 == box1.position_y) {
              
//                     box1.direction = 0;
//                     box1.beingGrabbed = true;
                
//             } else if (player.position_y + 1 < MAP_ROWS && player.position_x == box1.position_x && player.position_y + 1 == box1.position_y) {
               

//                 box1.direction = 2;
//                 box1.beingGrabbed = true;
                
//             }
//     }

// }


void collectProjectile(){
   if (WIP.collected)
        WIP.collected = false;
    else {

        // 0 = left | 1 = up | 2 = right | 3 down
        if (player.position_x + 1 == WIP.position_x && player.position_y == WIP.position_y) {
               
                    
                    WIP.collected = true;
                
            } else if (player.position_x - 1 == WIP.position_x && player.position_y == WIP.position_y) {
               
                    box1.direction = 3;
                    WIP.collected = true;
                
            } else if (player.position_y - 1 < MAP_ROWS && player.position_x == WIP.position_x && player.position_y - 1 == WIP.position_y) {
              
                    box1.direction = 0;
                    WIP.collected = true;
                
            } else if (player.position_y + 1 < MAP_ROWS && player.position_x == WIP.position_x && player.position_y + 1 == WIP.position_y) {
               

                box1.direction = 2;
                WIP.collected = true;
                
            }
    } 
}

void throwProjectile(){

}
