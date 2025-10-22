#include <stdio.h>
#include "player.h"

struct  Player player = {16, 1};


// Trent & Xavier
void movePlayer(char dir)
{
    printf("Moving player to %c\n", dir);
    
    switch (dir)
    {
    case 'W':
    case 'w':
        if (isTileWalkable(map[player.position_x - 1][player.position_y]))
        {
            if (map[player.position_x][player.position_y] == 'T')
            {
                printf("You stepped on a trap and died!\n");
                //PlayerDeath();
            }
            player.position_x--;
        }
        break;
    case 'A':
    case 'a':
        if (isTileWalkable(map[player.position_x][player.position_y - 1]))
        {
            if (map[player.position_x][player.position_y] == 'T')
            {
                printf("You stepped on a trap and died!\n");
                //PlayerDeath();
            }
            player.position_y--;
        }
        break;
    case 'S':
    case 's':
        if (isTileWalkable(map[player.position_x + 1][player.position_y]))
        {
            if (map[player.position_x][player.position_y] == 'T')
            {
                printf("You stepped on a trap and died!\n");
                //PlayerDeath();
            }
            player.position_x++;
        }
        break;
    case 'D':
    case 'd':
        if (isTileWalkable(map[player.position_x][player.position_y + 1]))
        {
            if (map[player.position_x][player.position_y] == 'T')
            {
                printf("You stepped on a trap and died!\n");
                //PlayerDeath();
            }
            player.position_y++;
        }
        break;
    }
}

