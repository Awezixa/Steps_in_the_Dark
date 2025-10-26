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
    {'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'T', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'T', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'T', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'T', 'T', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'X', 'T', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'W'},
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
void playerDeath();
void torchDim();
void checkInteraction();

int stepCount = 0;
int torchLevel = 5;

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

//Pedro
void startGame() {
    printMap();
    while (1 == 1) {
        char input = readUserInput();
        // Trent
        if (input == '\n')
            continue;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        movePlayer(input);
        checkInteraction();
        printMap();
    }
}

// Xavier & Pedro
void printMap(){
    for (int x = 0; x < MAP_ROWS; x++)
    {
        for (int y = 0; y < MAP_COLS; y++)
        {
            if (((x == player.position_x + 1 && y == player.position_y) || (x == player.position_x -1 && y == player.position_y) || (x == player.position_x && y == player.position_y + 1) || (x == player.position_x && y == player.position_y - 1)) && (torchLevel > 0)) {
                if (map[x][y] == 'X')
                    printf("🔳 ");
                if (map[x][y] == 'Z')
                    printf("⬜ ");
                if (map[x][y] == 'W')
                    printf("🧱 ");
                if (map[x][y] == 'T')
                    printf(" 🕸️ ");
                //Trent. Torch now appears when in the light around the character
                if (map[x][y]== 'L')
                    printf("🕯️ ");
            }
            else if (x == player.position_x && y == player.position_y)
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
                printf("🕯️ ");
            else printf("%c", map[x][y]);
        } 
        printf("\n"); 
    }
}

// Xavier
char readUserInput(){
    char input;
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
                playerDeath();
                break;
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
                playerDeath();
                break;
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
                playerDeath();
                break;
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
                playerDeath();
                break;
            }
        player.position_y++;
        stepCounter();
        }
        break;
    }
}

void stepCounter(){
    stepCount++;
    if( torchLevel > 0 ){
        torchDim();
    }
}

// Trent
void checkInteraction(){
    printf("You have walked %d steps\n", stepCount);
    switch (map[player.position_x][player.position_y]) {
        case 'X':
            //X interaction code
            break;

        case 'Z':
            //X interaction code
            break;

        case 'W':
            //W interaction code. Probably nothing
            break;

        case 'T':
            //T interaction code
            break;

        case 'L':
            torchInteract();
            break;
    }
    

}

// Trent
void torchDim(){
    if (--torchLevel == 0){
        printf("Your torch had run out of light!\n");
    }
}

// Trent
void torchInteract(){
    printf("You use the torch!\n");
    torchLevel = 5;
}

//Xavier
void playerDeath(){
    printf("YOU DIED 💀\n");
    torchLevel = 5;
    player.position_x = 16;
    player.position_y = 1;
}