#include "common.h"

SDL_Texture *load_texture(SDL_Renderer *pRenderer, char *path)
{
    SDL_Surface *surface = IMG_Load(path);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(pRenderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void load_default_images(SDL_Renderer *pRenderer, AssetImages *pImages)
{
    pImages->logo = load_texture(pRenderer, "../res/pokemon.png");
    pImages->font = load_texture(pRenderer, "../res/font-v3-4.png");
    pImages->front[0] = load_texture(pRenderer, "../res/espeon-front.png");
}

AssetManager *init_asset_manager(SDL_Renderer *pRenderer)
{
    AssetManager *asset_manager = malloc(sizeof(AssetManager));
    asset_manager->images = malloc(sizeof(AssetImages));
    asset_manager->sounds = malloc(sizeof(AssetSounds));

    load_default_images(pRenderer, asset_manager->images);
    
    return asset_manager;
}
