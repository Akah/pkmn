#include "draw.h"

/**
 * Scale screen position relative to screen scale value
 * @param n input value
 */
int px(int n)
{
    return n * SCALE;
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

void draw_start_menu()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    draw_string("NEW GAME", 8, 8);
    draw_string("CONTINUE", 8, 24);
    draw_string("OPTIONS", 8, 40);
}

void draw_start_screen()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    draw_image(asset_manager->images->logo, 45, 20);
    
    if ((SDL_GetTicks() / 1000) % 2) {
	draw_string("Press any key", 55, 110);
    }
}

SDL_Rect make_rect(int x, int y, int w, int h);
SDL_Rect make_rect(int x, int y, int w, int h)
{
    SDL_Rect rect = {x, y, w, h};
    return rect;
}

void draw_box(int x, int y, int w, int h)
{
    SDL_Colour colour = {255, 255, 255, 255};
    SDL_Rect rect = {x, y, w, h};
    draw_rect(rect, colour);
    
    colour.r = 0;
    colour.g = 0;
    colour.b = 0;

    int p1 = 3;
    int p2 = p1 * 2;
    int p3 = p1 * 3;
    int p4 = p1 * 4;
    int p5 = p1 * 5;
    int p6 = p1 * 6;
    int p7 = p1 * 7;

    x += p3;
    y += p3;
    h -= p7;
    w -= p7;

    rect = make_rect(x+p2, y, w-p4, p1);
    draw_rect(rect, colour);
    
    rect = make_rect(x+(w-p2), y+p1, p1, p1);
    draw_rect(rect, colour);
    
    rect = make_rect(x+(w-p1), y+p2, p1, h-p4);
    draw_rect(rect, colour);
    
    rect = make_rect(x, y+p2, p1, h-16);
    draw_rect(rect, colour);
    
    rect = make_rect(x+(w-p2), y+(h-p3), p1, p2);
    draw_rect(rect, colour);
    
    rect = make_rect(x+p2, y+(h-p2), w-p4, p2);
    draw_rect(rect, colour);
    
    rect = make_rect(x+p1, y+(h-p3), p1, p2);
    draw_rect(rect, colour);

    rect = make_rect(x, y+p2, p1, h-p4);
    draw_rect(rect, colour);
    
    rect = make_rect(x+p1, y+p1, p1, p1);
    draw_rect(rect, colour);

    /**************************************/

    rect = make_rect(x+p3, y+p2, w-p6, p2);//
    draw_rect(rect, colour);

    rect = make_rect(x+p2, y+p3, p2, p2);//
    draw_rect(rect, colour);

    rect = make_rect(x+(w-p4), y+p3, p2, p2);//
    draw_rect(rect, colour);

    rect = make_rect(x+p2, y+p3, p1, h-p7);//
    draw_rect(rect, colour);
    
    rect = make_rect(x+(w-p3), y+p3, p1, h-p7);//
    draw_rect(rect, colour);
    
    rect = make_rect(x+p3, y+(h-p4), w-p6, p1);//
    draw_rect(rect, colour);
}

void draw_dialog(int x, int y, int w, int h)
{
    draw_box(x, y, w, h);
}

void render()
{
    SDL_RenderClear(renderer);

    // draw_start_screen(renderer, asset_manager);
    // draw_start_menu();

    draw_dialog(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderPresent(renderer);
}
