#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "map.h"
#include "menu.h"
#include "player.h"
#include "box.h"
#include "doorAndKeys.h"
#include "torch.h"
#include "cheats.h"

// Defining the Map & Tiles

// #define MAP_ROWS 18
// #define MAP_COLS 18

// #define TILE_WALL 'W'
// #define TILE_FLOORWHITE 'Z'
// #define TILE_FLOORBLACK 'X'
// #define TILE_TRAP 'T'
// #define TILE_TORCH 'L'
// #define TILE_DOOR 'D'
// #define TILE_KEY 'K'
// #define TILE_PRESSUREPLATE 'P'


//bool getKey = false;



// Player Structure:
// struct Player {
//     int position_x;
//     int position_y;
// };

// struct Box {
//     int position_x;
//     int position_y;
//     bool beingGrabbed;
//     int direction; // 0 = left | 1 = up | 2 = right | 3 down
// };

// struct inventory{
//     char name[20];
//     int quantity;
// };

// Map and Player Global Variables

// char map[MAP_ROWS][MAP_COLS] = {
//     {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
//     {'W', 'K', 'L', 'Z', 'X', 'W', 'X', 'Z', 'L', 'L', 'X', 'Z', 'W', 'Z', 'X', 'L', 'D', 'W'}, 
//     {'W', 'L', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'L', 'W'},
//     {'W', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'W'},
//     {'W', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'W'},
//     {'W', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'W'},
//     {'W', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'W'},
//     {'W', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'W'},
//     {'W', 'X', 'Z', 'X', 'Z', 'Z', 'Z', 'T', 'Z', 'X', 'Z', 'L', 'W', 'X', 'Z', 'X', 'Z', 'W'},
//     {'W', 'L', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'L', 'W', 'Z', 'X', 'Z', 'L', 'W'},
//     {'W', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'W'},
//     {'W', 'Z', 'X', 'Z', 'X', 'W', 'X', 'P', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'W'},
//     {'W', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'T', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'W'},
//     {'W', 'Z', 'X', 'Z', 'X', 'W', 'X', 'T', 'T', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'W'},
//     {'W', 'X', 'Z', 'X', 'Z', 'W', 'T', 'X', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'W'},
//     {'W', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'L', 'W'},
//     {'W', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'L', 'L', 'Z', 'X', 'Z', 'X', 'Z', 'L', 'Z', 'W'},
//     {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},

// };

//struct Player player = {16, 1};
//struct Box box1 = {15, 2, false, 0};
// struct inventory inventory[3]={};




int main(){ 
    printf("\n\n\n\n");
    printMenu();
    return 0;
}

// TODO:
/*
    - Don't forget to reset the box positions.
    - Don't forget to check if the box is colliding against a wall. IF it is, we CANNOT move the player.
*/


// function initialization

//Print menu moved to menu.c



//choose player name moved to player.c

//startgame moved to menu.c

//print map moved to map.c



//read user input in player.c

//is tile walkable in player.c

//player movement in player.c

//step counter moved to player.c

//check interaction in player.c
    

//Torch dim moved to torch.c


//torch interact moved to torch.c

//Player death moved to player.c


//Pedro. End level moved to menu.c


//Pause menu moved to menu.c


//Collect key moved to doorsAndKeys.c

//Print inventory moved to player.c



//Death counter moved to player.c

//Torch display moved to torch.c



//Xavier Level select moved to menu.c


//Pedro Sanity -> moved to player.c

//debugstats moved to map.c






//moveBox moved to box.c


//Move grabBox  moved to box.c
