#include "../utils.h"
#include "init.h"

SDL_Window* createWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
	printf("SDL_Init error: %s\n", SDL_GetError());
    else
	_utils_debug("Initialised SDL");

    // SDL_WINDOW_RESIZABLE
    SDL_Window* window =
	SDL_CreateWindow(SCREEN_TITLE,
			 SDL_WINDOWPOS_UNDEFINED,
			 SDL_WINDOWPOS_UNDEFINED,
			 SCREEN_WIDTH,
			 SCREEN_HEIGHT,
			 SDL_WINDOW_SHOWN);
    if (window == NULL)
	printf("Window error: %s\n", SDL_GetError());
    else
	_utils_debug("Initialised window");

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	printf("SDL_image error: %s\n", IMG_GetError());
    else
	_utils_debug("Initialised SDL_image");

    return window;
}

State *initState()
{
    const Overworld overworld = {
	0,
    };

    const Start_menu start_menu = {
	NEW_GAME
    };

    const Cursor cursor = {
	0,
	0,
	1,
    };

    Time* time = malloc(sizeof(Time));
    strcpy(time->time, "00:00");
    strcpy(time->day,  "MONDAY");
    strcpy(time->tod,  "NIGHT");

    Dialog* dialog = malloc(sizeof(Dialog));
    dialog->chars = 0;
    dialog->writing_to_dialog = 0;

    State* state = malloc(sizeof(State));

    state->current_state = START_MENU; // change later to into;
    state->overworld = overworld;
    state->start_menu = start_menu;
    state->cursor = cursor;
    state->test = 0;
    state->time = time;
    state->dialog = dialog;

    _utils_debug("Initialised state machine");
    return state;
}
