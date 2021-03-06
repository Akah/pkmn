#include "../utils.h"
#include "asset_manager.h"

SDL_Texture* load_texture(char *source, SDL_Palette* palette)
{
    SDL_Surface *surface = IMG_Load(source);
    char debug[1024];
    if (surface == NULL)
	sprintf(debug, "SDL_Error: %s", IMG_GetError());
    else
        sprintf(debug, "Loading file: %s", source);
    _utils_debug(debug);
    if (palette != NULL)
	surface->format->palette = palette;
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void load_default_images(AssetImages *images)
{
    images->logo = load_texture("../res/images/pokemon.png", NULL);
    images->font = load_texture("../res/images/font-v3-6.png", NULL);
    images->front[0] = load_texture("../res/images/espeon-front.png", NULL);
    images->front[1] = load_texture("../res/images/umbreon-front.png", NULL);
    images->back[0] = load_texture("../res/images/espeon-back.png", NULL);
    images->back[1] = load_texture("../res/images/umbreon-back.png", NULL);
    images->player_status = load_texture("../res/images/player_status.png", NULL);
    images->enemy_status = load_texture("../res/images/enemy_status.png", NULL);
}

AssetManager *init_asset_manager()
{
    AssetManager *asset_manager = malloc(sizeof(AssetManager));
    asset_manager->images = malloc(sizeof(AssetImages));
    asset_manager->sounds = malloc(sizeof(AssetSounds));

    load_default_images(asset_manager->images);

    _utils_debug("Initialised asset manager");

    return asset_manager;
}
