#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "sdl_utils.h"
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

// map is 16x16. Each tile 32x32 in size
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

// functions to render things
void renderGame(void);
void renderMainMenu(void);
void renderGameFinished(void);
void renderInitialScreen(void);

int main(void)
{
    // Initialize SDL Systems.
    window = sdl_initialize_window(APP_NAME, APP_MAINMENU_WIDTH, APP_MAINMENU_HEIGHT);
    renderer = sdl_initialize_renderer(window);
    sdl_initialize_audio();

    // intialize the textures
    floorTexture = sdl_load_texture(renderer, "Assets/floor.png");
    keyTexture = sdl_load_texture(renderer, "Assets/STIDKey.png");
    boxTexture = sdl_load_texture(renderer, "Assets/STIDBox.png");

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
            if (event.type == SDL_EVENT_KEY_DOWN)
            {
                if (event.key.key == SDLK_SPACE)
                {
                    setGameState(MAIN_MENU);
                }
            }

            if (gameState() == MAIN_MENU)
            {
                //play
                if (event.key.key == SDLK_1)
                    setGameState(INGAME);
                //options
                if (event.key.key == SDLK_2)
                    
                //credits
                if (event.key.key == SDLK_3)

                //exit
                if (event.key.key == SDLK_4){
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                    SDL_RenderClear(renderer);
                    showText(renderer, 300, 150, "See you next Time!", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});
                    SDL_RenderPresent(renderer);
                    running = 0;
                }
                    
            }
        }

        if (gameState() == INITIAL_STATE)
            renderInitialScreen();
        else if (gameState() == MAIN_MENU)
            renderMainMenu();
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

void renderInitialScreen(void)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    showText(renderer, 300, 150, "Press SpaceBar to Start!", (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});
    SDL_RenderPresent(renderer);
}

void renderMainMenu()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    showText(renderer, 100, 300,
             //  ".▄▄ · ▄▄▄▄▄▄▄▄ . ▄▄▄·.▄▄ ·     ▪   ▐ ▄     ▄▄▄▄▄ ▄ .▄▄▄▄ .    ·▄▄▄▄   ▄▄▄· ▄▄▄  ▄ •▄ "
             //  "▐█ ▀. •██  ▀▄.▀·▐█ ▄█▐█ ▀.     ██ •█▌▐█    •██  ██▪▐█▀▄.▀·    ██▪ ██ ▐█ ▀█ ▀▄ █·█▌▄▌▪"
             //  "▄▀▀▀█▄ ▐█.▪▐▀▀▪▄ ██▀·▄▀▀▀█▄    ▐█·▐█▐▐▌     ▐█.▪██▀▐█▐▀▀▪▄    ▐█· ▐█▌▄█▀▀█ ▐▀▀▄ ▐▀▀▄·"
             //  "▐█▄▪▐█ ▐█▌·▐█▄▄▌▐█▪·•▐█▄▪▐█    ▐█▌██▐█▌     ▐█▌·██▌▐▀▐█▄▄▌    ██. ██ ▐█ ▪▐▌▐█•█▌▐█.█▌"
             //  " ▀▀▀▀  ▀▀▀  ▀▀▀ .▀    ▀▀▀▀     ▀▀▀▀▀ █▪     ▀▀▀ ▀▀▀ · ▀▀▀     ▀▀▀▀▀•  ▀  ▀ .▀  ▀·▀  ▀"
             "1. Start Game || 2. Controls || 3. Credits || 4. Exit Select Option: ",
             (SDL_Color){255, 255, 255, SDL_ALPHA_OPAQUE});
    SDL_RenderPresent(renderer);
}