#include "main.h"
#include <string.h>

SDL_Window *pWindow;

int main()
{
    pWindow = createWindow();
    SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow, -1 ,SDL_RENDERER_ACCELERATED);

    AssetManager *pAssetManager = init_asset_manager(pRenderer);
    State *pState = initState();
    
    main_loop(pRenderer, pState, pAssetManager);

    SDL_DestroyWindow(pWindow);
    SDL_DestroyRenderer(pRenderer);
    
    return 0;
}

void main_loop(SDL_Renderer *pRenderer, State *pState, AssetManager *pAssetManager)
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
	handle_input_key(pState);

	render_timer -= delta_time;

	if (render_timer <= 0) {
	    render(pRenderer, pAssetManager);
	    render_timer = delta_time;
	}

	fps_frames++;
	
	if (fps_last < SDL_GetTicks() - 1000) {
	    fps_last = SDL_GetTicks();
	    fps_current = fps_frames;
	    sprintf(title, "pkmn: %u fps", fps_frames);
	    SDL_SetWindowTitle(pWindow, title);
	    fps_frames = 0;
	}

	int end_ticks = SDL_GetTicks();
	SDL_Delay(delta_time - (end_ticks - start_ticks));
    }
   
}
