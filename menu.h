#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

extern bool isLevelFour;
extern bool isLevelThree;
extern bool isLevelTwo;
extern bool isLevelOne;

void printMenu();
void startGame();
void pauseGame();
void levelSelect();
void endLevel();




#endif  