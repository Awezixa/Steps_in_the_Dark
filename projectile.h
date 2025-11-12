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

void throwProjectile();
void collectProjectile();




#endif