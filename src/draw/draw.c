#include "draw.h"
#include "../utils.h"

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

    SDL_Rect dst_rect = { x, y, px(w), px(h) };

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
    for (int i=0; i < (int)strlen(str); i++) {
	draw_char(str[i], px(x), y);
	x += 8;
    }
}

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

void draw_dialog(char* str[18], int x, int y, int w, int h)
{
    int buffer_pos = state->dialog->buffer_position;
    draw_box(x, y, w, h);
    draw_string(str[buffer_pos], x+8, y+40);
    if (str[buffer_pos+1] && (SDL_GetTicks() / 300) % 2) {
	draw_char('`', w-52, SCREEN_HEIGHT-35);
    }
}

void draw_start_menu()
{
    /* draw_dialog(0, 0, px(120), px(70)); */
    /* draw_string("NEW GAME", 16, 16); */
    /* draw_string("CONTINUE", 16, 32); */
    /* draw_string("OPTIONS", 16, 48); */

    /* draw_char('~', 21, (state->start_menu.items*16*3) + 48); */

    /* draw_dialog(0, px(120), SCREEN_WIDTH, SCREEN_HEIGHT - px(120)); */
    /* draw_string(state->time->day, 8, 128); */
    /* draw_string(state->time->tod, 8, 136); */
    /* draw_string(state->time->time, 72, 136); */
}

void draw_start_screen()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    draw_image(asset_manager->images->logo, 20, 40);

    if ((SDL_GetTicks() / 1000) % 2) {
	draw_string("Press any key", 0, 0);
    }
}

void draw_player_status()
{
    // passed as parameters when struct for player party created:
    // i.e pokemon struct passed for current pokemon
    char *name = "ESPEON";
    float health = 120;
    float health_max = 120;
    char status = 0; // enum of status types
    float exp_nxt_lvl = 3100;
    float exp = 3099;

    int health_val = ceil((health/health_max)*144);
    int exp_val = -(192*(exp/exp_nxt_lvl));

    draw_image(asset_manager->images->player_status, 180, 158);

    SDL_Colour health_colour = get_health_colour(health, health_max);

    SDL_Colour exp_colour = {0x20, 0x88, 0xf8};
    draw_rect(make_rect(252, 214, health_val, 6), health_colour);
    draw_rect(make_rect(396, 265, exp_val, 6), exp_colour);
    draw_string("ESPEON", 68, 52);
    draw_string("65", 108, 61);

    char health_str[8];
    sprintf(health_str, "%3d/%3d", (int)health, (int)health_max);
    draw_string(health_str, 76, 76);
}

void draw_enemy_status()
{
    draw_string("UMBREON", 2, 0);
    draw_image(asset_manager->images->enemy_status, 8, 32);
}

SDL_Colour get_health_colour(int health, int health_max)
{
    SDL_Colour colour;
    int health_percent = ceil(((float)health/(float)health_max)*100);
    if (health_percent > 50) {
	colour.r = 0;
	colour.g = 184;
	colour.b = 0;
    } else if (health_percent > 10) {
	colour.r = 247;
	colour.g = 172;
	colour.b = 5;
    } else {
	colour.r = 248;
	colour.g = 0;
	colour.b = 0;
    }
    return colour;
}

void render()
{
    SDL_RenderClear(renderer);

    draw_string("test", 0, 0);

    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}
