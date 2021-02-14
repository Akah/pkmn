#include "../common.h"
#include "draw.h"
#include "render.h"

void render()
{
    SDL_RenderClear(renderer);

    char *a[18] = {
    //  "------------------"< 18 chars max length
	"This is a max exa-",
	"ple although it ",
	"looks like more",
	"should fit."
    };

    int height = 100;

    draw_dialog(a, 0, px(height), SCREEN_WIDTH, SCREEN_HEIGHT - px(height));

    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}
