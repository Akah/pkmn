#include "init.h"

SDL_Window* createWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
	printf("SDL_Init error: %s\n", SDL_GetError());
    }

    SDL_Window* window =
	SDL_CreateWindow(SCREEN_TITLE,
			 SDL_WINDOWPOS_UNDEFINED,
			 SDL_WINDOWPOS_UNDEFINED,
			 SCREEN_WIDTH,
			 SCREEN_HEIGHT,
			 SDL_WINDOW_SHOWN);
    if (window == NULL) {
	printf("Window error: %s\n", SDL_GetError());
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
	printf("SDL_image error: %s\n", IMG_GetError());
    }

    return window;
}
