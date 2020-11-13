#include "input.h"

int quit = 0;

void handle_input_event(SDL_Event event)
{
    if (event.type == SDL_QUIT) {
	quit = 1;
	return;
    }
}

void handle_start_menu(const Uint8 *key_state)
{

    enum start_menu_items *item = &state->start_menu.items;
    if (key_state[SDL_SCANCODE_UP]) {
	if (*item == 0) {
	    *item = 2;
	} else {
	    (*item)--;
	}
    }

    if (key_state[SDL_SCANCODE_DOWN]) {
	if (*item == 2) {
	    *item = 0;
	} else {
	    (*item)++;
	}
    }

    if (key_state[SDL_SCANCODE_RETURN]) {
    	switch (*item) {
	    case NEW_GAME:
		printf("new game\n");
	        break;
	    case CONTINUE:
		printf("continue\n");
	        break;
	    case SETTINGS:
		printf("settings\n");
	        break;
	}
    }
}

void handle_input_key()
{
    const Uint8 *key_state = SDL_GetKeyboardState(NULL);

    switch (state->current_state) {
        case START_MENU:
	    handle_start_menu(key_state);
	    break;
        default:
	    break;
    }

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
 
