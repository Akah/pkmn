#include "common.h"

SDL_Texture *load_texture(char *path);

void load_default_images(AssetImages *pImages);

AssetManager *init_asset_manager();

void read_image_file(int image_size, char *src, Image *test);
