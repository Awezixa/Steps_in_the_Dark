#ifndef MAP_H
#define MAP_H

#include <stdbool.h>

#define MAP_ROWS 18
#define MAP_COLS 18

#define TILE_WALL 'W'
#define TILE_FLOORWHITE 'Z'
#define TILE_FLOORBLACK 'X'
#define TILE_TRAP 'T'
#define TILE_TORCH 'L'

void printMap();


#endif 