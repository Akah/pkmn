/* #include "config.h" */
#include "main.h"

int main()
{
    SDL_Window *pWindow = createWindow();
    SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow, -1 ,SDL_RENDERER_ACCELERATED);

    State *pState = initState();
    
    main_loop(pRenderer);

    SDL_DestroyWindow(pWindow);
    SDL_DestroyRenderer(pRenderer);
    
    return 0;
}

void main_loop(SDL_Renderer* pRenderer)
{
    SDL_Event event;
    uint fps_last = SDL_GetTicks();
    uint fps_current = 0;
    uint fps_frames = 0;
    int render_timer = roundf(1000.0f / 60.0f);
    const int delta_time = roundf(1000.0f / 60.0f);

    // temp:
    quit = 1;
    while (!quit) {
	const int start_ticks = SDL_GetTicks();
	
	while (SDL_PollEvent(&event) !=0) {
	    handle_input(event);
	}

	render_timer -= delta_time;

	if (render_timer <= 0) {
	    render(pRenderer);
	    render_timer = delta_time;
	}

	fps_frames++;
	if (fps_last < SDL_GetTicks() - 1000) {
	    fps_last = SDL_GetTicks();
	    fps_current = fps_frames;
	    fps_frames = 0;
	}

	int end_ticks = SDL_GetTicks();
	SDL_Delay(delta_time - (end_ticks - start_ticks));
    }

}
