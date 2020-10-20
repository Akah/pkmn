#include "main.h"

int main()
{
    SDL_Window* pWindow = createWindow();
    SDL_Renderer* pRenderer = SDL_CreateRenderer(pWindow, -1 ,SDL_RENDERER_ACCELERATED);
    quit = 0;
    pQuit = &quit;

    main_loop(pRenderer);

    SDL_DestroyWindow(pWindow);
    SDL_DestroyRenderer(pRenderer);
    
    return 0;
}

void main_loop(SDL_Renderer* pRenderer)
{
    SDL_Event event;
    int render_timer = roundf(1000.0f / 5.0f);
    const int delta_time = roundf(1000.0f / 5.0f);

    printf("%d", quit);
    printf("%d", *pQuit);
    
    while (!*pQuit) {
	const int start_ticks = SDL_GetTicks();

	while (SDL_PollEvent(&event) !=0) {
	    handle_input(event);
	}

	render_timer -= delta_time;

	if (render_timer <= 0) {
	    printf("quit=%d\n", *pQuit);
	    render(pRenderer);
	    render_timer = delta_time;
	}

	int end_ticks = SDL_GetTicks();

	SDL_Delay(delta_time - (end_ticks - start_ticks));
    }
}
