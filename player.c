#include <stdio.h>
#include "player.h"
#include "map.h"
#include "doorAndKeys.h"
#include "torch.h"
#include "menu.h"
#include "box.h"
#include ".\Cheats/cheats.h"
#include "projectile.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

int stepCount = 0;
int deathCounter = 0;
char playerName[1000];
bool fullBrightOn = false;
bool isLevelOne = false;
bool isLevelTwo = false;
bool isLevelThree = false;
bool isLevelFour = false;

struct Player player = {16, 1};

// Trent & Xavier
void movePlayer(char dir)
{
    
    switch (dir)
    {
    case 'W':
    case 'w':
        if( box1.beingGrabbed == true) {
        if (isTileWalkable(map[player.position_x - 1][player.position_y]) && isTileWalkable(map[box1.position_x-1][box1.position_y]))
        {
        
        if ((map[player.position_x][player.position_y] == 'D') && (getKey == true)){
            endLevel();
        }
            player.position_x--;
            stepCounter();
        }
    }
        else if( box1.beingGrabbed == false) {
            if (isTileWalkable(map[player.position_x - 1][player.position_y]))
        {
       
        if ((map[player.position_x][player.position_y] == 'D') && (getKey == true)){
            endLevel();
        }
            player.position_x--;
            stepCounter();
        }}
        break;

    case 'A':
    case 'a':
         if( box1.beingGrabbed == true) {
        if (isTileWalkable(map[player.position_x][player.position_y - 1]) && isTileWalkable(map[box1.position_x][box1.position_y-1]))
        {
        
        if ((map[player.position_x][player.position_y] == 'D') && (getKey == true)){
            endLevel();
        }
            player.position_y--;
            stepCounter();     
        }}
         else if( box1.beingGrabbed == false) {
            if (isTileWalkable(map[player.position_x][player.position_y-1]))
        {
        
        if ((map[player.position_x][player.position_y] == 'D') && (getKey == true)){
            endLevel();
        }
            player.position_y--;
            stepCounter();
        }}
        break;

    case 'S':
    case 's':
     if( box1.beingGrabbed == true) {
        if (isTileWalkable(map[player.position_x + 1][player.position_y]) && isTileWalkable(map[box1.position_x+1][box1.position_y]))
        {
        
        if ((map[player.position_x][player.position_y] == 'D') && (getKey == true)){
            endLevel();
        }
            player.position_x++;
            stepCounter();   
        }}
        else if( box1.beingGrabbed == false) {
            if (isTileWalkable(map[player.position_x+1][player.position_y]))
        {
       
        if ((map[player.position_x][player.position_y] == 'D') && (getKey == true)){
            endLevel();
        }
            player.position_x++;
            stepCounter();
        }}
        break;

    case 'D':
    case 'd':
     if( box1.beingGrabbed == true) {
        if (isTileWalkable(map[player.position_x][player.position_y + 1]) && isTileWalkable(map[box1.position_x][box1.position_y+1]))
        {   
       
        if ((map[player.position_x][player.position_y] == 'D') && (getKey = true)){
            endLevel();
        }
            player.position_y++;
            stepCounter();
        }}
          else if( box1.beingGrabbed == false) {
             if (isTileWalkable(map[player.position_x][player.position_y+1]))
        {
      
        if ((map[player.position_x][player.position_y] == 'D') && (getKey == true)){
            endLevel();
        }
            player.position_y++;
            stepCounter();
        }}
        break;
    case 'P':
    case 'p':
        pauseGame();
        break;
    case 'E':
    case 'e':
        grabBox();
        collectProjectile();
        break;
    case 'T':
    case 't':
        if (WIP.collected == true)
        {
            throwProjectile();
        }
        else{
            printf("You dont have the projectile.");
        }
       
       break;
        //cheats
        //activate full brigtness cheat
    case 'F':
    case 'f':
        fullBrightOn = true;
        break;
        
        //deactivate full brightness cheat 
    case 'G':
    case 'g':
        fullBrightOn = false;
        break;
        //give key
    case 'K':
    case 'k':
        getKey = true;
        break;
    case 'C':
    case 'c':
        cheats = true;
        break;
   case 'J':
   case 'j':
       //give projectile
       WIP.collected = true;
       break;
    }
    
}



//Xavier
char readUserInput(){
    char  input;
    scanf("%c", &input);
    return input;
}

//Xavier & Trent
bool isTileWalkable(char t){
    return(t != 'W' && t != 'H');
}


//Xaiver & Trent 
void stepCounter(){
    stepCount++;
    projDim();
    if( torchLevel > 0 )
    {
        torchDim();
    }
}


//Xavier
void playerDeath(){
    
    resetPlayer();

    if(isLevelOne == true){
    box1.position_x = 8;
    box1.position_y = 10;
    }

    if(isLevelTwo == true){
    box1.position_x = 8;
    box1.position_y = 10;
    }

    if(isLevelThree == true){
        box1.position_x = 8;
        box1.position_y = 10;
    }
    if(isLevelFour == true){
        box1.position_x = 3;
        box1.position_y = 2;
    }    
    box1.beingGrabbed = false;
    playerDeathCounter();
}

// Trent
void checkInteraction(){
    printf("You have walked %d steps\n", stepCount);
    switch (map[player.position_x][player.position_y]) {
        case 'T':
            playerDeath();
            break;

        case 'K':
            collectKey();
            break;

        case 'D':
            if (getKey == true){
                endLevel();
            }
            break;

        case 'L':
            torchInteract();
            break;
    }
    

}

//Pedro
void playerDeathCounter() {
    deathCounter++;
}

//Pedro
void choosePlayerName(){
    printf("\n\nWhat is the name of your character?\nInsert: ");
    scanf("%s", playerName);
    printf("\n\n\n\n");
    startGame();
}

//Pedro
void sanityDisplay(){    
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

//Pedro
void printInventory(){
    printf("\t\tInventory:");

    if (getKey == true)
    {
        printf("🗝️ ");
    }
    if (WIP.collected == true)
    {
       printf(" 💣");
    }
    
}

//Xavier
void resetPlayer(){
    player.position_x = 16;
    player.position_y = 1;
    stepCount = 0;
    torchLevel = 15;
    getKey = false;
    WIP.collected = false;
    WIP.projectileLevel = 15;
}


int player_get_row(void)
{
    return player.position_x;
}

int player_get_col(void)
{
    return player.position_y;
}