#include "init.h"
#include "draw.h"

#include <math.h>

void handleInput(SDL_Event e);
void update();
void render(SDL_Renderer *renderer);
long current_timestamp();
void load_media();
TTF_Font* load_font(char* src, int size);
void move();

static const int TILE_SIZE = 16;
static const int SCALE = 2;
static const int SCALED_TILE_SIZE = TILE_SIZE * SCALE;

enum Move_Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE,
};

enum Move_Direction move_direction = NONE;
