#include "draw.h"

void render(SDL_Renderer* pRenderer, AssetManager *pAssetManager)
{
    SDL_RenderClear(pRenderer);
    
    draw_image(pRenderer, pAssetManager->images->front[0]);

    SDL_RenderPresent(pRenderer);
}

void draw_rect(SDL_Renderer *renderer, SDL_Rect rect, SDL_Colour colour)
{
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderFillRect(renderer, &rect);
}

void draw_image(SDL_Renderer *pRenderer, SDL_Texture *texture)
{
    SDL_Rect dest_rect = {
	128,
	128,
	56 * SCALE,
	56 * SCALE
    };

    SDL_RenderCopy(pRenderer, texture, NULL, &dest_rect);
}
