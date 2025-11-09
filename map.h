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
#define TILE_DOOR 'D'
#define TILE_KEY 'K'

extern char map[MAP_ROWS][MAP_COLS];

void printMap();
void printDebugStats();

#endif 