#include "common.h"

SDL_Texture *load_texture(char *path)
{
    SDL_Surface *surface = IMG_Load(path);
    if (surface == NULL) {
	printf("SDL_ERROR: %s\n", IMG_GetError());
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void load_default_images(AssetImages *pImages)
{
    pImages->logo = load_texture("../res/images/pokemon.png");
    pImages->font = load_texture("../res/images/font-v3-4.png");
    pImages->front[0] = IMG_Load("../res/images/espeon-front.png");
    if (pImages->front[0] == NULL) {
	printf("front is null\n");
    }
    // TODO: extract out into function...
    //pImages->test = malloc((sizeof(unsigned char)*4)+(sizeof(unsigned char)*15));
    //pImages->test->pixels = malloc(sizeof(unsigned char)*19);
    // read_image_file(15, "../res/bins/test.bin", pImages->test);
}

AssetManager *init_asset_manager()
{
    AssetManager *asset_manager = malloc(sizeof(AssetManager));
    asset_manager->images = malloc(sizeof(AssetImages));
    asset_manager->sounds = malloc(sizeof(AssetSounds));

    load_default_images(asset_manager->images);
    
    return asset_manager;
}
