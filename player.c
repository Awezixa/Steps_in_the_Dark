#include <stdio.h>
#include "player.h"
#include "map.c"
#include "map.h"



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
            stepCounter();
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
            stepCounter();
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
            stepCounter();
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
            stepCounter();
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

char readUserInput(){
    char  input;
    scanf("%c", &input);
    return input;
}


bool isTileWalkable(char t){
    return(t != 'W');
}

void stepCounter(){
    int count = 0;
    if (player.position_x++ || player.position_y++ || player.position_x-- || player.position_y--)
    {
        count++;
        printf("\nYou have walked %d steps", count);
    }
    /* for when have dim function
    if(count == 5 ){
        torchDim();
    }
    */
    return count;
}