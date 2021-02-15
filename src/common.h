#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "state.h"
#include "asset/assets.h"

#define SCALE         3
#define SCREEN_WIDTH  160*SCALE
#define SCREEN_HEIGHT 144*SCALE
#define SCREEN_TITLE  "title"

extern bool quit;
// extern SDL_mutex    *console_buffer;

extern SDL_Window   *window;
extern SDL_Renderer *renderer;
extern AssetManager *asset_manager;
extern State        *state;
