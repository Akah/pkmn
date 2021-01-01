#include <SDL2/SDL.h>
#include "../state.h"
#include "../utils/resources.h"

#ifndef ASSETS_H
#define ASSETS_H

// possibly change to surfaces... idk
typedef struct {
    SDL_Texture *front[12]; // player's party front and back
    SDL_Texture *back[6];   // enemy's party only ever front
    SDL_Texture *small[32]; // pokemon npcs on map / in party menu
    SDL_Texture *tilemap;   // all tiles ? or only tiles from current area
    SDL_Texture *font;
    SDL_Texture *logo;      // intro screen
    SDL_Texture *player_status;
    SDL_Texture *enemy_status;
} AssetImages;

// placeholder for sounds later;
typedef struct {
    int foo;
} AssetSounds;

typedef struct {
    Resource *images;
    AssetSounds *sounds;
} AssetManager;

#endif
