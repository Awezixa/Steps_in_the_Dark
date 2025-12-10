#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "utils/sdl_utils.h"
#include "map.h"
#include "player.h"
#include "box.h"
#include "cheats.h"
#include "doorAndKeys.h"
#include "menu.h"
#include "projectile.h"
#include "torch.h"
#include "gamestate.h"

// Definitions
#define APP_NAME "Steps in the Dark"

#define TEXTURE_WIDTH 32
#define TEXTURE_HEIGHT 32

// map is 18x18. Each tile 32x32 in size
#define APP_WIDTH 18 * TEXTURE_WIDTH
#define APP_HEIGHT 18 * TEXTURE_HEIGHT

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

static Sound menuMusic;
static Sound playerWalk;
static Sound blockedDoorUnlocked;

// functions to render things
void renderGame(void);
void renderMainMenu(void);
void renderGameFinished(void);
void renderInitialScreen(void);
void renderPauseScreen(void);
void renderLevelSelect(void);
void renderCredits(void);
void renderOptions(void);
void renderTiles(void);
void renderBox(void);


// Other variables
int opSelected = -1;

int main(void)
{

    // Initialize SDL Systems.
    window = sdl_initialize_window(APP_NAME, APP_MAINMENU_WIDTH, APP_MAINMENU_HEIGHT);
    renderer = sdl_initialize_renderer(window);
    sdl_initialize_audio();

    // intialize the textures
    floorTexture = sdl_load_texture(renderer, "Assets/floor.png");
    wallTexture = sdl_load_texture(renderer, "Assets/gamewall.png");
    keyTexture = sdl_load_texture(renderer, "Assets/STIDKey.png");
    trapTexture = sdl_load_texture(renderer, "Assets/gamewoodtilecracked.png");
    playerTexture = sdl_load_texture(renderer, "Assets/character.png");
    boxTexture = sdl_load_texture(renderer, "Assets/STIDBox.png");
    pressurePlateTexture = sdl_load_texture(renderer, "Assets/STIDPressurePlate.png");
    mistTexture = sdl_load_texture(renderer, "Assets/mist.png");
    doorTexture = sdl_load_texture(renderer, "Assets/STIDExitDoor.png");
    blockedDoorTexture = sdl_load_texture(renderer, "Assets/STIDBlockedDoor.png");
    torchTexture = sdl_load_texture(renderer, "Assets/tiletorchpixel.png");
    bgTexture = sdl_load_texture(renderer, "Assets/mist.png");
    logoTexture = sdl_load_texture(renderer, "Assets/logoprototype.png");
    
    // Sound Initialization
    init_sound("Assets/Sounds/MenuMusic.wav", &menuMusic);
    init_sound("Assets/Sounds/PlayerWalk.wav", &playerWalk);
    init_sound("Assets/Sounds/blockedDoorUnlocked.wav", &blockedDoorUnlocked);
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
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_SPACE || event.key.key == SDLK_KP_ENTER)
            {
                if (gameState() == INITIAL_STATE)
                {
                    setGameState(MAIN_MENU);
                    playSound(&menuMusic);
                }
                if (gameState() == MAIN_MENU)
                {
                    // play
                    if (opSelected == 0)
                    {
                        // setGameState(LEVEL_SELECT);
                        playerSoundInitialization();
                        setGameState(INGAME);
                        loadMap("Maps/map1.txt");
                        SDL_SetWindowSize(window, APP_HEIGHT, APP_WIDTH);
                        SDL_SetWindowTitle(window, "Steps in the Dark - In Game");
                    }
                    // options
                    else if (opSelected == 1)
                    {
                    }
                    // credits
                    else if (opSelected == 2)
                    {
                    }
                    // exit
                    else if (opSelected == 3)
                    {
                        running = 0;
                    }
                }
                if (gameState() == LEVEL_SELECT)
                {
                    if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_1)
                    {
                        setGameState(INGAME);
                        loadMap("Environment/Maps/map1.txt");
                        SDL_SetWindowSize(window, APP_HEIGHT, APP_WIDTH);
                        SDL_SetWindowTitle(window, "Steps in the Dark - In Game");
                    }
                    if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_2)
                    {
                        setGameState(INGAME);
                        loadMap("Environment/Maps/map2.txt");
                        SDL_SetWindowSize(window, APP_HEIGHT, APP_WIDTH);
                        SDL_SetWindowTitle(window, "Steps in the Dark - In Game");
                    }
                    if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_3)
                    {
                        setGameState(INGAME);
                        loadMap("Environment/Maps/map3.txt");
                        SDL_SetWindowSize(window, APP_HEIGHT, APP_WIDTH);
                        SDL_SetWindowTitle(window, "Steps in the Dark - In Game");
                    }
                    if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_4)
                    {
                        setGameState(INGAME);
                        loadMap("Environment/Maps/map4.txt");
                        SDL_SetWindowSize(window, APP_HEIGHT, APP_WIDTH);
                        SDL_SetWindowTitle(window, "Steps in the Dark - In Game");
                    }
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

            if (gameState() == INGAME)
            {
                checkInteraction();
                if (torchLevel == 0) {
                    playerDeath();
                }
                // Player movement
                if (event.type == SDL_EVENT_KEY_DOWN)
                {
                    if (event.key.key == SDLK_W)
                        movePlayer('W');
                        playSound(&playerWalk);
                    if (event.key.key == SDLK_A)
                        movePlayer('A');
                        playSound(&playerWalk);
                    if (event.key.key == SDLK_S)
                        movePlayer('S');
                        playSound(&playerWalk);
                    if (event.key.key == SDLK_D)
                        movePlayer('D');
                        playSound(&playerWalk);
                    if (event.key.key == SDLK_P)
                    {
                        setGameState(PAUSED);
                        opSelected = 4;
                    }
                }
                
                
                
                // if (map[player.position_x][player.position_y] == 'T'){
                //     playerTexture = sdl_load_texture(renderer, "Assets/gamewoodtilebroken.png");

                // }
                // Temporary Sound Fix
            }
        }
        if (gameState() == INITIAL_STATE)
            renderInitialScreen();
        if (gameState() == MAIN_MENU)
            renderMainMenu();
        if (gameState() == LEVEL_SELECT)
        {
            renderLevelSelect();
        }
        if (gameState() == INGAME)
            renderGame();
        if (gameState() == PAUSED)
        {
            renderPauseScreen();
            if(event.type == SDL_EVENT_KEY_DOWN){
                //continue
                if (opSelected == 0 && event.key.key == SDLK_SPACE)
                {
                    setGameState(INGAME);
                    loadMap("Maps/map1.txt");
                    SDL_SetWindowSize(window, APP_HEIGHT, APP_WIDTH);
                    SDL_SetWindowTitle(window, "Steps in the Dark - In Game");
                }
                // level select
                else if (opSelected == 1 && event.key.key == SDLK_SPACE)
                {
                    setGameState(LEVEL_SELECT);
                }
                // credits
                else if (opSelected == 2 && event.key.key == SDLK_SPACE)
                {
                }
                // exit
                else if (opSelected == 3 && event.key.key == SDLK_SPACE)
                {
                    running = 0;
                }
            }
            
        }

        // if (gameState() == FINISHED)
        // renderGameFinished();

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

void renderInitialScreen(void)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_FRect logoRect = {200, 100, 591, 198};
    SDL_RenderTexture(renderer, logoTexture, NULL, &logoRect);

    showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 25)) / 2), 475, "<< PRESS SPACE TO START>>", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});
    SDL_RenderPresent(renderer);
}

void renderMainMenu(void)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_FRect logoRect = {200, 100, 591, 198};
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

    showText(renderer, 300, 150, "1. Level 1    2. Level 2      3. Level 3      4. Level 4", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});
    SDL_RenderPresent(renderer);
}

void renderMap()
{
    for (int x = 0; x < MAP_ROWS; x++)
    {
        for (int y = 0; y < MAP_COLS; y++)
        {

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
          if(((x == player.position_x + 1 && y == player.position_y)
                || (x == player.position_x - 1 && y == player.position_y)
                || (x == player.position_x && y == player.position_y + 1)
                || (x == player.position_x && y == player.position_y - 1)
                || (x == player.position_x - 2 && y == player.position_y)
                || (x == player.position_x + 2 && y == player.position_y)
                || (x == player.position_x && y == player.position_y - 2)
                || (x == player.position_x && y == player.position_y + 2)
                || (x == player.position_x + 1 && y == player.position_y + 1)
                || (x == player.position_x - 1 && y == player.position_y + 1)
                || (x == player.position_x + 1 && y == player.position_y - 1)
                || (x == player.position_x - 1 && y == player.position_y - 1)) 
                && (torchLevel > 10)){

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
                }else{
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
                // Medium Radius
                if (((x == player.position_x + 1 && y == player.position_y)
                || (x == player.position_x - 1 && y == player.position_y)
                || (x == player.position_x && y == player.position_y + 1)
                || (x == player.position_x && y == player.position_y - 1))
                && (torchLevel <= 10)) {
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
                }else{
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
               // Minimum Radius
            if (torchLevel <= 5){

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
            if ((map[x][y] == 'L')
                || (x > 0 && map[x - 1][y] == 'L')
            || (x < MAP_ROWS - 1 && map[x + 1][y] == 'L')
            || (y > 0 && map[x][y - 1] == 'L')
            || (y < MAP_COLS - 1 && map[x][y + 1] == 'L'))
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
                }else{
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
            }
                    
        }
    }
}



void renderPlayer()
{
    // Render the wizard at the player's position
    SDL_FRect explorer_rect = {TEXTURE_WIDTH * player_get_col(), TEXTURE_WIDTH * player_get_row(), TEXTURE_WIDTH, TEXTURE_HEIGHT};
    SDL_RenderTexture(renderer, playerTexture, NULL, &explorer_rect);
}

void renderBox()
{
    // Render the wizard at the boxes position
    SDL_FRect explorer_rect = {TEXTURE_WIDTH * box_get_col(), TEXTURE_WIDTH * box_get_row(), TEXTURE_WIDTH, TEXTURE_HEIGHT};
    SDL_RenderTexture(renderer, boxTexture, NULL, &explorer_rect);
}

void renderGame(void)
{
    const int charsize = SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE;

    /* as you can see from this, rendering draws over whatever was drawn before it. */
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); /* black, full alpha */
    SDL_RenderClear(renderer);                                   /* start with a blank canvas. */

    renderMap();
    renderPlayer();

    showText(renderer, 100, 0, "Steps in the Dark", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});
    SDL_RenderDebugTextFormat(renderer, (float)((APP_WIDTH - (charsize * 46)) / 2), APP_HEIGHT - charsize, "(This program has been running for %" SDL_PRIu64 " seconds.)", SDL_GetTicks() / 1000);

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
        showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 15)) / 2), 200, "-> EXIT", (SDL_Color){255, 255, 0, SDL_ALPHA_OPAQUE});
    else
        showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 15)) / 2), 200, "   EXIT", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});

    showText(renderer, (float)((APP_MAINMENU_WIDTH - (SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 34)) / 2), 475, "<< PRESS SPACE TO SELECT OPTION >>", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});
    SDL_RenderPresent(renderer);
}

