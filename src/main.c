#include "init/init.h"
#include "draw/draw.h"
#include "input/input.h"
#include "asset/asset_manager.h"
#include "time/date_time.h"
#include "console.h"
#include "utils.h"
#include "main.h"

#define TEXT_SPEED 4 // hight is slower

SDL_Window      *window;
SDL_Renderer    *renderer;
AssetManager    *asset_manager;
State           *state;

#ifdef WINDOWS
int WinMain(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
    window = createWindow();
    renderer = SDL_CreateRenderer(window, -1 ,SDL_RENDERER_ACCELERATED);
    asset_manager = init_asset_manager(renderer);
    state = initState();

    SDL_CreateThread(read_console, "console_thread", (void*)NULL);
    main_loop();

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    return 0;
}

void main_loop()
{
    char title[16];
    SDL_Event event;
    unsigned int last_input_ticks = 0;
    unsigned int fps_last = SDL_GetTicks();
    unsigned int fps_current = 0;
    unsigned int fps_frames = 0;
    int render_timer = roundf(1000.0f / 60.0f);

    const int delta_time = roundf(1000.0f / 60.0f);

    time_t t;
    struct tm *tm;
    unsigned int time_ticks = 2000;

    //_utils_debug("started main loop");

    while (!quit) {
	const int start_ticks = SDL_GetTicks();

	// every second:
	if (SDL_GetTicks() > time_ticks + 1000) {
	    t = time(NULL);
	    tm = localtime(&t);
	    sprintf(state->time->time, "%02d:%02d", tm->tm_hour, tm->tm_min);
	    get_day(tm->tm_wday, state->time->day);
	    get_time_of_day(tm->tm_hour, state->time->tod);
	    time_ticks = SDL_GetTicks();
	}

	while (SDL_PollEvent(&event) !=0) {
	    handle_input_event(event);
	}

	// input check every 300 ms
	if (SDL_GetTicks() > (last_input_ticks + 300)) {
	    handle_input_key(state);
	    last_input_ticks = SDL_GetTicks();
	}

	render_timer -= delta_time;

	// draw/render
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
