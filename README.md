# Steps_in_the_Dark
Game for IADE grid based project Class


# Formatting

Header files will be required and used for initialization of functions

Separate C files will be required for declaration and writing of functions

File naming & vairable declaration convention(s): camel case 
                    eg: menuMain.c
                        int stepCounter = 0;


# Compile

`gcc -Wall -Wextra -Werror -std=c17 box.c doorAndKeys.c main.c map.c menu.c player.c cheats.c torch.c projectile.c -o StepsintheDark && StepsintheDark`

# Game features
- Dynamic lighting
- Throwable projectile with dynamic lighting (Throwable is thrown in direction in which was picked up)
- Pressure plate system
- Box grabing and moving mechanics
