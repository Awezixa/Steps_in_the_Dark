#include <stdio.h>
#include "player.h"
#include "map.h"
#include "box.h"
#include "menu.h"
#include "../Utils/sdl_utils.h"

bool activated = false;

struct Box box1 = {8, 10, false, 0};
static Sound blockedDoorUnlocked;

void boxPositioning(){
if (isLevelOne == true){
box1.position_x = 8;
box1.position_y = 10;}

if (isLevelTwo == true){
box1.position_x = 4;
box1.position_y = 4;}

if (isLevelThree == true){
box1.position_x = 8;
box1.position_y = 10;}

if (isLevelFour == true){
box1.position_x = 3;
box1.position_y = 2;   
}
}



void moveBox()
{
    if (!box1.beingGrabbed)
        return;

    // 0 = left | 1 = up | 2 = right | 3 down
    if (box1.beingGrabbed){
    if (box1.direction == 1)
    {

        box1.position_x = player.position_x + 1;
        box1.position_y = player.position_y;
    }
    else if (box1.direction == 3)
    {

        box1.position_x = player.position_x - 1;
        box1.position_y = player.position_y;
    }
    else if (box1.direction == 0)
    {

        box1.position_x = player.position_x;
        box1.position_y = player.position_y - 1;
    }
    else
    {
        // is 2 here. everything else failed.
        box1.position_x = player.position_x;
        box1.position_y = player.position_y + 1;
    }
    }
}

void grabBox()
{
    // We need to check if the player is close to the box.
    if (box1.beingGrabbed)
        box1.beingGrabbed = false;
    
    // 0 = left | 1 = up | 2 = right | 3 down
    if (player.position_x + 1 == box1.position_x && player.position_y == box1.position_y)
    {
        box1.direction = 1;
        box1.beingGrabbed = true;
    }
    else if (player.position_x - 1 == box1.position_x && player.position_y == box1.position_y)
    {
        box1.direction = 3;
        box1.beingGrabbed = true;
    }
    else if (player.position_y - 1 < MAP_ROWS && player.position_x == box1.position_x && player.position_y - 1 == box1.position_y)
    {
        box1.direction = 0;
        box1.beingGrabbed = true;
    }
    else if (player.position_y + 1 < MAP_ROWS && player.position_x == box1.position_x && player.position_y + 1 == box1.position_y)
    {
        box1.direction = 2;
        box1.beingGrabbed = true;
    }
}



void plateActivated()
{
    init_sound("Assets/Sounds/blockedDoorUnlocked.wav", &blockedDoorUnlocked);

    for (int x = 0; x < MAP_ROWS; x++)
    {
        for (int y = 0; y < MAP_COLS; y++)
        {
            if (map[x][y] == 'H' && map[box1.position_x][box1.position_y] == 'P')
            {
                activated = true;
                playSound(&blockedDoorUnlocked);
                (map[x][y] = 'Z');
            }
        }
    }
}

int box_get_row(void)
{
    return box1.position_x;
}

int box_get_col(void)
{
    return box1.position_y;
}