#include <stdio.h>
#include "player.h"
#include "map.h"
#include "doorAndKeys.h"
#include "torch.h"
#include "menu.h"
#include "box.h"
#include "cheats.h"
#include "projectile.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "../Utils/sdl_utils.h"

int stepCount = 0;
int deathCounter = 0;
char playerName[1000];
bool fullBrightOn = false;
bool isLevelOne = false;
bool isLevelTwo = false;
bool isLevelThree = false;
bool isLevelFour = false;
bool panic = false;
static Sound deathSound;
static Sound torchInteractSound;
static Sound getKeySound;
static Sound TorchInteract;
static Sound blockedDoorUnlocked;

struct Player player = {16, 1, false};

// Sound Initialization

void playerSoundInitialization()
{
    init_sound("Assets/Sounds/DeathSound.wav", &deathSound);
    init_sound("Assets/Sounds/TorchInteract.wav", &torchInteractSound);
    init_sound("Assets/Sounds/GetKeySound.wav", &getKeySound);
    init_sound("Assets/Sounds/TorchInteract.wav", &TorchInteract);
    init_sound("Assets/Sounds/blockedDoorUnlocked.wav", &blockedDoorUnlocked);
    if (activated == true)
    {
        playSound(&blockedDoorUnlocked);
    }
    stopSound(&blockedDoorUnlocked);
}

// Trent & Xavier
void movePlayer(char dir)
{

    switch (dir)
    {
    case 'W':
    case 'w':
        if (box1.beingGrabbed == true)
        {

            if (isTileWalkable(map[player.position_x - 1][player.position_y]) && isTileWalkable(map[box1.position_x - 1][box1.position_y]))
            {
                if ((map[player.position_x][player.position_y] == 'D') && (getKey == true))
                {
                    endLevel();
                }
                player.position_x--;
                stepCounter();
            }
        }
        else if (box1.beingGrabbed == false)
        {
            if (isTileWalkable(map[player.position_x - 1][player.position_y]))
            {

                if ((map[player.position_x][player.position_y] == 'D') && (getKey == true))
                {
                    endLevel();
                }
                player.position_x--;
                stepCounter();
            }
        }
        break;

    case 'A':
    case 'a':
        if (box1.beingGrabbed == true)
        {
            if (isTileWalkable(map[player.position_x][player.position_y - 1]) && isTileWalkable(map[box1.position_x][box1.position_y - 1]))
            {

                if ((map[player.position_x][player.position_y] == 'D') && (getKey == true))
                {
                    endLevel();
                }
                player.position_y--;
                stepCounter();
            }
        }
        else if (box1.beingGrabbed == false)
        {
            if (isTileWalkable(map[player.position_x][player.position_y - 1]))
            {

                if ((map[player.position_x][player.position_y] == 'D') && (getKey == true))
                {
                    endLevel();
                }
                player.position_y--;
                stepCounter();
            }
        }
        break;

    case 'S':
    case 's':
        if (box1.beingGrabbed == true)
        {
            if (isTileWalkable(map[player.position_x + 1][player.position_y]) && isTileWalkable(map[box1.position_x + 1][box1.position_y]))
            {

                if ((map[player.position_x][player.position_y] == 'D') && (getKey == true))
                {
                    endLevel();
                }
                player.position_x++;
                stepCounter();
            }
        }
        else if (box1.beingGrabbed == false)
        {
            if (isTileWalkable(map[player.position_x + 1][player.position_y]))
            {

                if ((map[player.position_x][player.position_y] == 'D') && (getKey == true))
                {
                    endLevel();
                }
                player.position_x++;
                stepCounter();
            }
        }
        break;

    case 'D':
    case 'd':
        if (box1.beingGrabbed == true)
        {
            if (isTileWalkable(map[player.position_x][player.position_y + 1]) && isTileWalkable(map[box1.position_x][box1.position_y + 1]))
            {

                if ((map[player.position_x][player.position_y] == 'D') && (getKey = true))
                {
                    endLevel();
                }
                player.position_y++;
                stepCounter();
            }
        }
        else if (box1.beingGrabbed == false)
        {
            if (isTileWalkable(map[player.position_x][player.position_y + 1]))
            {

                if ((map[player.position_x][player.position_y] == 'D') && (getKey == true))
                {
                    endLevel();
                }
                player.position_y++;
                stepCounter();
            }
        }
        break;
    case 'P':
    case 'p':
        pauseGame();
        break;
    case 'E':
    case 'e':
        grabBox();

        break;
    case 'T':
    case 't':
        if (WIP.collected == true)
        {
            throwProjectile();
        }

        break;
        // cheats
        // activate full brigtness cheat
    case 'F':
    case 'f':
        fullBrightOn = true;
        break;

        // deactivate full brightness cheat
    case 'G':
    case 'g':
        fullBrightOn = false;
        break;
        // give key
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
        // give projectile
        WIP.collected = true;
        break;
    }
}

// Xavier
char readUserInput()
{
    char input;
    scanf("%c", &input);
    return input;
}

// Xavier & Trent
bool isTileWalkable(char t)
{
    return (t != 'W' && t != 'H');
}

// Xaiver & Trent
int stepCounter(void)
{
    stepCount += 1;
    projDim();
    if (torchLevel > 0)
    {
        torchDim();
    }
    return stepCount;
}

// Xavier
void playerDeath()
{
    playSound(&deathSound);
    resetPlayer();
    boxPositioning();
    playerDeathCounter();
}

// Trent
void checkInteraction()
{
    printf("You have walked %d steps\n", stepCount);
    switch (map[player.position_x][player.position_y])
    {
    case 'T':
        box1.beingGrabbed = false;
        playerDeath();
        break;

    case 'K':
        collectKey();
        playSound(&getKeySound);
        break;

    case 'D':
        if (getKey == true)
        {
            endLevel();
        }
        break;

    case 'L':
        torchInteract();
        playSound(&TorchInteract);
        break;
    }
}

// Pedro/Trent
int playerDeathCounter()
{
    deathCounter++;
    if (torchLevel > 0)
    {
        torchDim();
    }
    return deathCounter;
}

// Pedro
void choosePlayerName()
{
    printf("\n\nWhat is the name of your character?\nInsert: ");
    scanf("%s", playerName);
    printf("\n\n\n\n");
    startGame();
}

// Pedro
void sanityDisplay()
{
    printf("\n");
    printf("Sanity Meter: ");
    if (torchLevel > 4)
    {
        printf("[🧠🧠🧠🧠🧠]");
    }
    if (torchLevel == 4)
    {
        printf("[🧠🧠🧠🧠⬛]");
    }
    if (torchLevel == 3)
    {
        printf("[🧠🧠🧠⬛⬛]");
    }
    if (torchLevel == 2)
    {
        printf("[🧠🧠⬛⬛⬛]");
    }
    if (torchLevel == 1)
    {
        printf("[🧠⬛⬛⬛⬛]");
    }
    if (torchLevel == 0)
    {
        printf("[⬛⬛⬛⬛⬛]");
    }
}

// Pedro
void printInventory()
{
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

// Xavier
void resetPlayer()
{

    box1.beingGrabbed = false;
    box1.position_x = 8;
    box1.position_y = 10;
    if (isLevelOne == true)
    {
        map[1][1] = 'K';
    }
    if (isLevelFour == true)
    {
        map[8][8] = 'K';
    }
    player.position_x = 16;
    player.position_y = 1;
    stepCount = 0;
    torchLevel = 15;
    getKey = false;
    WIP.collected = false;
    WIP.projectileLevel = 15;
    activated = false;
    panic = false;
}

int player_get_row(void)
{
    return player.position_x;
}

int player_get_col(void)
{
    return player.position_y;
}
