#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <stdbool.h>

typedef enum {
    INITIAL_STATE,
    MAIN_MENU,
    LEVEL_SELECT,
    INGAME,
    FINISHED,
    PAUSED
} GameState;

GameState gameState();
void setGameState(GameState newState);

#endif /* GAMESTATE_H */