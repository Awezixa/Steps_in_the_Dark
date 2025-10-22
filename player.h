#ifndef PLAYER_H
#define PLAYER_H

struct Player {
    int position_x;
    int position_y;
};

void PlayerFunction();
void movePlayer(char dir);
void player_collect_items(void);
int player_get_row(void);
int player_get_col(void);

#endif PLAYER_H