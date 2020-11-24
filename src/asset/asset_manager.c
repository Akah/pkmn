#include "common.h"

SDL_Texture *load_texture(char *path)
{
    SDL_Surface *surface = IMG_Load(path);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}


void read_image_file(int image_size, char *src, Image *test)
{
    FILE* file;
    const int file_size = image_size+4;
    unsigned char buffer[file_size];
    file = fopen(src, "rb");
    const char thing = fread(buffer, sizeof(unsigned char), file_size, file);
    for (int i=0; i<4; i++) {
	printf("%x ", buffer[i]);
	test->colours[i] = buffer[i];
    }
    printf("\n");
    for (int i=4; i<file_size; i++) {
	test->pixels[i] = buffer[i];
	printf("%x ", buffer[i]);
	if (i % 3 == 0) printf("\n");
    }   
}

void load_default_images(AssetImages *pImages)
{
    pImages->logo = load_texture("../res/pokemon.png");
    pImages->font = load_texture("../res/font-v3-4.png");
    pImages->front[0] = load_texture("../res/espeon-front.png");
    // TODO: extract out into function...
    pImages->test = malloc((sizeof(char)*4)+(sizeof(char)*15));
    pImages->test->pixels = malloc(sizeof(char)*15);
    read_image_file(15, "../res/bins/test.bin", pImages->test);
}

AssetManager *init_asset_manager()
{
    AssetManager *asset_manager = malloc(sizeof(AssetManager));
    asset_manager->images = malloc(sizeof(AssetImages));
    asset_manager->sounds = malloc(sizeof(AssetSounds));

    load_default_images(asset_manager->images);
    
    return asset_manager;
}
