#include "gamestate.h"

GameState current_game_state = INITIAL_STATE;

GameState gameState() {
    return current_game_state;
}

void setGameState(GameState newState) {
    current_game_state = newState;
}