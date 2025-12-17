#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "Utils/sdl_utils.h"
#include "Source/map.h"
#include "Source/player.h"
#include "Source/box.h"
#include "Source/cheats.h"
#include "Source/doorAndKeys.h"
#include "Source/menu.h"
#include "Source/projectile.h"
#include "Source/torch.h"
#include "Source/gamestate.h"

// Definitions
#define APP_NAME "Steps in the Dark"

#define TEXTURE_WIDTH 32
#define TEXTURE_HEIGHT 32

// map is 18x18. Each tile 32x32 in size
#define APP_WIDTH 18 * TEXTURE_WIDTH
#define APP_HEIGHT 20 * TEXTURE_HEIGHT

#define APP_MAINMENU_WIDTH 1000
#define APP_MAINMENU_HEIGHT 400

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
// all image assets we will have
static SDL_Texture *floorTexture = NULL;
static SDL_Texture *wallTexture = NULL;
static SDL_Texture *trapTexture = NULL;
static SDL_Texture *pressurePlateTexture = NULL;
static SDL_Texture *playerTexture = NULL;
static SDL_Texture *WIPTexture = NULL;
static SDL_Texture *boxTexture = NULL;
static SDL_Texture *doorTexture = NULL;
static SDL_Texture *keyTexture = NULL;
static SDL_Texture *environmentalTorchTexture = NULL;
static SDL_Texture *mistTexture = NULL;
static SDL_Texture *blockedDoorTexture = NULL;
static SDL_Texture *torchTexture = NULL;
static SDL_Texture *bgTexture = NULL;
static SDL_Texture *logoTexture = NULL;
static SDL_Texture *projTexture = NULL;
static SDL_Texture *uniLogo = NULL;
static SDL_Texture *inventoryEmpty = NULL;
static SDL_Texture *inventoryKey = NULL;
static SDL_Texture *inventoryBomb = NULL;
static SDL_Texture *bombBroken = NULL;
static SDL_Texture *torchMeterFirstFull = NULL;
static SDL_Texture *torchMeterFirstEmpty = NULL;
static SDL_Texture *torchMeterMiddleFull = NULL;
static SDL_Texture *torchMeterMiddleEmpty = NULL;
static SDL_Texture *torchMeterEndFull = NULL;
static SDL_Texture *torchMeterEndEmpty = NULL;
static SDL_Texture *mistPanicTexture = NULL;
static SDL_Texture *sanityMeterFirstFull = NULL;
static SDL_Texture *sanityMeterMiddleFull = NULL;
static SDL_Texture *sanityMeterEndFull = NULL;
static SDL_Texture *playerPanicTexture = NULL;
static SDL_Texture *boxCarry = NULL;
static SDL_Texture *boxHighlight = NULL;
static SDL_Texture *levelSelectBg = NULL;

//Music intialization
static Sound menuMusic;
static Sound InGameMusic;
static Sound playerWalk;
static Sound blockedDoorUnlocked;
static Sound InGameMusic;
static Sound boxPush;
static Sound TorchInteract;

// Pedro's Frankenstein Contraption

// functions to render things
void renderGame(void);
void renderMainMenu(void);
void renderGameFinished(void);
void renderInitialScreen(void);
void renderPauseScreen(void);
void renderLevelSelect(void);
void renderCredits(void);
void renderTiles(void);
void renderBox(void);
void renderProjectile(void);
void renderOptions(void);
void renderProjRadius(void);
void renderUI(void);
void panicMode(void);

static void set_menu_presentation(int width, int height)
{
    SDL_SetRenderLogicalPresentation(renderer, width, height, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    SDL_SetWindowFullscreen(window, true);
}

static void set_nearest(SDL_Texture *t)
{
    if (t)
    SDL_SetTextureScaleMode(t, SDL_SCALEMODE_NEAREST);
}

// Other variables
int opSelected = -1;

int main(void)
{

    // Initialize SDL Systems.
    window = sdl_initialize_window(APP_NAME, APP_MAINMENU_WIDTH, APP_MAINMENU_HEIGHT);
    renderer = sdl_initialize_renderer(window);
    sdl_initialize_audio();
    set_menu_presentation(APP_MAINMENU_WIDTH, APP_MAINMENU_HEIGHT);

    // intialize the textures
    floorTexture = sdl_load_texture(renderer, "Assets/floor.png");
    wallTexture = sdl_load_texture(renderer, "Assets/gamewall.png");
    keyTexture = sdl_load_texture(renderer, "Assets/STIDKey.png");
    trapTexture = sdl_load_texture(renderer, "Assets/gamewoodtilecracked.png");
    playerTexture = sdl_load_texture(renderer, "Assets/character.png");
    boxTexture = sdl_load_texture(renderer, "Assets/STIDBox.png");
    if (activated == true)
    {
        pressurePlateTexture = sdl_load_texture(renderer, "Assets/STIDPressurePlateActivated.png");
    }
    else
    {
        pressurePlateTexture = sdl_load_texture(renderer, "Assets/STIDPressurePlate.png");
    }

    mistTexture = sdl_load_texture(renderer, "Assets/mist.png");
    doorTexture = sdl_load_texture(renderer, "Assets/STIDExitDoor.png");
    blockedDoorTexture = sdl_load_texture(renderer, "Assets/STIDBlockedDoor.png");
    torchTexture = sdl_load_texture(renderer, "Assets/tiletorchpixel.png");
    bgTexture = sdl_load_texture(renderer, "Assets/mist.png");
    logoTexture = sdl_load_texture(renderer, "Assets/logoprototype.png");
    projTexture = sdl_load_texture(renderer, "Assets/STIDFlashBombTile.png");
    uniLogo = sdl_load_texture(renderer, "Assets/IADElogo.jpg");
    inventoryEmpty = sdl_load_texture(renderer, "Assets/inventorybackground.png");
    inventoryBomb = sdl_load_texture(renderer, "Assets/inventorybomb.png");
    inventoryKey = sdl_load_texture(renderer, "Assets/inventorykey.png");
    bombBroken = sdl_load_texture(renderer, "Assets/STIDFlashBombBroken.png");
    torchMeterFirstFull = sdl_load_texture(renderer, "Assets/gamemeterONEfull.png");
    torchMeterFirstEmpty = sdl_load_texture(renderer, "Assets/gamemeterONEempty.png");
    torchMeterMiddleFull = sdl_load_texture(renderer, "Assets/gamemeterMIDDLEfull.png");
    torchMeterMiddleEmpty = sdl_load_texture(renderer, "Assets/gamemeterMIDDLEempty.png");
    torchMeterEndFull = sdl_load_texture(renderer, "Assets/gamemeterENDfull.png");
    torchMeterEndEmpty = sdl_load_texture(renderer, "Assets/gamemeterENDempty.png");
    mistPanicTexture = sdl_load_texture(renderer, "Assets/mistpanic.png");
    sanityMeterFirstFull = sdl_load_texture(renderer, "Assets/sanityONEfull.png");
    sanityMeterMiddleFull = sdl_load_texture(renderer, "Assets/sanityMIDDLEfull.png");
    sanityMeterEndFull = sdl_load_texture(renderer, "Assets/sanityENDfull.png");
    playerPanicTexture = sdl_load_texture(renderer, "Assets/characterpanic.png");
    boxCarry = sdl_load_texture(renderer, "Assets/STIDBoxCarry.png");
    boxHighlight = sdl_load_texture(renderer, "Assets/STIDBoxHighlight.png");
    levelSelectBg = sdl_load_texture(renderer, "Assets/LevelBackground.png");

    set_nearest(floorTexture);
    set_nearest(wallTexture);
    set_nearest(keyTexture);
    set_nearest(trapTexture);
    set_nearest(playerTexture);
    set_nearest(boxTexture);
    set_nearest(pressurePlateTexture);
    set_nearest(mistTexture);
    set_nearest(doorTexture);
    set_nearest(blockedDoorTexture);
    set_nearest(torchTexture);
    set_nearest(bgTexture);
    set_nearest(logoTexture);
    set_nearest(projTexture);
    set_nearest(uniLogo);
    set_nearest(inventoryEmpty);
    set_nearest(inventoryBomb);
    set_nearest(inventoryKey);
    set_nearest(bombBroken);
    set_nearest(torchMeterFirstFull);
    set_nearest(torchMeterFirstEmpty);
    set_nearest(torchMeterMiddleFull);
    set_nearest(torchMeterMiddleEmpty);
    set_nearest(torchMeterEndFull);
    set_nearest(torchMeterEndEmpty);
    set_nearest(mistPanicTexture);
    set_nearest(sanityMeterFirstFull);
    set_nearest(sanityMeterMiddleFull);
    set_nearest(sanityMeterEndFull);
    set_nearest(playerPanicTexture);
    set_nearest(boxCarry);
    set_nearest(boxHighlight);

    playerSoundInitialization();
    
    // Sound Initialization
    init_sound("Assets/Sounds/MenuMusic.wav", &menuMusic);
    init_sound("Assets/Sounds/PlayerWalk.wav", &playerWalk);
    init_sound("Assets/Sounds/blockedDoorUnlocked.wav", &blockedDoorUnlocked);
    init_sound("Assets/Sounds/InGameMusic.wav", &InGameMusic);
    init_sound("Assets/Sounds/boxPush.wav", &boxPush);
    init_sound("Assets/Sounds/TorchInteract.wav", &TorchInteract);

    // Game loop
    int running = 1;
    const Uint32 FRAME_MS = 16; // ~60 FPS
    while (running)
    {
        Uint32 frame_start = SDL_GetTicks();

        // Capture Events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = 0;
            }
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_SPACE)
            {
                if (gameState() == INITIAL_STATE)
                {
                    setGameState(MAIN_MENU);
                    playSound(&menuMusic);
                }
                if (gameState() == MAIN_MENU)
                {
                    playSound(&menuMusic);
                    // play
                    if (opSelected == 0)
                    {
                        setGameState(LEVEL_SELECT);
                        SDL_SetRenderLogicalPresentation(renderer, APP_MAINMENU_WIDTH, APP_MAINMENU_HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX);
                    }
                    // options
                    else if (opSelected == 1)
                    {
                        setGameState(OPTIONS);
                        SDL_SetRenderLogicalPresentation(renderer, APP_MAINMENU_WIDTH, APP_MAINMENU_HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX);
                    }
                    // credits
                    else if (opSelected == 2)
                    {
                        setGameState(CREDITS);
                        SDL_SetRenderLogicalPresentation(renderer, APP_MAINMENU_WIDTH, APP_MAINMENU_HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX);
                    }
                    // exit
                    else if (opSelected == 3)
                    {
                        running = 0;
                    }
                }
            }
            
            if (event.type == SDL_EVENT_KEY_DOWN && gameState() == LEVEL_SELECT)
            {
                if (event.key.key == SDLK_ESCAPE)
                {
                    setGameState(MAIN_MENU);
                }
                switch (event.key.key)
                {
                case SDLK_1:
                    setGameState(INGAME);
                    isLevelOne = true;
                    isLevelTwo = false;
                    isLevelThree = false;
                    isLevelFour = false;
                    resetPlayer();
                    boxPositioning();
                    stopSound(&menuMusic);
                    loadMap("Maps/map1.txt");
                    SDL_SetRenderLogicalPresentation(renderer, APP_WIDTH, APP_HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX);
                    SDL_SetWindowTitle(window, "Steps in the Dark - In Game");
                    break;
                case SDLK_2:
                    setGameState(INGAME);
                    isLevelTwo = true;
                    isLevelOne = false;
                    isLevelThree = false;
                    isLevelFour = false;
                    resetPlayer();
                    boxPositioning();
                    stopSound(&menuMusic);
                    loadMap("Maps/map2.txt");
                    SDL_SetRenderLogicalPresentation(renderer, APP_WIDTH, APP_HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX);
                    SDL_SetWindowTitle(window, "Steps in the Dark - In Game");
                    break;
                case SDLK_3:
                    setGameState(INGAME);
                    isLevelThree = true;
                    isLevelTwo = false;
                    isLevelOne = false;
                    isLevelFour = false;
                    resetPlayer();
                    boxPositioning();
                    stopSound(&menuMusic);
                    loadMap("Maps/map3.txt");
                    SDL_SetRenderLogicalPresentation(renderer, APP_WIDTH, APP_HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX);
                    SDL_SetWindowTitle(window, "Steps in the Dark - In Game");
                    break;
                case SDLK_4:
                    setGameState(INGAME);
                    isLevelFour = true;
                    isLevelTwo = false;
                    isLevelThree = false;
                    isLevelOne = false;
                    resetPlayer();
                    boxPositioning();
                    stopSound(&menuMusic);
                    loadMap("Maps/map4.txt");
                    SDL_SetRenderLogicalPresentation(renderer, APP_WIDTH, APP_HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX);
                    SDL_SetWindowTitle(window, "Steps in the Dark - In Game");
                    break;
                default:
                    break;
                }
            }

            // Menu movement
            if (event.type == SDL_EVENT_KEY_DOWN && (event.key.key == SDLK_UP || event.key.key == SDLK_W))
            {
                opSelected--;
                if (opSelected < 0)
                    opSelected = 3;
            }

            if (event.type == SDL_EVENT_KEY_DOWN && (event.key.key == SDLK_DOWN || event.key.key == SDLK_S))
            {
                opSelected++;
                if (opSelected > 3)
                    opSelected = 0;
            }

            // Paused loop
            if (event.type == SDL_EVENT_KEY_DOWN && gameState() == PAUSED)
            {
                SDL_SetRenderLogicalPresentation(renderer, APP_WIDTH, APP_HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX);
                if (opSelected == 0 && (event.key.key == SDLK_SPACE || event.key.key == SDLK_ESCAPE))
                {
                    setGameState(INGAME);
                    SDL_SetRenderLogicalPresentation(renderer, APP_WIDTH, APP_HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX);
                    SDL_SetWindowTitle(window, "Steps in the Dark - In Game");
                }
                // level select
                else if (opSelected == 1 && event.key.key == SDLK_SPACE)
                {
                    setGameState(LEVEL_SELECT);
                }
                // options
                else if (opSelected == 2 && event.key.key == SDLK_SPACE)
                {
                    setGameState(OPTIONS);
                }
                // exit
                else if (opSelected == 3 && event.key.key == SDLK_SPACE)
                {
                    setGameState(MAIN_MENU);
                    opSelected = -1;
                }
            }

            if (event.type == SDL_EVENT_KEY_DOWN &&
                event.key.key == SDLK_ESCAPE)
            {
                switch (gameState())
                {
                case CREDITS:
                case OPTIONS:
                case LEVEL_SELECT:
                    setGameState(MAIN_MENU);
                    break;

                case INGAME:
                    setGameState(PAUSED);
                    break;

                default:
                    break;
                }
            }

            if (event.type == SDL_EVENT_KEY_DOWN &&
                event.key.key == SDLK_SPACE &&
                gameState() == FINISHED)
            {
                SDL_SetRenderLogicalPresentation(renderer, APP_WIDTH, APP_HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX);
                setGameState(MAIN_MENU);
            }

            // Ingame loop
            if (gameState() == INGAME)
            {
                checkInteraction();
                panicMode();
                moveBox();
                plateActivated();
                if (activated == true)
                {
                    playSound(&blockedDoorUnlocked);
                }
                stopSound(&blockedDoorUnlocked);
                collectProjectile();

                if (torchLevel == 0)
                {
                    playerDeath();
                }

                // Player movement
                if (event.type == SDL_EVENT_KEY_DOWN)
                {
                    switch (event.key.key)
                    {
                    case SDLK_W:
                        movePlayer('W');
                        if (box1.beingGrabbed == true)
                        {
                            playSound(&boxPush);
                        }
                        else
                        {
                            playSound(&playerWalk);
                        }
                        WIP.direction = 3;
                        //}
                        break;
                    case SDLK_A:
                        movePlayer('A');
                        if (box1.beingGrabbed == true)
                        {
                            playSound(&boxPush);
                        }
                        else
                        {
                            playSound(&playerWalk);
                        }
                        WIP.direction = 0;
                        break;
                    case SDLK_S:
                        movePlayer('S');
                        if (box1.beingGrabbed == true)
                        {
                            playSound(&boxPush);
                        }
                        else
                        {
                            playSound(&playerWalk);
                        }
                        WIP.direction = 1;
                        break;
                    case SDLK_D:
                        movePlayer('D');
                        if (box1.beingGrabbed == true)
                        {
                            playSound(&boxPush);
                        }
                        else
                        {
                            playSound(&playerWalk);
                        }
                        WIP.direction = 2;
                        break;
                    case SDLK_E:
                        if (box1.beingGrabbed == true)
                        {
                            box1.beingGrabbed = false;
                        }
                        else
                        {
                            movePlayer('E');
                        }
                        break;
                    case SDLK_T:
                        movePlayer('T');
                        break;
                    case SDLK_P:
                        setGameState(PAUSED);
                        opSelected = 4;
                        break;
                        // cheats
                    case SDLK_K:
                        movePlayer('K');
                        break;
                        case SDLK_F:
                        movePlayer('F');
                        break;
                        case SDLK_G:
                        movePlayer('G');
                        break;
                        case SDLK_J:
                        movePlayer('J');
                        break;
                    default:
                        break;
                    }
                }

                // if (map[player.position_x][player.position_y] == 'T'){
                //     playerTexture = sdl_load_texture(renderer, "Assets/gamewoodtilebroken.png");

                // }
                // Temporary Sound Fix
            }
        }

        // Game states
        if (gameState() == INITIAL_STATE)
            renderInitialScreen();
        if (gameState() == MAIN_MENU)
            renderMainMenu();
            
        if (gameState() == LEVEL_SELECT)
            renderLevelSelect();
        if (gameState() == INGAME)
        {
            renderGame();
            stopSound(&menuMusic);
        }
        if (gameState() == PAUSED)
            renderPauseScreen();
        if (gameState() == CREDITS)
            renderCredits();
        if (gameState() == OPTIONS)
            renderOptions();
        if (gameState() == FINISHED)
            renderGameFinished();

        Uint32 elapsed = SDL_GetTicks() - frame_start;
        if (elapsed < FRAME_MS)
            SDL_Delay(FRAME_MS - elapsed);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

// functions

// Object renders
void renderPlayer()
{
    // Render the wizard at the player's position
    SDL_FRect explorer_rect = {TEXTURE_WIDTH * player_get_col(), TEXTURE_WIDTH * player_get_row(), TEXTURE_WIDTH, TEXTURE_HEIGHT};
    if (panic == true)
    {
        SDL_RenderTexture(renderer, playerPanicTexture, NULL, &explorer_rect);
    }
    else if (panic == false)
    {
        SDL_RenderTexture(renderer, playerTexture, NULL, &explorer_rect);
    }
}

void renderBox()
{
    // Render the wizard at the boxes position
    SDL_FRect box_rect = {TEXTURE_WIDTH * box_get_col(), TEXTURE_WIDTH * box_get_row(), TEXTURE_WIDTH, TEXTURE_HEIGHT};
    if (panic == true)
    {
        SDL_RenderTexture(renderer, mistPanicTexture, NULL, &box_rect);
    }
    else if (panic == false)
    {
        if (box1.beingGrabbed == true){
            SDL_RenderTexture(renderer, boxCarry, NULL, &box_rect);
        }else if (box1.beingGrabbed == false){
            if ((player.position_x + 1 == box1.position_x && player.position_y == box1.position_y) 
            || (player.position_x - 1 == box1.position_x && player.position_y == box1.position_y)
            || (player.position_y - 1 < MAP_ROWS && player.position_x == box1.position_x && player.position_y - 1 == box1.position_y)
            || (player.position_y + 1 < MAP_ROWS && player.position_x == box1.position_x && player.position_y + 1 == box1.position_y)){
                SDL_RenderTexture(renderer, boxHighlight, NULL, &box_rect);
            }else{
        SDL_RenderTexture(renderer, boxTexture, NULL, &box_rect);
        }
    }
}
}
void renderProjectile()
{
    // Render the wizard at the boxes position
    SDL_FRect proj_rect = {TEXTURE_WIDTH * proj_get_col(), TEXTURE_WIDTH * proj_get_row(), TEXTURE_WIDTH, TEXTURE_HEIGHT};
    if (WIP.collected == false)
    {
        if (thrown == false)
        {
            if (panic == true)
            {
                SDL_RenderTexture(renderer, mistPanicTexture, NULL, &proj_rect);
            }
            else if (panic == false)
            {
                SDL_RenderTexture(renderer, projTexture, NULL, &proj_rect);
            }
        }
        else if (thrown == true)
        {
            SDL_RenderTexture(renderer, bombBroken, NULL, &proj_rect);
        }
    }
    else
    {
        SDL_RenderTexture(renderer, floorTexture, NULL, &proj_rect);
    }
}

void renderProjRadius(void)
{
    for (int x = 0; x < MAP_ROWS; x++)
    {
        for (int y = 0; y < MAP_COLS; y++)
        {
            SDL_FRect dst_rect = {TEXTURE_WIDTH * y, TEXTURE_HEIGHT * x, TEXTURE_WIDTH, TEXTURE_HEIGHT};

            if (thrown == true && ((x == WIP.position_x + 1 && y == WIP.position_y) || (x == WIP.position_x - 1 && y == WIP.position_y) || (x == WIP.position_x && y == WIP.position_y + 1) || (x == WIP.position_x && y == WIP.position_y - 1) || (x == WIP.position_x + 1 && y == WIP.position_y + 1) || (x == WIP.position_x - 1 && y == WIP.position_y + 1) || (x == WIP.position_x + 1 && y == WIP.position_y - 1) || (x == WIP.position_x - 1 && y == WIP.position_y - 1) || (x == WIP.position_x + 2 && y == WIP.position_y) || (x == WIP.position_x - 2 && y == WIP.position_y) || (x == WIP.position_x && y == WIP.position_y + 2) || (x == WIP.position_x && y == WIP.position_y - 2)) && WIP.projectileLevel > 10)
            {
                if (map_get_tile(x, y) == TILE_FLOOR)
                {
                    SDL_RenderTexture(renderer, floorTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_WALL)
                {
                    SDL_RenderTexture(renderer, wallTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_DOOR)
                {
                    SDL_RenderTexture(renderer, doorTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_TRAP)
                {
                    SDL_RenderTexture(renderer, trapTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_PRESSUREPLATE)
                {
                    SDL_RenderTexture(renderer, pressurePlateTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_LOCKEDDOOR)
                {
                    SDL_RenderTexture(renderer, blockedDoorTexture, NULL, &dst_rect);
                }
                continue;
            }
            if (thrown == true && ((x == WIP.position_x + 1 && y == WIP.position_y) || (x == WIP.position_x - 1 && y == WIP.position_y) || (x == WIP.position_x && y == WIP.position_y + 1) || (x == WIP.position_x && y == WIP.position_y - 1)) && WIP.projectileLevel >= 6)
            {
                if (map_get_tile(x, y) == TILE_FLOOR)
                {
                    SDL_RenderTexture(renderer, floorTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_WALL)
                {
                    SDL_RenderTexture(renderer, wallTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_DOOR)
                {
                    SDL_RenderTexture(renderer, doorTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_TRAP)
                {
                    SDL_RenderTexture(renderer, trapTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_PRESSUREPLATE)
                {
                    SDL_RenderTexture(renderer, pressurePlateTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_LOCKEDDOOR)
                {
                    SDL_RenderTexture(renderer, blockedDoorTexture, NULL, &dst_rect);
                }
                continue;
            }
        }
    }
}
// Screen renders
void renderInitialScreen(void)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_FRect logoRect = {200, 100, 591, 198};
    SDL_RenderTexture(renderer, logoTexture, NULL, &logoRect);

    showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 25)) / 2), 500, "<< PRESS SPACE TO START>>", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});
    SDL_RenderPresent(renderer);
}

void renderMainMenu(void)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_FRect logoRect = {50, 100, 591, 198};
    SDL_RenderTexture(renderer, bgTexture, NULL, &logoRect);

    // Show Start Game Option
    if (opSelected == 0)
        showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 15)) / 2), 50, "-> PLAY", (SDL_Color){255, 255, 0, SDL_ALPHA_OPAQUE});
    else
        showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 15)) / 2), 50, "   PLAY", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});

    // Show Select Level Option
    if (opSelected == 1)
        showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 15)) / 2), 100, "-> OPTIONS", (SDL_Color){255, 255, 0, SDL_ALPHA_OPAQUE});
    else
        showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 15)) / 2), 100, "   OPTIONS", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});

    // Show Options Option
    if (opSelected == 2)
        showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 15)) / 2), 150, "-> CREDITS", (SDL_Color){255, 255, 0, SDL_ALPHA_OPAQUE});
    else
        showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 15)) / 2), 150, "   CREDITS", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});

    // Show Exit Option
    if (opSelected == 3)
        showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 15)) / 2), 200, "-> EXIT", (SDL_Color){255, 255, 0, SDL_ALPHA_OPAQUE});
    else
        showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 15)) / 2), 200, "   EXIT", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});

    showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 34)) / 2), 475, "<< PRESS SPACE TO SELECT OPTION >>", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});
    SDL_RenderPresent(renderer);
}

void renderLevelSelect(void)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_FRect logoRect = {0, 0, 1080, 1920};
    SDL_RenderTexture(renderer, levelSelectBg, NULL, &logoRect);
    showText(renderer, 300, 150, "1. Level 1    2. Level 2      3. Level 3      4. Level 4", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});
    SDL_RenderPresent(renderer);
}

void renderMap()
{
    for (int x = 0; x < MAP_ROWS; x++)
    {
        for (int y = 0; y < MAP_COLS; y++)
        {
            renderProjRadius();
            SDL_FRect dst_rect = {TEXTURE_WIDTH * y, TEXTURE_HEIGHT * x, TEXTURE_WIDTH, TEXTURE_HEIGHT};
            // Constant Texture

            if (map_get_tile(x, y) == TILE_KEY)
            {
                SDL_RenderTexture(renderer, keyTexture, NULL, &dst_rect);
            }

            if (map_get_tile(x, y) == TILE_TORCH)
            {
                SDL_RenderTexture(renderer, torchTexture, NULL, &dst_rect);
            }
            if (map_get_tile(x, y) == TILE_MIST)
            {
                SDL_RenderTexture(renderer, bgTexture, NULL, &dst_rect);
            }

            // Max Radius
            if (((x == player.position_x + 1 && y == player.position_y) || (x == player.position_x - 1 && y == player.position_y) || (x == player.position_x && y == player.position_y + 1) || (x == player.position_x && y == player.position_y - 1) || (x == player.position_x - 2 && y == player.position_y) || (x == player.position_x + 2 && y == player.position_y) || (x == player.position_x && y == player.position_y - 2) || (x == player.position_x && y == player.position_y + 2) || (x == player.position_x + 1 && y == player.position_y + 1) || (x == player.position_x - 1 && y == player.position_y + 1) || (x == player.position_x + 1 && y == player.position_y - 1) || (x == player.position_x - 1 && y == player.position_y - 1)) && (torchLevel > 10))
            {
                if (map_get_tile(x, y) == TILE_FLOOR)
                {
                    SDL_RenderTexture(renderer, floorTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_WALL)
                {
                    SDL_RenderTexture(renderer, wallTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_DOOR)
                {

                    SDL_RenderTexture(renderer, doorTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_TRAP)
                {

                    SDL_RenderTexture(renderer, trapTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_PRESSUREPLATE)
                {

                    SDL_RenderTexture(renderer, pressurePlateTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_LOCKEDDOOR)
                {
                    SDL_RenderTexture(renderer, blockedDoorTexture, NULL, &dst_rect);
                }

            } // Medium Range
            else if (((x == player.position_x + 1 && y == player.position_y) || (x == player.position_x - 1 && y == player.position_y) || (x == player.position_x && y == player.position_y + 1) || (x == player.position_x && y == player.position_y - 1)) && (torchLevel >= 6))
            {
                if (map_get_tile(x, y) == TILE_FLOOR)
                {
                    SDL_RenderTexture(renderer, floorTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_WALL)
                {
                    SDL_RenderTexture(renderer, wallTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_DOOR)
                {

                    SDL_RenderTexture(renderer, doorTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_TRAP)
                {

                    SDL_RenderTexture(renderer, trapTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_PRESSUREPLATE)
                {

                    SDL_RenderTexture(renderer, pressurePlateTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_LOCKEDDOOR)
                {
                    SDL_RenderTexture(renderer, blockedDoorTexture, NULL, &dst_rect);
                }
            }

            // Minimum Radius
            else if (torchLevel < 6)
            {
                if (map_get_tile(x, y) == TILE_FLOOR)
                {
                    SDL_RenderTexture(renderer, mistPanicTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_WALL)
                {
                    SDL_RenderTexture(renderer, mistPanicTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_DOOR)
                {
                    SDL_RenderTexture(renderer, mistPanicTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_TRAP)
                {
                    SDL_RenderTexture(renderer, mistPanicTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_PRESSUREPLATE)
                {
                    SDL_RenderTexture(renderer, mistPanicTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_LOCKEDDOOR)
                {
                    SDL_RenderTexture(renderer, mistPanicTexture, NULL, &dst_rect);
                }
            }
            else
            {
                if (map_get_tile(x, y) == TILE_FLOOR)
                {
                    SDL_RenderTexture(renderer, mistTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_WALL)
                {
                    SDL_RenderTexture(renderer, mistTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_DOOR)
                {
                    SDL_RenderTexture(renderer, mistTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_TRAP)
                {
                    SDL_RenderTexture(renderer, mistTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_PRESSUREPLATE)
                {
                    SDL_RenderTexture(renderer, mistTexture, NULL, &dst_rect);
                }
                if (map_get_tile(x, y) == TILE_LOCKEDDOOR)
                {
                    SDL_RenderTexture(renderer, mistTexture, NULL, &dst_rect);
                }
            }

            // Environmental Candle Lighting
            if (panic == false)
            {
                if ((map[x][y] == 'L') || (x > 0 && map[x - 1][y] == 'L') || (x < MAP_ROWS - 1 && map[x + 1][y] == 'L') || (y > 0 && map[x][y - 1] == 'L') || (y < MAP_COLS - 1 && map[x][y + 1] == 'L'))
                {
                    if (map_get_tile(x, y) == TILE_FLOOR)
                    {
                        SDL_RenderTexture(renderer, floorTexture, NULL, &dst_rect);
                    }
                    if (map_get_tile(x, y) == TILE_WALL)
                    {
                        SDL_RenderTexture(renderer, wallTexture, NULL, &dst_rect);
                    }
                    if (map_get_tile(x, y) == TILE_DOOR)
                    {
                        SDL_RenderTexture(renderer, doorTexture, NULL, &dst_rect);
                    }
                    if (map_get_tile(x, y) == TILE_TRAP)
                    {
                        SDL_RenderTexture(renderer, trapTexture, NULL, &dst_rect);
                    }
                    if (map_get_tile(x, y) == TILE_PRESSUREPLATE)
                    {
                        SDL_RenderTexture(renderer, pressurePlateTexture, NULL, &dst_rect);
                    }
                    if (map_get_tile(x, y) == TILE_LOCKEDDOOR)
                    {
                        SDL_RenderTexture(renderer, blockedDoorTexture, NULL, &dst_rect);
                    }
                }
            }
        }
    }
}

void renderGame(void)
{
    const int charsize = SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE;
    char steps[1000];
    snprintf(steps, sizeof(steps), "Steps: %d", stepCount);

    /* as you can see from this, rendering draws over whatever was drawn before it. */
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); /* black, full alpha */
    SDL_RenderClear(renderer);                                   /* start with a blank canvas. */

    renderMap();
    renderUI();
    renderProjectile();
    renderBox();
    renderPlayer();

    showText(renderer, 100, 0, "Steps in the Dark", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});
    showText(renderer, 300, 0, steps, (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});
    // SDL_RenderDebugTextFormat(renderer, (float)((APP_WIDTH - (charsize * 46)) / 2), APP_HEIGHT - charsize, "(This program has been running for %" SDL_PRIu64 " seconds.)", SDL_GetTicks() / 1000);

    SDL_RenderPresent(renderer); /* put it all on the screen! */
}

void renderPauseScreen(void)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    if (opSelected == 0)
        showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 15)) / 2), 50, "-> CONTINUE", (SDL_Color){255, 255, 0, SDL_ALPHA_OPAQUE});
    else
        showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 15)) / 2), 50, "   CONTINUE", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});

    // Show Select Level Option
    if (opSelected == 1)
        showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 15)) / 2), 100, "-> LEVEL SELECT", (SDL_Color){255, 255, 0, SDL_ALPHA_OPAQUE});
    else
        showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 15)) / 2), 100, "   LEVEL SELECT", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});

    // Show Options Option
    if (opSelected == 2)
        showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 15)) / 2), 150, "-> OPTIONS", (SDL_Color){255, 255, 0, SDL_ALPHA_OPAQUE});
    else
        showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 15)) / 2), 150, "   OPTIONS", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});

    // Show Exit Option
    if (opSelected == 3)
        showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 15)) / 2), 200, "-> MAIN MENU", (SDL_Color){255, 255, 0, SDL_ALPHA_OPAQUE});
    else
        showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 15)) / 2), 200, "   MAIN MENU", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});

    showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 34)) / 2), 475, "<< PRESS SPACE TO SELECT OPTION >>", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});
    SDL_RenderPresent(renderer);
}

void renderCredits()
{
    const int charsize = SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE;
    char credits[1000];

    snprintf(credits, sizeof(credits), "Credits: Xavier Dos Santos, Trent Kirby, Pedro Alao, Nelio  Codices");

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);



    showText(renderer, 20, 20, credits, (SDL_Color){255, 255, 255, 255});
    SDL_RenderPresent(renderer);
}

void renderOptions(void)
{
    char options[1000];

    snprintf(options, sizeof(options),
             "Options:"
             "\n"
             "Instructions:"
             "To escape the Castle and exit to the next level, you will navigate the darkness "
             "with the torch to find a key by solving puzzles with interactables in the level. "
             "Then take the key and open the door to the next dungeon room.\n"
             "\n"
             "Movement:\n"
             "W - Forward\n"
             "S - Back\n"
             "A - Left\n"
             "D - Right\n"
             "\n"
             "Cheats:\n"
             "C - Full Cheats\n"
             "K - Give Key\n"
             "F - Full Brightness\n"
             "G - Deactivate Brightness\n");

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    showText(renderer, 20, 20, options, (SDL_Color){255, 255, 255, 255});
    SDL_RenderPresent(renderer);
}

void renderUI()
{

    // INVENTORY UI
    SDL_FRect inv_rect1 = {0, TEXTURE_WIDTH * 18, TEXTURE_WIDTH, TEXTURE_HEIGHT};
    SDL_FRect inv_rect2 = {TEXTURE_HEIGHT, TEXTURE_WIDTH * 18, TEXTURE_WIDTH, TEXTURE_HEIGHT};

    if (WIP.collected == false)
    {
        SDL_RenderTexture(renderer, inventoryEmpty, NULL, &inv_rect1);
    }
    else
    {
        SDL_RenderTexture(renderer, inventoryBomb, NULL, &inv_rect1);
    }

    if (getKey == false)
    {
        SDL_RenderTexture(renderer, inventoryEmpty, NULL, &inv_rect2);
    }
    else
    {
        SDL_RenderTexture(renderer, inventoryKey, NULL, &inv_rect2);
    }

    // TORCH METER UI
    SDL_FRect torchm1 = {TEXTURE_HEIGHT * 8, TEXTURE_WIDTH * 18, TEXTURE_WIDTH, TEXTURE_HEIGHT};
    SDL_FRect torchm2 = {TEXTURE_HEIGHT * 9, TEXTURE_WIDTH * 18, TEXTURE_WIDTH, TEXTURE_HEIGHT};
    SDL_FRect torchm3 = {TEXTURE_HEIGHT * 10, TEXTURE_WIDTH * 18, TEXTURE_WIDTH, TEXTURE_HEIGHT};
    SDL_FRect torchm4 = {TEXTURE_HEIGHT * 11, TEXTURE_WIDTH * 18, TEXTURE_WIDTH, TEXTURE_HEIGHT};
    SDL_FRect torchm5 = {TEXTURE_HEIGHT * 12, TEXTURE_WIDTH * 18, TEXTURE_WIDTH, TEXTURE_HEIGHT};
    SDL_FRect torchm6 = {TEXTURE_HEIGHT * 13, TEXTURE_WIDTH * 18, TEXTURE_WIDTH, TEXTURE_HEIGHT};
    SDL_FRect torchm7 = {TEXTURE_HEIGHT * 14, TEXTURE_WIDTH * 18, TEXTURE_WIDTH, TEXTURE_HEIGHT};
    SDL_FRect torchm8 = {TEXTURE_HEIGHT * 15, TEXTURE_WIDTH * 18, TEXTURE_WIDTH, TEXTURE_HEIGHT};
    SDL_FRect torchm9 = {TEXTURE_HEIGHT * 16, TEXTURE_WIDTH * 18, TEXTURE_WIDTH, TEXTURE_HEIGHT};
    SDL_FRect torchm10 = {TEXTURE_HEIGHT * 17, TEXTURE_WIDTH * 18, TEXTURE_WIDTH, TEXTURE_HEIGHT};

    if (torchLevel >= 6)
    {
        SDL_RenderTexture(renderer, torchMeterFirstFull, NULL, &torchm1);
    }
    else
    {
        SDL_RenderTexture(renderer, torchMeterFirstEmpty, NULL, &torchm1);
    }

    if (torchLevel >= 7)
    {
        SDL_RenderTexture(renderer, torchMeterMiddleFull, NULL, &torchm2);
    }
    else
    {
        SDL_RenderTexture(renderer, torchMeterMiddleEmpty, NULL, &torchm2);
    }

    if (torchLevel >= 8)
    {
        SDL_RenderTexture(renderer, torchMeterMiddleFull, NULL, &torchm3);
    }
    else
    {
        SDL_RenderTexture(renderer, torchMeterMiddleEmpty, NULL, &torchm3);
    }

    if (torchLevel >= 9)
    {
        SDL_RenderTexture(renderer, torchMeterMiddleFull, NULL, &torchm4);
    }
    else
    {
        SDL_RenderTexture(renderer, torchMeterMiddleEmpty, NULL, &torchm4);
    }

    if (torchLevel >= 10)
    {
        SDL_RenderTexture(renderer, torchMeterMiddleFull, NULL, &torchm5);
    }
    else
    {
        SDL_RenderTexture(renderer, torchMeterMiddleEmpty, NULL, &torchm5);
    }

    if (torchLevel >= 11)
    {
        SDL_RenderTexture(renderer, torchMeterMiddleFull, NULL, &torchm6);
    }
    else
    {
        SDL_RenderTexture(renderer, torchMeterMiddleEmpty, NULL, &torchm6);
    }

    if (torchLevel >= 12)
    {
        SDL_RenderTexture(renderer, torchMeterMiddleFull, NULL, &torchm7);
    }
    else
    {
        SDL_RenderTexture(renderer, torchMeterMiddleEmpty, NULL, &torchm7);
    }

    if (torchLevel >= 13)
    {
        SDL_RenderTexture(renderer, torchMeterMiddleFull, NULL, &torchm8);
    }
    else
    {
        SDL_RenderTexture(renderer, torchMeterMiddleEmpty, NULL, &torchm8);
    }

    if (torchLevel >= 14)
    {
        SDL_RenderTexture(renderer, torchMeterMiddleFull, NULL, &torchm9);
    }
    else
    {
        SDL_RenderTexture(renderer, torchMeterMiddleEmpty, NULL, &torchm9);
    }

    if (torchLevel == 15)
    {
        SDL_RenderTexture(renderer, torchMeterEndFull, NULL, &torchm10);
    }
    else
    {
        SDL_RenderTexture(renderer, torchMeterEndEmpty, NULL, &torchm10);
    }

    // SANITY METER UI

    SDL_FRect sanitym1 = {TEXTURE_HEIGHT * 13, TEXTURE_WIDTH * 19, TEXTURE_WIDTH, TEXTURE_HEIGHT};
    SDL_FRect sanitym2 = {TEXTURE_HEIGHT * 14, TEXTURE_WIDTH * 19, TEXTURE_WIDTH, TEXTURE_HEIGHT};
    SDL_FRect sanitym3 = {TEXTURE_HEIGHT * 15, TEXTURE_WIDTH * 19, TEXTURE_WIDTH, TEXTURE_HEIGHT};
    SDL_FRect sanitym4 = {TEXTURE_HEIGHT * 16, TEXTURE_WIDTH * 19, TEXTURE_WIDTH, TEXTURE_HEIGHT};
    SDL_FRect sanitym5 = {TEXTURE_HEIGHT * 17, TEXTURE_WIDTH * 19, TEXTURE_WIDTH, TEXTURE_HEIGHT};

    if (torchLevel >= 1)
    {
        SDL_RenderTexture(renderer, sanityMeterFirstFull, NULL, &sanitym1);
    }
    else
    {
        SDL_RenderTexture(renderer, torchMeterFirstEmpty, NULL, &sanitym1);
    }

    if (torchLevel >= 2)
    {
        SDL_RenderTexture(renderer, sanityMeterMiddleFull, NULL, &sanitym2);
    }
    else
    {
        SDL_RenderTexture(renderer, torchMeterMiddleEmpty, NULL, &sanitym2);
    }

    if (torchLevel >= 3)
    {
        SDL_RenderTexture(renderer, sanityMeterMiddleFull, NULL, &sanitym3);
    }
    else
    {
        SDL_RenderTexture(renderer, torchMeterMiddleEmpty, NULL, &sanitym3);
    }

    if (torchLevel >= 4)
    {
        SDL_RenderTexture(renderer, sanityMeterMiddleFull, NULL, &sanitym4);
    }
    else
    {
        SDL_RenderTexture(renderer, torchMeterMiddleEmpty, NULL, &sanitym4);
    }

    if (torchLevel >= 5)
    {
        SDL_RenderTexture(renderer, sanityMeterEndFull, NULL, &sanitym5);
    }
    else
    {
        SDL_RenderTexture(renderer, torchMeterEndEmpty, NULL, &sanitym5);
    }
}

void panicMode()
{

    if (torchLevel < 6)
    {
        panic = true;
    }
    if (torchLevel > 6)
    {
        panic = false;
    }
     if (panic == true){
     playSound(&InGameMusic);
     }
     if (panic == false){
     stopSound(&InGameMusic);
     }
}

void renderGameFinished(void)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    showText(renderer, 100, 400, "You completed the Room. Onto the Next!!", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});
    showText(renderer, 300, 500, "Press Space to exit", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});
    SDL_RenderPresent(renderer);
}


void playerWalkSound(){
    if (box1.beingGrabbed == true)
        {
            playSound(&boxPush);
        }
    else{
            playSound(&playerWalk);
        }
}