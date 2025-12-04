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

//Definitions
#define APP_NAME "Steps in the Dark"

#define TEXTURE_WIDTH 32
#define TEXTURE_HEIGHT 32

//map is 16x16. Each tile 32x32 in size
#define APP_WIDTH 16 * TEXTURE_WIDTH
#define APP_HEIGHT 16 * TEXTURE_HEIGHT

#define APP_MAINMENU_WIDTH 400
#define APP_MAINMENU_HEIGHT 100

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
//all image assets we will have
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

//functions to render things
void renderGame(void);
void renderMainMenu(void);
void renderGameFinished(void);


int main(void){
    // Initialize SDL Systems.
    window = sdl_initialize_window(APP_NAME, APP_MAINMENU_WIDTH, APP_MAINMENU_HEIGHT);
    renderer = sdl_initialize_renderer(window);

    //intialize the textures
    floorTexture = sdl_load_texture(renderer, "Assets/.png");
    keyTexture = sdl_load_texture(renderer, "Assets/STIDKey.png");
    boxTexture = sdl_load_texture(renderer, "Assets/STIDBox.png");

    //Game loop
    int running = 1;
    const Uint32 FRAME_MS = 16; // ~60 FPS
    while (running)
    {
        //main game code
    }
    


    return 0;
}





