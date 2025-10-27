#include <stdio.h>
#include "torch.h"

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
