#include "input.h"

int quit = 0;

void handle_input(SDL_Event event)
{
    if (event.type == SDL_QUIT) {
	quit = 1;
    }
}
 
