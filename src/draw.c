#include "draw.h"

void draw_rect(SDL_Renderer* renderer, SDL_Rect rect, colour r, colour g,
	       colour b, colour a)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, &rect);
}
