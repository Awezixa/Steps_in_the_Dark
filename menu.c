#include <stdio.h>
#include "menu.h"
#include "player.h"

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
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        movePlayer(input);
        checkInteraction();
        printMap();
    }
}

//Xavier and Pedro
void pauseGame(){
    int opt;
    printf("🐾 Steps in the Dark 🐾\n\n1. Continue\n2. Options\n3. Main Menu\n\nInsert Option: ");
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
    }
    
}


//Xavier 
void levelSelect(){
    int opt;
    printf("Select a level to play 🔦");
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
        printmap();
        break;
    case 2:
        printMap();
        break;
    default:
        break;
    }
}