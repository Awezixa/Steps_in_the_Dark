#ifndef TORCH_H
#define TORCH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TORCH_SYMBOL 'L'
#define TORCH_LIGHT_RADIUS 2

void placeTorch(int player_x, int player_y, char map[][20], int rows, int cols);
bool isTorchAt(int player_x, int player_y);
char getTorchSymbol(int player_x, int player_y);
void TorchLight(int player_x, int player_y, char map[][20], int rows, int cols);
void torchInteract();

#endif TORCH_H