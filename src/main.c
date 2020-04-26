#include "init.h"
#include "input.h"
#include <math.h>

// TODO: extract to header file ln-6-23
void handleInput(SDL_Event e);
void update();
void render(SDL_Renderer *renderer);
long current_timestamp();
void print_key(char* key);
void load_media();
TTF_Font* load_font(char* src, int size);

int quit = 0;

int camera_offset_x = 0;
int camera_offset_y = 0;

int player_pos_x = 9*32;
int player_pos_y = 7*32;

int npc_pos_x = 7*32;
int npc_pos_y = 6*32;

int map[8][8] =
    {
     {1,1,1,1,1,1,1,1}, 
     {1,0,0,0,0,0,0,1},
     {1,0,0,0,0,0,0,1},
     {1,0,0,0,0,0,0,1},
     {1,0,0,0,0,0,0,1},
     {1,0,0,0,0,0,0,1},
     {1,0,0,0,0,0,0,1},
     {1,1,1,1,1,1,1,1},
    };

int main(int argc, char* args[])
{
    SDL_Window* pWindow;
    SDL_Renderer* pRenderer;
    SDL_Event event;
    pWindow = createWindow();
    pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    load_media();

    const float fps = 60;
    const int delta_time = roundf(1000.0f / 60.0f);
    int render_timer = roundf(1000.0f / fps);
    while (!quit) {
        const int begin_frame_time = SDL_GetTicks();

        while (SDL_PollEvent(&event) != 0) {
            handleInput(event);
        }

        render_timer -= delta_time;
        if (render_timer <= 0) {
            render(pRenderer);
            render_timer = roundf(1000.0f / fps);
        }

        int end_frame_time = SDL_GetTicks();
        SDL_Delay(delta_time - (end_frame_time - begin_frame_time));
    }

    SDL_DestroyWindow(pWindow);
    SDL_DestroyRenderer(pRenderer);

    return 0;
}

void handleInput(SDL_Event e) 
{
    if( e.type == SDL_QUIT )
    {
        quit = 1;
    }
    //User presses a key
    else if( e.type == SDL_KEYDOWN )
    {
        //Select surfaces based on key press
        switch( e.key.keysym.sym )
        {
            case SDLK_UP:
            case SDLK_w:
                print_key("up");
		camera_offset_y += 32;
		player_pos_y -= 32;
                break;

            case SDLK_DOWN:
            case SDLK_s:
                print_key("down");
		camera_offset_y -= 32;
		player_pos_y += 32;
                break;

            case SDLK_LEFT:
            case SDLK_a:
                print_key("left");
		camera_offset_x += 32;
		player_pos_x -= 32;
                break;

            case SDLK_RIGHT:
            case SDLK_d:
                print_key("right");
		camera_offset_x -= 32;
		player_pos_x += 32;
                break;

            default:
                // print_key("other");
                break;
        }
    }
}

void print_key(char* key)
{
    //    printf("Key pressed: %s\n", key);
}

void update()
{
    // ticks++;
}

void render(SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 32;
    rect.h = 32;

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
	    if (map[y][x] == 1) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	    }
	    if (map[y][x] == 0) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	    }
	    rect.x = x * 32 + (32*6) + camera_offset_x;
	    rect.y = y * 32 + (32*4) + camera_offset_y;
	    SDL_RenderFillRect(renderer, &rect);
	}
    }

    // draw player
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    rect.x = player_pos_x + camera_offset_x;
    rect.y = player_pos_y + camera_offset_y;
    SDL_RenderFillRect(renderer, &rect);

    // draw npc
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    rect.x = npc_pos_x + camera_offset_x;
    rect.y = npc_pos_y + camera_offset_y;
    SDL_RenderFillRect(renderer, &rect);
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
}

void load_media(){
}

TTF_Font* load_font(char* src, int size) {
    TTF_Font *font = TTF_OpenFont(src, size);
    if ( font == NULL )
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );
    else
        printf("loaded: /usr/share/fonts/truetype/noto/NotoMono-Regular.ttf\n");
    return font;
}
