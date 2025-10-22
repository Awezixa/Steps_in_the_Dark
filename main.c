#include<stdbool.h>
#include <stdio.h>





























































// Functions to be implemented
void printMenu(void);
void printMap(void);
void printPlayerStats(void);

char readUserInput(void);
void movePlayer(char dir);

bool isTileWalkable(char t);
int inBounds(int y, int x);

void collectItems();