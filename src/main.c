#include "main.h"
#include "utils/resources.h"
#include <string.h>
#include <time.h>

SDL_Window *window;
SDL_Renderer *renderer;
// tree_node *asset_manager;
State *state;

Resource *test;

int main()
{
    printf("before window");
    window = createWindow();
    printf("after window");
    renderer = SDL_CreateRenderer(window, -1 ,SDL_RENDERER_ACCELERATED);
    //asset_manager = init_asset_manager(renderer);
    state = initState();

    /* SDL_DestroyWindow(window); */
    /* SDL_DestroyRenderer(renderer); */


    test = (Resource *)malloc(sizeof(Resource));

    struct texture_array *array = malloc(sizeof(struct texture_array));
    SDL_Texture *txt[4];
    array->len = 4;
    array->texture = txt;
    

    test->key = "test";
    test->texture = array;
    test->texture->texture[0] = load_texture("../res/images/pokemon.png", NULL);


    main_loop();
    
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

    time_t t;
    struct tm *tm;
    uint time_ticks = 2000;

    while (!quit) {
	const int start_ticks = SDL_GetTicks();

	if (SDL_GetTicks() > time_ticks + 1000) {
	    t = time(NULL);
	    tm = localtime(&t);
	    sprintf(state->time.time, "%d:%d", tm->tm_hour, tm->tm_min);
	    get_day(tm->tm_wday, state->time.day);
	    time_ticks = SDL_GetTicks();
	}
	
	while (SDL_PollEvent(&event) !=0) {
	    handle_input_event(event);
	}

	if (SDL_GetTicks() > (last_input_ticks + 300)) {
	    handle_input_key(state);
	    last_input_ticks = SDL_GetTicks();
	}

	render_timer -= delta_time;

	if (render_timer <= 0) {
	    // render(renderer, asset_manager);
	    SDL_RenderClear(renderer);

	    int w, h;
	    int x = 0, y = 0;
	    int n = 0;
	    SDL_QueryTexture(test->texture->texture[n], NULL, NULL, &w, &h);
	    SDL_Rect dst_rect = { x, y, w, h };
	    SDL_RenderCopy(renderer, test->texture->texture[n], NULL, &dst_rect);
	    render_timer = delta_time;

	    SDL_RenderPresent(renderer);
	    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
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
