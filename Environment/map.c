#include <stdio.h>
#include "map.h"
#include "player.h"
#include "box.h"
#include "torch.h"

//Level 1
char map[MAP_ROWS][MAP_COLS] = {
    {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
    {'W', 'K', 'L', 'Z', 'X', 'W', 'X', 'Z', 'L', 'L', 'X', 'Z', 'W', 'Z', 'X', 'L', 'D', 'W'}, 
    {'W', 'L', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'L', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'Z', 'Z', 'T', 'Z', 'X', 'Z', 'L', 'W', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'L', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'L', 'W', 'Z', 'X', 'Z', 'L', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'T', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'W', 'X', 'T', 'T', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'W', 'T', 'X', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'L', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'L', 'L', 'Z', 'X', 'Z', 'X', 'Z', 'L', 'Z', 'W'},
    {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},

};

// Map2 or level 2
char map[MAP_ROWS][MAP_COLS] = {
    {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
    {'W', 'T', 'L', 'Z', 'X', 'Z', 'T', 'Z', 'L', 'L', 'X', 'Z', 'W', 'Z', 'X', 'L', 'D', 'W'}, 
    {'W', 'L', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'L', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'T', 'T', 'T', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'K', 'W', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'Z', 'Z', 'W', 'W', 'X', 'Z', 'L', 'W', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'L', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'L', 'W', 'Z', 'X', 'Z', 'L', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'T', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'W', 'X', 'T', 'T', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'W', 'T', 'X', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'L', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'L', 'L', 'Z', 'X', 'Z', 'X', 'Z', 'L', 'Z', 'W'},
    {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
};




// Xavier & Pedro
void printMap(){
    printf("\n");
    printf("Death Count: %d", deathCounter);
    printInventory();
    printf("\n");
    torchDisplay();
    sanityDisplay();
    printDebugStats();
    printf("\n\n");
    for (int x = 0; x < MAP_ROWS; x++)
    {
        for (int y = 0; y < MAP_COLS; y++)
        {
            // player defualt vision radius
            if (((x == player.position_x + 1 && y == player.position_y) || (x == player.position_x -1 && y == player.position_y) || (x == player.position_x && y == player.position_y + 1) || (x == player.position_x && y == player.position_y - 1) || (x == player.position_x -2 && y == player.position_y) || (x == player.position_x +2 && y == player.position_y) || (x == player.position_x && y == player.position_y-2) || (x == player.position_x && y == player.position_y+2) || (x == player.position_x +1 && y == player.position_y+1) || (x == player.position_x -1 && y == player.position_y+1) || (x == player.position_x +1 && y == player.position_y-1) || (x == player.position_x-1 && y == player.position_y-1)) && (torchLevel > 10)) {
                if (x == box1.position_x && y == box1.position_y) 
                     printf("📦");
                else if (map[x][y] == 'X')
                    printf("🟫");
                else if (map[x][y] == 'Z')
                    printf("🟫");
                else if (map[x][y] == 'W')
                    printf("🧱");
                else if (map[x][y] == 'T')
                    printf("🕸️ ");
                else if (map[x][y] == 'P')
                    printf("🟪");
                else if (map[x][y] == 'K')
                     printf("🗝️ ");
                else if (map[x][y] == 'D')
                    printf("🪜 ");
                //Trent. Torch now appears when in the light around the character
                else if (map[x][y]== 'L') {
                    printf("🕯️ ");
                
                
                }
            }

            
            //play vision radius dim
            else if (((x == player.position_x + 1 && y == player.position_y) || (x == player.position_x -1 && y == player.position_y) || (x == player.position_x && y == player.position_y + 1) || (x == player.position_x && y == player.position_y - 1)) && (torchLevel > 5)) {
            if (x == box1.position_x && y == box1.position_y) 
                     printf("📦"); 
                else if (map[x][y] == 'X')
                    printf("🟫");
                else if (map[x][y] == 'Z')
                    printf("🟫");
                else if (map[x][y] == 'W')
                    printf("🧱");
                else if (map[x][y] == 'T')
                    printf("🕸️ ");
                else if (map[x][y] == 'P')
                    printf("🟪");
                else if (map[x][y] == 'K')
                     printf("🗝️ ");
                else if (map[x][y] == 'D')
                    printf("🪜 ");
                //Trent. Torch now appears when in the light around the character
                else if (map[x][y]== 'L')
                    printf("🕯️ ");
                
        }  //candle/ environmental torch lighting  
           else if (x == player.position_x && y == player.position_y) 
                     printf("🤠");
           else if (x == box1.position_x && y == box1.position_y) 
                     printf("📦"); 
             else if ((map[x][y]== 'L') || (x > 0 && map[x-1][y] == 'L') || (x < MAP_ROWS - 1 && map[x+1][y] == 'L') || (y > 0 && map[x][y-1] == 'L') || (y < MAP_COLS - 1 && map[x][y+1] == 'L') || (x > 0 && y > 0 && map[x - 1][y - 1] == 'L') ||(x > 0 && y < MAP_COLS - 1 && map[x - 1][y + 1] == 'L') || (x < MAP_ROWS - 1 && y > 0 && map[x + 1][y - 1] == 'L') || (x < MAP_ROWS - 1 && y < MAP_COLS - 1 && map[x + 1][y + 1] == 'L')) {
                if (map[x][y] == 'X') 
                     printf("🟫");
                if (map[x][y] == 'Z')
                     printf("🟫");
                if (map[x][y] == 'W')
                      printf("🧱");
                if (map[x][y] == 'K')
                     printf("🗝️ ");
                if (map[x][y]== 'L')
                      printf("🕯️ ");
                if (map[x][y] == 'D')
                     printf("🪜 ");
                if (map[x][y] == 'P')
                    printf("🟪");
                }
                //blacking out map
                 else if (x == player.position_x && y == player.position_y) 
                     printf("🤠");
                else if (x == box1.position_x && y == box1.position_y) 
                     printf("⬛");
                 else if(map[x][y] == 'X')
                      printf("⬛");
                 else if (map[x][y] == 'Z')
                     printf("⬛");
                  else if (map[x][y] == 'W')
                     printf("⬛");
                    else if (map[x][y] == 'P')
                    printf("⬛");
                  else if (map[x][y] == 'T')
                      printf("⬛");
                 else if (map[x][y]== 'L')
                     printf("🕯️ ");
                else if (map[x][y] == 'D')
                     printf(" 🪜 ");
                else if (map[x][y] == 'K')
                     printf("🗝️ ");
                 else printf("%c", map[x][y]);  
        }
        
       if (torchLevel == 0){
        playerDeath();}

        printf("\n"); 
    }
}

