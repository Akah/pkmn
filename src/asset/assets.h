#include <SDL2/SDL.h>
#include "../state.h"

#ifndef ASSETS_H
#define ASSETS_H

// possibly change to surfaces... idk
typedef struct {
    SDL_Surface *front[12];
    SDL_Texture *back[6];
    SDL_Texture *small[32];
    SDL_Texture *tilemap;
    SDL_Texture *font;
    SDL_Texture *logo;
    Image *test;
} AssetImages;

// placeholder for sounds later;
typedef struct {
    int foo;
} AssetSounds;

typedef struct {
    AssetImages *images;
    AssetSounds *sounds;
} AssetManager;

#endif
