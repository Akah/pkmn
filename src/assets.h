#include <SDL2/SDL.h>

#ifndef ASSETS_H
#define ASSETS_H

// possibly change to surfaces... idk
typedef struct {
    SDL_Texture *front[12];
    SDL_Texture *back[6];
    SDL_Texture *small[32];
    SDL_Texture *tilemap;
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
