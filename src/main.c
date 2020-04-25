#include "init.h"
#include "input.h"
#include <math.h>

void handleInput(SDL_Event e);
void update();
void render(SDL_Renderer *renderer);
long current_timestamp();
void print_key(char* key);
void load_media();
TTF_Font* load_font(char* src, int size);

int quit = 0;
int map_width;
int map_height;

int main(int argc, char* args[])
{
    SDL_Window* pWindow;
    SDL_Renderer* pRenderer;
    SDL_Event event;
    pWindow = createWindow();
    pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    load_media();

    char map[];

    map[0] = "########";
    map[1] = "#000#00#";
    map[2] = "###0#00#";
    map[3] = "#000000#";
    map[4] = "#00###0#";
    map[5] = "#00#000#";
    map[6] = "########";

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
                break;

            case SDLK_DOWN:
            case SDLK_s:
                print_key("down");
                break;

            case SDLK_LEFT:
            case SDLK_a:
                print_key("left");
                break;

            case SDLK_RIGHT:
            case SDLK_d:
                print_key("right");
                break;

            default:
                // print_key("other");
                break;
        }
    }
}

void print_key(char* key)
{
    printf("Key pressed: %s\n", key);
}

void update()
{
    // ticks++;
}

float pos = 0.0001;
void render(SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);

    SDL_Rect rect;
    rect.x = 32;
    rect.y = 32;
    rect.w = 32;
    rect.h = 32;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    
    SDL_RenderPresent(renderer);
}

void load_media(){
}

TTF_Font* load_font(char* src, int size) {
    TTF_Font *font = TTF_OpenFont(src, size);
    if ( font == NULL )
        printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );
    else
        printf( "loaded: /usr/share/fonts/truetype/noto/NotoMono-Regular.ttf\n");
    return font;
}
