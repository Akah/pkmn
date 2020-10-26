#include "draw.h"

void render(SDL_Renderer* pRenderer)
{
    SDL_RenderClear(pRenderer);

    SDL_Surface *img = IMG_Load("../res/espeon-front.png");
    draw_image(pRenderer, img);

    SDL_RenderPresent(pRenderer);
}

void draw_rect(SDL_Renderer *renderer, SDL_Rect rect, SDL_Colour colour)
{
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderFillRect(renderer, &rect);
}

void draw_image(SDL_Renderer *pRenderer, SDL_Surface *surface)
{
    SDL_Texture* texture = SDL_CreateTextureFromSurface(pRenderer, surface); 
    SDL_Rect dest_rect = {
	128,
	128,
	56 * SCALE,
	56 * SCALE
    };

    SDL_RenderCopy(pRenderer, texture, NULL, &dest_rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
