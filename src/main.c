#include "main.h"
#include <string.h>
#include <time.h>

SDL_Window *window;
SDL_Renderer *renderer;
AssetManager *asset_manager;
State *state;

time_t t;

char *current_day(char* out)
{
    t = time(NULL);
    struct tm *tm = localtime(&t);

    switch (tm->tm_wday) {
    case 0:
	out = "SUNDAY";
	break;
    case 1:
	out = "MONDAY";
	break;
    case 2:
	out = "TUESDAY";
	break;
    case 3:
	out = "WEDNESDAY";
	break;
    case 4:
	out = "THURSDAY";
	break;
    case 5:
	out = "FRIDAY";
	break;
    case 6:
	out = "SATURDAY";
	break;
    default:
	printf("Error getting current day. Check src/time.c");
    }

    return out;
}

int main()
{
    window = createWindow();
    renderer = SDL_CreateRenderer(window, -1 ,SDL_RENDERER_ACCELERATED);
    asset_manager = init_asset_manager(renderer);
    state = initState();

    char day[11];
    current_day(day);
    printf("%s\n", day);
    
    main_loop();

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
    return 0;
}

void main_loop()
{
    char title[16];
    SDL_Event event;
    uint last_input_ticks = 0;
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

	if (SDL_GetTicks() > last_input_ticks + 300) {
	    handle_input_key(state);
	    last_input_ticks = SDL_GetTicks();
	}

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
