#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "./Environment/map.h"
#include "./Menus/menu.h"
#include "./Player/player.h"
#include "./Environment/box.h"
#include "./Environment/doorAndKeys.h"
#include "torch.h"

// Defining the Map & Tiles

// #define MAP_ROWS 18
// #define MAP_COLS 18

// #define TILE_WALL 'W'
// #define TILE_FLOORWHITE 'Z'
// #define TILE_FLOORBLACK 'X'
// #define TILE_TRAP 'T'
// #define TILE_TORCH 'L'
// #define TILE_DOOR 'D'
// #define TILE_KEY 'K'
// #define TILE_PRESSUREPLATE 'P'


//bool getKey = false;


// We'll have the Wall; Two Tiles (to make it a black and white chess pattern) and the trapped plates.

// Player Structure:
// struct Player {
//     int position_x;
//     int position_y;
// };

// struct Box {
//     int position_x;
//     int position_y;
//     bool beingGrabbed;
//     int direction; // 0 = left | 1 = up | 2 = right | 3 down
// };

struct inventory{
    char name[20];
    int quantity;
};
// Map and Player Global Variables

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
    {'W', 'Z', 'X', 'Z', 'X', 'W', 'X', 'P', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'T', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'W', 'X', 'T', 'T', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'Z', 'X', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'W', 'T', 'X', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'W'},
    {'W', 'Z', 'X', 'Z', 'X', 'W', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'X', 'Z', 'L', 'W'},
    {'W', 'X', 'Z', 'X', 'Z', 'W', 'Z', 'X', 'L', 'L', 'Z', 'X', 'Z', 'X', 'Z', 'L', 'Z', 'W'},
    {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},

};

//struct Player player = {16, 1};
//struct Box box1 = {15, 2, false, 0};
struct inventory inventory[3]={};
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
void pauseGame();
void endLevel();
void choosePlayerName();
void collectKey();
void printInventory();
void shootProjectile();
void playerDeathCounter();
void torchDisplay();
void levelSelect();
void sanityDisplay();
void printDebugStats();
void moveBox();
void grabBox();

//int stepCount = 0;
//int torchLevel = 15;
// int deathCounter = 0;

int main(){ 
    printf("\n\n\n\n");
    printMenu();
    return 0;
}

// TODO:
/*
    - Don't forget to reset the box positions.
    - Don't forget to check if the box is colliding against a wall. IF it is, we CANNOT move the player.
*/


// function initialization

//Pedro
// void printMenu() {
//     int option[] = {1,2,3,4};
//     int length = sizeof(option) / sizeof(option[0]);

//     for(int i = 0; i < length; i++){
//         printf("🐾 Steps in the Dark 🐾\n\n1. Start Game\n2. Controls\n3. Credits\n4. Exit\n\nSelect Option: ");
//         scanf("%d", &option[i]);
//         if(option[i] == 1) 
//             choosePlayerName();
//         else if (option[i] == 2)
//             printf("\n\nThe movement controls for the player are:\nW - Up\nA - Left\nS - Down\nD - Right\n\n");
            
//         else if (option[i] == 3) 
//             printf("\n\nThis game was developed by Xavier Dos Santos, Pedro Alao and Trent Kirby.\n ©Three Rand Stuidios. Academic Property of IADE\n");
//             //add external names, companies if any external content was used
            
//         else if (option[i] == 4) 
//             printf("\n\nSee you next time!\n");
//         else 
//             printf("\n\nInvalid Option\n");
//         break;
//     }
// }

//char playerName[1000];

//Pedro
// void choosePlayerName(){
//     printf("\n\nWhat is the name of your character?\nInsert: ");
//     scanf("%s", playerName);
//     printf("\n\n\n\n");
//     startGame();
// }

//Pedro
// void startGame() {
//     printf("Welcome to the Haunted Manor, %s!\n\n", playerName);
//     torchLevel = 15;
//     stepCount = 0;
//     player.position_x = 16;
//     player.position_y = 1;
//     getKey = false;
//     map[1][1] = 'K';
//     deathCounter = 0;
//     printMap();
//     while (1 == 1) {
//         char input = readUserInput();
//         // Trent
//         if (input == '\n')
//             continue;
//         printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
//         movePlayer(input);
//         collectKey();
//         moveBox();
//         checkInteraction();
//         printMap();
//     }
// }

// Xavier & Pedro
// void printMap(){
//     printf("\n");
//     printf("Death Count: %d", deathCounter);
//     printInventory();
//     printf("\n");
//     torchDisplay();
//     sanityDisplay();
//     printDebugStats();
//     printf("\n\n");
//     for (int x = 0; x < MAP_ROWS; x++)
//     {
//         for (int y = 0; y < MAP_COLS; y++)
//         {
//             // player defualt vision radius
//             if (((x == player.position_x + 1 && y == player.position_y) || (x == player.position_x -1 && y == player.position_y) || (x == player.position_x && y == player.position_y + 1) || (x == player.position_x && y == player.position_y - 1) || (x == player.position_x -2 && y == player.position_y) || (x == player.position_x +2 && y == player.position_y) || (x == player.position_x && y == player.position_y-2) || (x == player.position_x && y == player.position_y+2) || (x == player.position_x +1 && y == player.position_y+1) || (x == player.position_x -1 && y == player.position_y+1) || (x == player.position_x +1 && y == player.position_y-1) || (x == player.position_x-1 && y == player.position_y-1)) && (torchLevel > 10)) {
//                 if (x == box1.position_x && y == box1.position_y) 
//                      printf("📦");
//                 else if (map[x][y] == 'X')
//                     printf("🟫");
//                 else if (map[x][y] == 'Z')
//                     printf("🟫");
//                 else if (map[x][y] == 'W')
//                     printf("🧱");
//                 else if (map[x][y] == 'T')
//                     printf("🕸️ ");
//                 else if (map[x][y] == 'P')
//                     printf("🟪");
//                 else if (map[x][y] == 'K')
//                      printf("🗝️ ");
//                 else if (map[x][y] == 'D')
//                     printf("🪜 ");
//                 //Trent. Torch now appears when in the light around the character
//                 else if (map[x][y]== 'L') {
//                     printf("🕯️ ");
                
                
//                 }
//             }

            
//             //play vision radius dim
//             else if (((x == player.position_x + 1 && y == player.position_y) || (x == player.position_x -1 && y == player.position_y) || (x == player.position_x && y == player.position_y + 1) || (x == player.position_x && y == player.position_y - 1)) && (torchLevel > 5)) {
//             if (x == box1.position_x && y == box1.position_y) 
//                      printf("📦"); 
//                 else if (map[x][y] == 'X')
//                     printf("🟫");
//                 else if (map[x][y] == 'Z')
//                     printf("🟫");
//                 else if (map[x][y] == 'W')
//                     printf("🧱");
//                 else if (map[x][y] == 'T')
//                     printf("🕸️ ");
//                 else if (map[x][y] == 'P')
//                     printf("🟪");
//                 else if (map[x][y] == 'K')
//                      printf("🗝️ ");
//                 else if (map[x][y] == 'D')
//                     printf("🪜 ");
//                 //Trent. Torch now appears when in the light around the character
//                 else if (map[x][y]== 'L')
//                     printf("🕯️ ");
                
//         }  //candle/ environmental torch lighting  
//            else if (x == player.position_x && y == player.position_y) 
//                      printf("🤠");
//            else if (x == box1.position_x && y == box1.position_y) 
//                      printf("📦"); 
//              else if ((map[x][y]== 'L') || (x > 0 && map[x-1][y] == 'L') || (x < MAP_ROWS - 1 && map[x+1][y] == 'L') || (y > 0 && map[x][y-1] == 'L') || (y < MAP_COLS - 1 && map[x][y+1] == 'L') || (x > 0 && y > 0 && map[x - 1][y - 1] == 'L') ||(x > 0 && y < MAP_COLS - 1 && map[x - 1][y + 1] == 'L') || (x < MAP_ROWS - 1 && y > 0 && map[x + 1][y - 1] == 'L') || (x < MAP_ROWS - 1 && y < MAP_COLS - 1 && map[x + 1][y + 1] == 'L')) {
//                 if (map[x][y] == 'X') 
//                      printf("🟫");
//                 if (map[x][y] == 'Z')
//                      printf("🟫");
//                 if (map[x][y] == 'W')
//                       printf("🧱");
//                 if (map[x][y] == 'K')
//                      printf("🗝️ ");
//                 if (map[x][y]== 'L')
//                       printf("🕯️ ");
//                 if (map[x][y] == 'D')
//                      printf("🪜 ");
//                 if (map[x][y] == 'P')
//                     printf("🟪");
//                 }
//                 //blacking out map
//                  else if (x == player.position_x && y == player.position_y) 
//                      printf("🤠");
//                 else if (x == box1.position_x && y == box1.position_y) 
//                      printf("⬛");
//                  else if(map[x][y] == 'X')
//                       printf("⬛");
//                  else if (map[x][y] == 'Z')
//                      printf("⬛");
//                   else if (map[x][y] == 'W')
//                      printf("⬛");
//                     else if (map[x][y] == 'P')
//                     printf("⬛");
//                   else if (map[x][y] == 'T')
//                       printf("⬛");
//                  else if (map[x][y]== 'L')
//                      printf("🕯️ ");
//                 else if (map[x][y] == 'D')
//                      printf(" 🪜 ");
//                 else if (map[x][y] == 'K')
//                      printf("🗝️ ");
//                  else printf("%c", map[x][y]);  
//         }
        
//        if (torchLevel == 0){
//         playerDeath();}

//         printf("\n"); 
//     }
// }



// Xavier
// char readUserInput(){
//     char input;
//     scanf("%c", &input);
//     return input;
// }

// Xavier & Trent
// bool isTileWalkable(char t){
//     return(t != 'W' && map[box1.position_x][box1.position_y]);
// }

// Trent & Xavier
// void movePlayer(char dir)
// {
    
//     switch (dir)
//     {
//     case 'W':
//     case 'w':
//         if (isTileWalkable(map[player.position_x - 1][player.position_y]))
//         {
//         if (map[player.position_x][player.position_y] == 'T'){
//             playerDeath();
//         }
//         if (map[player.position_x][player.position_y] == 'D' && getKey == true){
//             endLevel();
//         }
        
//             player.position_x--;
//             stepCounter();
//             printf("\n");    
//         }
//         break;

//     case 'A':
//     case 'a':
//         if (isTileWalkable(map[player.position_x][player.position_y - 1]))
//         {
//         if (map[player.position_x][player.position_y] == 'T'){
//             playerDeath();
//         }  
//         if (map[player.position_x][player.position_y] == 'D' && getKey == true){
//             endLevel();
//         }
//             player.position_y--;
//             stepCounter();
//             printf("\n");     
//         }
//         break;

//     case 'S':
//     case 's':
//         if (isTileWalkable(map[player.position_x + 1][player.position_y]))
//         {
//         if (map[player.position_x][player.position_y] == 'T'){
//             playerDeath();
//         }
//         if (map[player.position_x][player.position_y] == 'D' && getKey == true){
//             endLevel();
//         }
//             player.position_x++;
//             stepCounter();
//             printf("\n");   
//         }
//         break;

//     case 'D':
//     case 'd':
//         if (isTileWalkable(map[player.position_x][player.position_y + 1]))
//         {  
//         if (map[player.position_x][player.position_y] == 'T'){
//             playerDeath();
//         }
//         if (map[player.position_x][player.position_y] == 'D' && getKey == true){
//             endLevel();
//         }
//             player.position_y++;
//             stepCounter();
//             printf("\n");
//         }
//         break;
//     //pause menu
//     case 'P':
//     case 'p':
//         pauseGame();
//         break;
//     //case 'X':
//      //   shootProjectile();
//      //   break;
//     case 'E':
//     case 'e':
//         grabBox();
    
//     }
// }

//Xaiver & Trent
// void stepCounter(){
//     stepCount++;
//     if( torchLevel > 0 ){
//         torchDim();
//     }
// }

// Trent
// void checkInteraction(){
//     printf("You have walked %d steps\n", stepCount);
//     switch (map[player.position_x][player.position_y]) {
//         case 'X':
//             //X interaction code
//             break;

//         case 'Z':
//             //X interaction code
//             break;

//         case 'W':
//             //W interaction code. Probably nothing
//             break;

//         case 'T':
//             //T interaction code
//             break;

//         case 'L':
//             torchInteract();
//             break;
//     }
    

// }

// Trent
// void torchDim(){
//     if (torchLevel-- == 5){
//         printf("Your torch had run out of light!\n");
    
//     }
        
// }


// Trent
// void torchInteract(){
//     printf("You use the torch!🕯️\n");
//     torchLevel = 15;
// }

//Xavier
// reset box values
// void playerDeath(){
//     printf("\tYOU DIED 💀"); 
//     torchLevel = 15;
//     stepCount = 0;
//     player.position_x = 16;
//     player.position_y = 1;
//     getKey = false;
//     map[1][1] = 'K';
//     playerDeathCounter();
//     // box1.position_x = 15;
//     // box1.position_y = 2;
// }


//Pedro
// void endLevel(){
//     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou've escaped from the Haunted Mansion, %s!\n\n", playerName);
//     torchLevel = 15;
//     stepCount = 0;
//     player.position_x = 16;
//     player.position_y = 1;
//     printMenu();
// }


//Xavier & Pedro
// void pauseGame(){
//     int opt;
//     printf("🐾 Steps in the Dark 🐾\n\n1. Continue\n2. Options\n3. Main Menu\n\nInsert Option: ");
//     scanf("%d", &opt);
    
//     switch (opt)
//     {
//     case 1:
//         printf("\n\n\n");
//         break;
//     case 2:
//         printf("\n\n\n");
//         printf("\n\nThe movement controls for the player are:\nW - Up\nA - Left\nS - Down\nD - Right\n\n");
//         break;
//     case 3:
//         printf("\n\n\n");
//         printMenu();
//         break;
//     }
    
// }

// void collectKey() {
//     if(map[player.position_x][player.position_y] == 'K') {
//         getKey = true;
//         map[player.position_x][player.position_y] = 'X';
 
//     }
// }

void printInventory(){
    printf("\t\tInventory:");
    if (getKey == true)
    {
        printf("🗝️");
    }
    
}



// void playerDeathCounter() {
//     deathCounter++;
// }

void torchDisplay() {
    printf("\n");
    printf("Torch Meter: ");
    if(torchLevel == 15){
        printf("[🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩]");
    }
    if(torchLevel == 14){
        printf("[🟩🟩🟩🟩🟩🟩🟩🟩🟩⬛]");
    }
    if(torchLevel == 13){
        printf("[🟩🟩🟩🟩🟩🟩🟩🟩⬛⬛]");
    }
    if(torchLevel == 12){
        printf("[🟩🟩🟩🟩🟩🟩🟩⬛⬛⬛]");
    }
    if(torchLevel == 11){
        printf("[🟩🟩🟩🟩🟩🟩⬛⬛⬛⬛]");
    }
    if(torchLevel == 10){
        printf("[🟨🟨🟨🟨🟨⬛⬛⬛⬛⬛]");
    }
    if(torchLevel == 9){
        printf("[🟨🟨🟨🟨⬛⬛⬛⬛⬛⬛]");
    }
    if(torchLevel == 8){
        printf("[🟨🟨🟨⬛⬛⬛⬛⬛⬛⬛]");
    }
    if(torchLevel == 7){
        printf("[🟨🟨⬛⬛⬛⬛⬛⬛⬛⬛]");
    }
    if(torchLevel == 6){
        printf("[🟥⬛⬛⬛⬛⬛⬛⬛⬛⬛]");
    }
    if(torchLevel < 6){
        printf("[⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛]");
    }
    
}


//Xavier
// void levelSelect(){
//     int opt;
//     printf("Select a level to play 🔦");
//     scanf("%d", &opt);
//     switch (opt)
//     {
//     case 1:
        
//         break;
    
//     default:
//         break;
//     }
// }


//Pedro
void sanityDisplay() {
    printf("\n");
    printf("Sanity Meter: ");
    if(torchLevel > 4){
        printf("[🧠🧠🧠🧠🧠]");
    }
    if(torchLevel == 4){
        printf("[🧠🧠🧠🧠⬛]");
    }
    if(torchLevel == 3){
        printf("[🧠🧠🧠⬛⬛]");
    }
    if(torchLevel == 2){
        printf("[🧠🧠⬛⬛⬛]");
    }
    if(torchLevel == 1){
        printf("[🧠⬛⬛⬛⬛]");
    }
    if(torchLevel == 0){
        printf("[⬛⬛⬛⬛⬛]");
    }

}

void printDebugStats() {
    printf("\n");
    printf("Is the box being grabbed : %s", box1.beingGrabbed ? "True" : "False");
}







// void moveBox()
// {
//     if (!box1.beingGrabbed) return;

//     printf("time to move box\n");
//     // 0 = left | 1 = up | 2 = right | 3 down

//     if (box1.direction == 1 ) {
//             box1.position_x= player.position_x + 1;
//             box1.position_y = player.position_y;
//     }else if (box1.direction == 3 ) {
//             box1.position_x = player.position_x - 1;
//             box1.position_y = player.position_y;
//     }else if (box1.direction == 0 ) {
//             box1.position_x = player.position_x;
//             box1.position_y = player.position_y - 1;
//     }else {
//         // is 2 here. everything else failed.
//                     box1.position_x = player.position_x;
//             box1.position_y = player.position_y - 1;
//     }

// }

// void grabBox(){
//     // We need to check if the player is close to the box.
//     if (box1.beingGrabbed)
//         box1.beingGrabbed = false;
//     else {

//         // 0 = left | 1 = up | 2 = right | 3 down
//         if (player.position_x + 1 == box1.position_x && player.position_y == box1.position_y) {
//                 box1.direction = 1;
//                 box1.beingGrabbed = true;
//             } else if (player.position_x - 1 == box1.position_x && player.position_y == box1.position_y) {
//                 box1.direction = 3;
//                 box1.beingGrabbed = true;
//             } else if (player.position_y - 1 < MAP_ROWS && player.position_x == box1.position_x && player.position_y - 1 == box1.position_y) {
//                 box1.direction = 0;
//                 box1.beingGrabbed = true;
//             } else if (player.position_y + 1 < MAP_ROWS && player.position_x == box1.position_x && player.position_x + 1 == box1.position_y) {
//                 box1.direction = 2;
//                 box1.beingGrabbed = true;
//             }
//     }

// }