#include "draw.h"

void render(SDL_Renderer* pRenderer, AssetManager *pAssetManager)
{
    SDL_RenderClear(pRenderer);

    draw_start_screen(pRenderer, pAssetManager);

    SDL_RenderPresent(pRenderer);
}

void draw_rect(SDL_Renderer *renderer, SDL_Rect rect, SDL_Colour colour)
{
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderFillRect(renderer, &rect);
}

void draw_image(SDL_Renderer *pRenderer, SDL_Texture *texture, int x, int y)
{
    int w, h;

    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
  
    SDL_Rect dst_rect = { x, y, (x+w)*SCALE, (y+h)*SCALE };
	
    SDL_RenderCopy(pRenderer, texture, NULL, &dst_rect);
}

void draw_char(SDL_Renderer *pRenderer,AssetManager *pAssetManager,char ch, int x, int y)
{
    int row = (ch - 32) % 16;
    int col = (ch - 32) / 16;

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

void draw_start_screen(SDL_Renderer *pRenderer, AssetManager *pAssetManager)
{
  draw_image(pRenderer, pAssetManager->images->logo, 0, 0);
}
