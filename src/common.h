#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include "utils/tree.h"
#include "state.h"
#include "asset/assets.h"
#include "time/date_time.h"
#include "math.h"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SCREEN_TITLE  "title"
#define SCALE 3

extern int quit;
extern int* pQuit;

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern Tree* assets;
extern State *state;
