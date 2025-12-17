#include <stdio.h>
#include "torch.h"

int torchLevel = 15;

// Trent
void torchDim(){
    if (torchLevel-- == 5){
        printf("Your torch had run out of light!\n");
    
    }
        
}

// Trent
void torchInteract(){
    printf("You use the torch!\n");
    torchLevel = 15;
}

//Pedro
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
