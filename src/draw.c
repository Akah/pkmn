#include "draw.h"

void render(SDL_Renderer* pRenderer)
{
    SDL_RenderClear(pRenderer);

    SDL_Rect rectangle = {100, 100, 100, 100};
    SDL_Colour colour = {255, 0, 0, 255};
    draw_rect(pRenderer, rectangle, colour);

    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    SDL_RenderPresent(pRenderer);
}

void draw_rect(SDL_Renderer *renderer, SDL_Rect rect, SDL_Colour colour)
{
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderFillRect(renderer, &rect);
}
