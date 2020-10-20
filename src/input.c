#include "input.h"

void handle_input(SDL_Event event)
{
    if (event.type == SDL_QUIT) {
	pQuit = 1;
	printf("set quit to %d\n", quit);
    }
}
 
