#include "main.h"
#include <string.h>

SDL_Window *window;
SDL_Renderer *renderer;
AssetManager *asset_manager;
State *state;

int main()
{
    window = createWindow();
    renderer = SDL_CreateRenderer(window, -1 ,SDL_RENDERER_ACCELERATED);
    asset_manager = init_asset_manager(renderer);
    state = initState();
    
    main_loop();

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
    return 0;
}

void main_loop()
{
    char title[16];
    SDL_Event event;
    uint fps_last = SDL_GetTicks();
    uint fps_current = 0;
    uint fps_frames = 0;
    int render_timer = roundf(1000.0f / 60.0f);
    const int delta_time = roundf(1000.0f / 60.0f);

    while (!quit) {
	const int start_ticks = SDL_GetTicks();
	
	while (SDL_PollEvent(&event) !=0) {
	    handle_input_event(event);
	}
	handle_input_key(state);

	render_timer -= delta_time;

	if (render_timer <= 0) {
	    render(renderer, asset_manager);
	    render_timer = delta_time;
	}

	fps_frames++;
	
	if (fps_last < SDL_GetTicks() - 1000) {
	    fps_last = SDL_GetTicks();
	    fps_current = fps_frames;
	    sprintf(title, "pkmn: %u fps", fps_frames);
	    SDL_SetWindowTitle(window, title);
	    fps_frames = 0;
	}

	int end_ticks = SDL_GetTicks();

	// slower systems start with negative delay time(i.e my vm)
	int delay = delta_time - (end_ticks - start_ticks);
	if (delay > 0) {
	  SDL_Delay(delay);
	}
    }
   
}
