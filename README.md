# Steps_in_the_Dark
Game for IADE grid based project Class


# Formatting

Header files will be required and used for initialization of functions

Separate C files will be required for declaration and writing of functions

File naming & vairable declaration convention(s): camel case 
                    eg: menuMain.c
                        int stepCounter = 0;


# Compile

`gcc -Wall -Wextra -Werror -std=c17 main.c menu.c player.c torch.c -o game && game`

We need:

1 - Menu

2 - Player
    2.1 - Player Movement
    2.2 - Player Death

3 - Torch
    3.1 - Torch Brightness
    3.2 - Torch Dimming

4 - Map
    4.1 - Trapped Plates
    4.2 - Key & Door