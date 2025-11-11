#ifndef BOX_H
#define BOX_H
#include <stdbool.h>

struct Box {
    int position_x;
    int position_y;
    bool beingGrabbed;
    int direction; // 0 = left | 1 = up | 2 = right | 3 down
};

extern struct Box box1;

void moveBox();
void grabBox();
void pressurePlate();
void plateActivated();



#endif