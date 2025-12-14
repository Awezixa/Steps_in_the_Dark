#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <stdbool.h>

struct projectile
{
    int position_x;
    int position_y;
    bool collected;
    int direction; // 0 = left | 1 = up | 2 = right | 3 down
    int projectileLevel;
};

extern struct projectile WIP;
extern bool thrown;

void throwProjectile();
void collectProjectile();
void WIPDisplay();
void projDim();
int proj_get_row(void);
int proj_get_col(void);



#endif