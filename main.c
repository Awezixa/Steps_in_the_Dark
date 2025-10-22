#include <stdio.h>
#include <stdbool.h>


// Defining the Map & Tiles

#define MAP_ROWS 18
#define MAP_COLS 18

#define TILE_WALL 'W'
#define TILE_FLOORWHITE 'Z'
#define TILE_FLOORBLACK 'X'
#define TILE_TRAP 'T'

// We'll have the Wall; Two Tiles (to make it a black and white chess pattern) and the trapped plates.

// Player Structure:
struct Player {
    int position_x;
    int position_y;
};

// Map and Player Global Variables

char map[MAP_ROWS][MAP_COLS] = {
    {'W', }
};