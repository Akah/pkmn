#include "common.h"

SDL_Texture *load_texture(SDL_Renderer *pRenderer, char *path);

void load_default_images(SDL_Renderer *pRenderer, AssetImages *pImages);

AssetManager *init_asset_manager(SDL_Renderer *pRenderer);

