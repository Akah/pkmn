#include "../common.h"

void render(SDL_Renderer* pRenderer, AssetManager *pAssetManager);

void draw_rect(SDL_Renderer *renderer, SDL_Rect rect, SDL_Colour colour);

void draw_image(SDL_Renderer * pRenderer, SDL_Texture *pTexture);

void draw_char(SDL_Renderer *pRenderer, AssetManager *pAssetManager, char c, int x, int y);

void draw_string(SDL_Renderer *pRenderer, AssetManager *pAssetManager, char *str, int x, int y);
