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

    if (key_state[SDL_SCANCODE_RIGHT]) {
	SDL_LogDebug(SDL_LOG_CATEGORY_TEST, "right pressed");
    }

    if (key_state[SDL_SCANCODE_LEFT]) {
	SDL_LogDebug(SDL_LOG_CATEGORY_TEST, "left  pressed");
    }

    if (key_state[SDL_SCANCODE_DOWN]) {
	SDL_LogDebug(SDL_LOG_CATEGORY_TEST, "down  pressed");
	state->cursor.pos_y += 16 * SCALE;
    }
    
    if (key_state[SDL_SCANCODE_UP]) {
	SDL_LogDebug(SDL_LOG_CATEGORY_TEST, "up    pressed");
	state->cursor.pos_y -= 16 * SCALE;
    }
}
 
