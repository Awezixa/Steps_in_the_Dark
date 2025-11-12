#ifndef PLAYER_H
#define PLAYER_H
#include <stdbool.h>

extern int stepCount;
extern int deathCounter;
extern char playerName[1000];

struct Player {
    int position_x;
    int position_y;
};

struct inventoryItems{
    char name[20];
    int quantity;
};

extern struct inventoryItems inventory[3];
extern struct Player player;

void PlayerFunction();
void movePlayer(char dir);
void playerCollectItems(void);
void stepCounter();
char readUserInput();
void printInventory();
bool isTileWalkable(char t);
void playerDeath();
void checkInteraction();
void playerDeathCounter();
void choosePlayerName();
void sanityDisplay();

void printInventory();
void openInventory();
void closeInventory();


#endif 