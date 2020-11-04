#include "common.h"

SDL_Texture *load_texture(char *path)
{
    SDL_Surface *surface = IMG_Load(path);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void load_default_images(AssetImages *pImages)
{
    pImages->logo = load_texture("../res/pokemon.png");
    pImages->font = load_texture("../res/font-v3-4.png");
    pImages->front[0] = load_texture("../res/espeon-front.png");
}

AssetManager *init_asset_manager()
{
    AssetManager *asset_manager = malloc(sizeof(AssetManager));
    asset_manager->images = malloc(sizeof(AssetImages));
    asset_manager->sounds = malloc(sizeof(AssetSounds));

    load_default_images(asset_manager->images);
    
    return asset_manager;
}
