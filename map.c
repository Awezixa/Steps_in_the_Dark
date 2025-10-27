#include <stdio.h>
#include "map.h"
#include "player.h"

char map[MAP_ROWS][MAP_COLS] = {
    {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
    {'W', 'Z', 'L', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W'}, 
    {'W', 'L', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},

};

// Xavier & Pedro
void printMap(){
    for (int x = 0; x < MAP_ROWS; x++)
    {
        for (int y = 0; y < MAP_COLS; y++)
        {
            // player defualt vision radius
            if (((x == player.position_x + 1 && y == player.position_y) || (x == player.position_x -1 && y == player.position_y) || (x == player.position_x && y == player.position_y + 1) || (x == player.position_x && y == player.position_y - 1) || (x == player.position_x -2 && y == player.position_y) || (x == player.position_x +2 && y == player.position_y) || (x == player.position_x && y == player.position_y-2) || (x == player.position_x && y == player.position_y+2) || (x == player.position_x +1 && y == player.position_y+1) || (x == player.position_x -1 && y == player.position_y+1) || (x == player.position_x +1 && y == player.position_y-1) || (x == player.position_x-1 && y == player.position_y-1)) && (torchLevel > 10)) {
                if (map[x][y] == 'X')
                    printf("🔳 ");
                if (map[x][y] == 'Z')
                    printf("⬜ ");
                if (map[x][y] == 'W')
                    printf("🧱 ");
                if (map[x][y] == 'T')
                    printf("🕸️  ");
                //Trent. Torch now appears when in the light around the character
                if (map[x][y]== 'L')
                    printf("🕯️  ");
                    (map[x+1] || map[y+1] || map[y-1] || map[y]
                if (map[x][y)
            }
            //play vision radius dim
            else if (((x == player.position_x + 1 && y == player.position_y) || (x == player.position_x -1 && y == player.position_y) || (x == player.position_x && y == player.position_y + 1) || (x == player.position_x && y == player.position_y - 1)) && (torchLevel > 5)) {
                if (map[x][y] == 'X')
                    printf("🔳 ");
                if (map[x][y] == 'Z')
                    printf("⬜ ");
                if (map[x][y] == 'W')
                    printf("🧱 ");
                if (map[x][y] == 'T')
                    printf("🕸️  ");
                //Trent. Torch now appears when in the light around the character
                if (map[x][y]== 'L')
                    printf("🕯️  ");
        }   
                 else if (x == player.position_x && y == player.position_y) 
                     printf("🤠 ");
                 else if(map[x][y] == 'X')
                      printf("⬛ ");
                 else if (map[x][y] == 'Z')
                     printf("⬛ ");
                  else if (map[x][y] == 'W')
                     printf("⬛ ");
                  else if (map[x][y] == 'T')
                      printf("⬛ ");
                 else if (map[x][y]== 'L')
                     printf("🕯️  ");
                 else printf("%c", map[x][y]);
            
        } 
       if (torchLevel == 0){
        playerDeath();}

        printf("\n"); 
    }
}

