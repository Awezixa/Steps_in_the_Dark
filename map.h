#ifndef MAP_H
#define MAP_H

#include <stdbool.h>

#define MAP_ROWS 12
#define MAP_COLS 12

#define TILE_WALL 'W'
#define TILE_FLOOR 'F'
#define TILE_POTION 'P'

void printMap();
bool map_is_walkable(int row, int col);
char map_get_tile(int row, int col);
void map_set_tile(int row, int col, char tile);

#endif MAP_H