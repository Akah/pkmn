#include "init.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

extern SDL_Window* createWindow()
{
    SDL_Window* window = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        printf( "SDL could not be initialised! SDL_Error: %s\n", SDL_GetError());

    window = SDL_CreateWindow("SDL Tutorial",
                              SDL_WINDOWPOS_UNDEFINED, 
                              SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);

    if( window == NULL )
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError());

    if( !( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ))
        printf( "SDL_image could not be initialised! SDL_image Error: %s\n", IMG_GetError());

    if(TTF_Init() < 0)
        printf( "SDL_ttf could not be initialised! SDL_ttf Error: %s\n", TTF_GetError());

    return window;
}