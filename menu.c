#include <stdio.h>
#include "menu.h"
#include "player.h"
#include "torch.h"
#include "map.h"
#include "doorAndKeys.h"
#include "box.h"
#include "projectile.h"

//Pedro
void printMenu() {
    int option[] = {1,2,3,4};
    int length = sizeof(option) / sizeof(option[0]);

    for(int i = 0; i < length; i++){
        printf(".▄▄ · ▄▄▄▄▄▄▄▄ . ▄▄▄·.▄▄ ·     ▪   ▐ ▄     ▄▄▄▄▄ ▄ .▄▄▄▄ .    ·▄▄▄▄   ▄▄▄· ▄▄▄  ▄ •▄ ");
        printf("\n▐█ ▀. •██  ▀▄.▀·▐█ ▄█▐█ ▀.     ██ •█▌▐█    •██  ██▪▐█▀▄.▀·    ██▪ ██ ▐█ ▀█ ▀▄ █·█▌▄▌▪");
        printf("\n▄▀▀▀█▄ ▐█.▪▐▀▀▪▄ ██▀·▄▀▀▀█▄    ▐█·▐█▐▐▌     ▐█.▪██▀▐█▐▀▀▪▄    ▐█· ▐█▌▄█▀▀█ ▐▀▀▄ ▐▀▀▄·");
        printf("\n▐█▄▪▐█ ▐█▌·▐█▄▄▌▐█▪·•▐█▄▪▐█    ▐█▌██▐█▌     ▐█▌·██▌▐▀▐█▄▄▌    ██. ██ ▐█ ▪▐▌▐█•█▌▐█.█▌");
        printf("\n ▀▀▀▀  ▀▀▀  ▀▀▀ .▀    ▀▀▀▀     ▀▀▀▀▀ █▪     ▀▀▀ ▀▀▀ · ▀▀▀     ▀▀▀▀▀•  ▀  ▀ .▀  ▀·▀  ▀");
        printf("\n\n1. Start Game\n2. Controls\n3. Credits\n4. Exit\n\nSelect Option: ");
        scanf("%d", &option[i]);
        if(option[i] == 1) 
            choosePlayerName();

        if (option[i] == 2){
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nW - Up\nA - Left\nS - Down\nD - Right\n\n");
            printMenu();
        }
            
        if (option[i] == 3){
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nThis game was developed by Xavier Dos Santos, Pedro Alao and Trent Kirby. Property of IADE\n\n");
            printMenu();
        } 
            
        if (option[i] == 4){
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nSee you next time!\n");
        } 
        else 
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nInvalid Option\n");
        break;
    }
}


//Pedro
void startGame() {

    levelSelect();
    while (1 == 1) {
        char input = readUserInput();
        // Trent
        if (input == '\n')
            continue;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        movePlayer(input);
        moveBox();
        checkInteraction();
        printMap();
    }
}

//Xavier and Pedro
void pauseGame(){
    int opt;
    printf("🐾 Steps in the Dark 🐾\n\n1. Continue\n2. Options\n3. Main Menu\n4. Level Select\n\nInsert Option: ");
    scanf("%d", &opt);
    
    switch (opt)
    {
    case 1:
        printf("\n\n\n");
        break;
    case 2:
        printf("\n\n\n");
        printf("\n\nThe movement controls for the player are:\nW - Up\nA - Left\nS - Down\nD - Right\n\n");
        break;
    case 3:
        printf("\n\n\n");
        printMenu();
        break;
    case 4:
        printf("\n\n\n");
        levelSelect();
    }
    
}

void endLevel(){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou've escaped from the Haunted Mansion, %s!\n\n", playerName);
    torchLevel = 15;
    stepCount = 0;
    player.position_x = 16;
    player.position_y = 1;
    
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
    getKey = false;
    thrown = false;
    levelSelect();
 }


//Xavier 
void levelSelect(){
    int opt;
    printf("Select a level to play 🔦");
    printf("\n\n");
    printf("1. Level 1\t2.  Level 2\t3. Level 3\t4. Level 4");
    printf("\n\n");
    scanf("%d", &opt);
     
    switch (opt)
    {
    case 0:
        printMenu();
        break;
    case 1:
        loadMap("map1.txt");
        isLevelOne = true;
        resetPlayer();
        printMap();
        break;
    case 2:
        loadMap("map2.txt");
        isLevelTwo = true;
        resetPlayer();
        printMap();
        break;
    case 3:
        loadMap("map3.txt");
        isLevelThree = true;
        resetPlayer();
        printMap();
        break;
    case 4:
        loadMap("map4.txt");
        isLevelFour = true;
        box1.position_x = 3;
        box1.position_y = 2;
        resetPlayer();
        printMap();
        break;
    default:
        printf("No level selected\n\n");
        levelSelect();
        break;
    }
}