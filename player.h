#ifndef PLAYER_H
#define PLAYER_H
#include <stdbool.h>

int stepCount = 0;

struct Player {
    int position_x;
    int position_y;
};

void PlayerFunction();
void movePlayer(char dir);
void playerCollectItems(void);
void stepCounter();
char readUserInput();
void playerInventory();
bool isTileWalkable(char t);
void playerDeath();
void playerDeathAnim();
void checkInteraction();
void playerDeathCounter();
void choosePlayerName();


#endif 