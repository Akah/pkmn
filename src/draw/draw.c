#include "draw.h"

/**
 * Scale screen position relative to screen scale value
 * @param n input value
 */
int px(int n)
{
    return n * SCALE;
}

void render()
{
    SDL_RenderClear(renderer);

    draw_start_screen(renderer, asset_manager);

    SDL_RenderPresent(renderer);
}

void draw_rect(SDL_Rect rect, SDL_Colour colour)
{
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderFillRect(renderer, &rect);
}

void draw_image(SDL_Texture *texture, int x, int y)
{
    int w, h;

    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
  
    SDL_Rect dst_rect = { x, y, px(x+w), px(y+h) };
	
    SDL_RenderCopy(renderer, texture, NULL, &dst_rect);
}

void draw_char(char ch, int x, int y)
{
    int row = (ch - 32) % 16;
    int col = (ch - 32) / 16;

    SDL_Rect dst_rect = {x, y, 8 * SCALE, 8 * SCALE};
    SDL_Rect src_rect = {row * 8, col * 8, 8, 8};

    SDL_RenderCopy(
	renderer,
	asset_manager->images->font,
	&src_rect,
	&dst_rect
    );
}

void draw_string(char *str, int x, int y)
{
    int length = strlen(str);
    for (int i=0; i < length; i++) {
	draw_char(str[i], px(x), px(y));
	x = x+8;
    }
}

void draw_start_screen()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    draw_image(asset_manager->images->logo, 45, 20);
    
    if ((SDL_GetTicks() / 1000) % 2) {
	draw_string("Press any key", 55, 110);
    }
}
