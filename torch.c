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
