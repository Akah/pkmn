#include "draw.h"

void render(SDL_Renderer* pRenderer, AssetManager *pAssetManager)
{
    SDL_RenderClear(pRenderer);

    draw_string(pRenderer, pAssetManager, "abcdefghijklm", 0, 0);
    draw_string(pRenderer, pAssetManager, "nopqrstuvwxzy", 0, 8*SCALE);

    SDL_RenderPresent(pRenderer);
}

void draw_rect(SDL_Renderer *renderer, SDL_Rect rect, SDL_Colour colour)
{
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderFillRect(renderer, &rect);
}

void draw_image(SDL_Renderer *pRenderer, SDL_Texture *texture)
{
    SDL_Rect dst_rect = { 128, 48, 8 * SCALE, 8 * SCALE };
    SDL_Rect src_rect = { 8, 8, 8, 8 };
	
    SDL_RenderCopy(pRenderer, texture, &src_rect, &dst_rect);
}

void draw_char(SDL_Renderer *pRenderer,AssetManager *pAssetManager,char ch, int x, int y)
{
    int row = (ch - 32) % 16;
    int col = (ch - 32) / 15;

    SDL_Rect dst_rect = {x, y, 8 * SCALE, 8 * SCALE};
    SDL_Rect src_rect = {row * 8, col * 8, 8, 8};

    SDL_RenderCopy(
	pRenderer,
	pAssetManager->images->font,
	&src_rect,
	&dst_rect
    );
}

void draw_string(SDL_Renderer *pRenderer, AssetManager *pAssetManager, char *str, int x, int y)
{
    int length = strlen(str);
    for (int i=0; i < length; i++) {
	draw_char(pRenderer, pAssetManager, str[i], x, y);
	x = x + 8 * SCALE;
    }
}
