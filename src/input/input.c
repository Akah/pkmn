#include "input.h"

int quit = 0;

void handle_input_event(SDL_Event event)
{
    if (event.type == SDL_QUIT) {
	quit = 1;
	return;
    }
}

void handle_input_key()
{
    const Uint8 *key_state = SDL_GetKeyboardState(NULL);

    if (key_state[SDL_SCANCODE_LEFT]) {
	printf("pressed a\n");
    }
}
 
