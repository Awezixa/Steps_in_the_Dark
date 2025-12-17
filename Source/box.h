#ifndef BOX_H
#define BOX_H
#include <stdbool.h>

struct Box {
    int position_x;
    int position_y;
    bool beingGrabbed;
    int direction; // 0 = left | 1 = up | 2 = right | 3 down
};

extern bool activated;
extern struct Box box1;

void moveBox();
void grabBox();
void plateActivated();
int box_get_row(void);
int box_get_col(void);
void boxPositioning(void);



#endif