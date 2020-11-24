#include "../common.h"

void render();

void draw_rect(SDL_Rect rect, SDL_Colour colour);

void draw_image(SDL_Texture *pTexture, int x, int y);

void draw_image_cropped();

void draw_char(char c, int x, int y);

void draw_string(char *str, int x, int y);

void draw_start_screen();

void draw_start_menu();

void draw_box(int x, int y, int w, int h);

void draw_binary();

void draw_dialog(int x, int y, int w, int h);
