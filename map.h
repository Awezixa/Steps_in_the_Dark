#ifndef MAP_H
#define MAP_H

#include <stdbool.h>

#define MAP_ROWS 18
#define MAP_COLS 18

#define TILE_WALL 'W'
#define TILE_FLOOR 'Z'
#define TILE_TRAP 'T'
#define TILE_TORCH 'L'
#define TILE_DOOR 'D'
#define TILE_KEY 'K'
#define TILE_PRESSUREPLATE 'P'
#define TILE_LOCKEDDOOR 'H'
#define TILE_MIST 'M'


extern char map[MAP_ROWS][MAP_COLS];

extern bool fullBrightOn;

void printMap();
void printDebugStats();
void cheatFullBright();
void trapPlate();
void loadMap();
bool map_in_bounds(int row, int col);
char map_get_tile(int row, int col);
char map_handlechar(char c, int x, int y);
char readMap();


#endif 