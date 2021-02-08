#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "state.h"
#include "asset/assets.h"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SCREEN_TITLE  "title"
#define SCALE         3

extern int quit;
// extern SDL_mutex    *console_buffer;

extern SDL_Window   *window;
extern SDL_Renderer *renderer;
extern AssetManager *asset_manager;
extern State        *state;
