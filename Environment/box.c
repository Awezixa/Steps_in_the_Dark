#include <stdio.h>
#include "./player.h"
#include "./map.h"

box1 = {15, 2, false, 0};

void moveBox()
{
    if (!box1.beingGrabbed) return;

    printf("time to move box\n");
    // 0 = left | 1 = up | 2 = right | 3 down

    if (box1.direction == 1 ) {
            box1.position_x= player.position_x + 1;
            box1.position_y = player.position_y;
    }else if (box1.direction == 3 ) {
            box1.position_x = player.position_x - 1;
            box1.position_y = player.position_y;
    }else if (box1.direction == 0 ) {
            box1.position_x = player.position_x;
            box1.position_y = player.position_y - 1;
    }else {
        // is 2 here. everything else failed.
                    box1.position_x = player.position_x;
            box1.position_y = player.position_y - 1;
    }

}

void grabBox(){
    // We need to check if the player is close to the box.
    if (box1.beingGrabbed)
        box1.beingGrabbed = false;
    else {

        // 0 = left | 1 = up | 2 = right | 3 down
        if (player.position_x + 1 == box1.position_x && player.position_y == box1.position_y) {
                box1.direction = 1;
                box1.beingGrabbed = true;
            } else if (player.position_x - 1 == box1.position_x && player.position_y == box1.position_y) {
                box1.direction = 3;
                box1.beingGrabbed = true;
            } else if (player.position_y - 1 < MAP_ROWS && player.position_x == box1.position_x && player.position_y - 1 == box1.position_y) {
                box1.direction = 0;
                box1.beingGrabbed = true;
            } else if (player.position_y + 1 < MAP_ROWS && player.position_x == box1.position_x && player.position_x + 1 == box1.position_y) {
                box1.direction = 2;
                box1.beingGrabbed = true;
            }
    }

}