#include <stdio.h>
#include <stdbool.h>
// #include "map.h"
// #include "menu.h"
// #include "player.h"
// #include "torch.h"
// Defining the Map & Tiles

#define MAP_ROWS 18
#define MAP_COLS 18

#define TILE_WALL 'W'
#define TILE_FLOORWHITE 'Z'
#define TILE_FLOORBLACK 'X'
#define TILE_TRAP 'T'
#define TILE_TORCH 'L'

// We'll have the Wall; Two Tiles (to make it a black and white chess pattern) and the trapped plates.

// Player Structure:
struct Player {
    int position_x;
    int position_y;
};

// Map and Player Global Variables

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

struct  Player player = {16, 1};

// Function Declaration

void printMenu();
void printMap();
void movePlayer(char dir);
void startGame();
void PlayerFunction();
void torchInteract();
char readUserInput();
bool isTileWalkable(char t);
void stepCounter();

int stepCount = 0;

int main(){ 
    printMenu();
    return 0;
}


// function initialization
//Pedro
void printMenu() {
    int option[] = {1,2,3,4};
    int length = sizeof(option) / sizeof(option[0]);

    for(int i = 0; i < length; i++){
        printf("🐾 Steps in the Dark 🐾\n\n1. Start Game\n2. Controls\n3. Credits\n4. Exit\n\nSelect Option: ");
        scanf("%d", &option[i]);
    if(option[i] == 1) 
        startGame();
    else if (option[i] == 2)
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nW - Up\nA - Left\nS - Down\nD - Right\n\n");
    else if (option[i] == 3) 
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nThis game was developed by Xavier Dos Santos, Pedro Alao and Trent Kirby.\n\n");
    else if (option[i] == 4) 
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nSee you next time!\n");
    else 
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nInvalid Option\n");
    break;
}
}


void startGame() {
    while (1 == 1) {
    printMap();
    char input = readUserInput();
    movePlayer(input);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
}


// Xavier & Pedro
void printMap(){
    for (int x = 0; x < MAP_ROWS; x++)
    {
        for (int y = 0; y < MAP_COLS; y++)
        {
            
            if ((x == player.position_x + 1 && y == player.position_y) || (x == player.position_x -1 && y == player.position_y) || (x == player.position_x && y == player.position_y + 1) || (x == player.position_x && y == player.position_y - 1))  {
                if (map[x][y] == 'X')
                 printf("🔳 ");
                if (map[x][y] == 'Z')
                  printf("⬜ ");
                if (map[x][y] == 'W')
                 printf("🧱 ");
                 
             }else
             
            if (x == player.position_x && y == player.position_y)
                printf("🤠 ");
            else if (map[x][y] == 'X')
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
        printf("\n"); 
    }
    
}

// Xavier
char readUserInput(){
    char  input;
    scanf("%c", &input);
    return input;
}

// Xavier & Trent
bool isTileWalkable(char t){
    return(t != 'W');
}


// Trent & Xavier
void movePlayer(char dir)
{
    
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
        stepCounter();    
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
        stepCounter();     
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
        stepCounter();   
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
        stepCounter();
        }
        break;
    }
}

void stepCounter(){
        stepCount++;
        printf("You have walked %d steps", stepCount);
    /* for when have dim function
    if(count == 5 ){
        torchDim();
    }
    */
}

// Trent
void torchInteract()
{
    printf("You used the torch!\n");
} 

        














