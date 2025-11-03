#include <stdio.h>
#include "player.h"
#include "map.c"
#include "map.h"



struct  Player player = {16, 1};


// Trent & Xavier
void movePlayer(char dir)
{
    
    switch (dir)
    {
    case 'W':
    case 'w':
        if (isTileWalkable(map[player.position_x - 1][player.position_y]))
        {
        if (map[player.position_x][player.position_y] == 'T'){
            playerDeath();
        }
            player.position_x--;
            stepCounter();    
        }
        break;

    case 'A':
    case 'a':
        if (isTileWalkable(map[player.position_x][player.position_y - 1]))
        {
        if (map[player.position_x][player.position_y] == 'T'){
            playerDeath();
        }  
            player.position_y--;
            stepCounter();     
        }
        break;

    case 'S':
    case 's':
        if (isTileWalkable(map[player.position_x + 1][player.position_y]))
        {
        if (map[player.position_x][player.position_y] == 'T'){
            playerDeath();
        }
            player.position_x++;
            stepCounter();   
        }
        break;

    case 'D':
    case 'd':
        if (isTileWalkable(map[player.position_x][player.position_y + 1]))
        {   
        if (map[player.position_x][player.position_y] == 'T'){
            playerDeath();
        }
            player.position_y++;
            stepCounter();
        }
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
    return(t != 'W');
}

//Xaiver & Trent
void stepCounter(){
    stepCount++;
    if( torchLevel > 0 ){
        torchDim();
    }
}



//Xavier
void playerDeath(){
    printf("\tYOU DIED 💀"); 
    torchLevel = 15;
    stepCount = 0;
    player.position_x = 16;
    player.position_y = 1;
    getKey = false;
    map[1][1] = 'K';
    playerDeathCounter();
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

//Pedro
void playerDeathCounter() {
    deathCounter++;
}