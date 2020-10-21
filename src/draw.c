#include "draw.h"

void render(SDL_Renderer* pRenderer)
{
    SDL_RenderClear(pRenderer);
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);

    SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255);
    SDL_Rect rectangle = rect(100, 100, 100, 100);

    SDL_RenderFillRect(pRenderer, &rectangle);
    SDL_RenderPresent(pRenderer);
}

SDL_Rect rect(int x, int y, int w, int h)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    return rect;
}
