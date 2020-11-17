#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "asset/assets.h"
#include "state.h"
#include "time/date_time.h"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SCREEN_TITLE  "title"
#define SCALE 3

extern int quit;
extern int* pQuit;

extern SDL_Renderer *renderer;
extern AssetManager *asset_manager;
extern State *state;
