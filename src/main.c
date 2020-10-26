/* #include "config.h" */
#include "main.h"

int main()
{
    SDL_Window *pWindow = createWindow();
    SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow, -1 ,SDL_RENDERER_ACCELERATED);

    AssetManager *pAssetManager = init_asset_manager();
    State *pState = initState();

    SDL_Surface *surface = IMG_Load("../res/espeon-front.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(pRenderer, surface);

    pAssetManager->images->front[0] = texture;
    
    main_loop(pRenderer, pState, pAssetManager);

    SDL_DestroyWindow(pWindow);
    SDL_DestroyRenderer(pRenderer);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    
    return 0;
}

void main_loop(SDL_Renderer *pRenderer, State *pState, AssetManager *pAssetManager)
{
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
	    fps_frames = 0;
	}

	int end_ticks = SDL_GetTicks();
	SDL_Delay(delta_time - (end_ticks - start_ticks));
    }

}
