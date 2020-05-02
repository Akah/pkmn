#include "init.h"
#include "input.h"
#include "draw.h"

#include <math.h>
// TODO: replace 32 pixels with a defined tilesize
// TODO: extract to header file ln-6-23
void handleInput(SDL_Event e);
void update();
void render(SDL_Renderer *renderer);
long current_timestamp();
void print_key(char* key);
void load_media();
TTF_Font* load_font(char* src, int size);
void move();
void toggle_command_line();
void add_to_string(char* old_string, char character);

int quit = 0;

int camera_offset_x = 0;
int camera_offset_y = 0;

int player_pos_x = 9*32;
int player_pos_y = 7*32;

int npc_pos_x = 7*32;
int npc_pos_y = 6*32;

char command_line_open = 0;
char typing_mode = 0;

char command_string[64];

enum Move_Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE,
};

enum Move_Direction move_direction = NONE;

int map[16][16] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,2,2,2,0,0,0,0,0,0,0,0,1},
    {1,0,0,2,2,2,2,0,0,0,0,0,0,0,0,1},
    {1,0,0,2,2,2,2,0,0,0,0,0,0,0,0,1},
    {1,0,0,2,2,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
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
    int render_timer = roundf(1000.0f / fps); // frames per ms
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

void add_to_string(char* old_string, char character)
{
    strncat(old_string, old_string, character);
}

void handleInput(SDL_Event e) 
{
    if( e.type == SDL_QUIT )
    {
        quit = 1;
    }

    if (typing_mode){
	add_to_string(command_string, e.key.keysym.sym);
	printf("%c\n", e.key.keysym.sym);`
	printf("%s\n", command_string);
    } else {
	if (e.type == SDL_KEYUP) {
	    move_direction = NONE;
	}
	//User presses a key
	else if( e.type == SDL_KEYDOWN )
	{
	    switch( e.key.keysym.sym)
	    {
            case SDLK_UP:
            case SDLK_w:
		move_direction = UP;
                break;

            case SDLK_DOWN:
            case SDLK_s:
		move_direction = DOWN;
		break;

            case SDLK_LEFT:
            case SDLK_a:
		move_direction = LEFT;
                break;

            case SDLK_RIGHT:
            case SDLK_d:
		move_direction = RIGHT;
                break;

	    case SDLK_BACKQUOTE:
		toggle_command_line();
		break;
            default:
                printf("undefined key pressed: %c\n", e.key.keysym.sym);
                break;
	    }
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

void move() {
    switch(move_direction)
    {
	case UP:
	    player_pos_y -= 8;
	    camera_offset_y += 8;
	    break;
	case DOWN:
	    player_pos_y += 8;
	    camera_offset_y -= 8;
	    break;
	case LEFT:
	    player_pos_x -= 8;
	    camera_offset_x += 8;
	    break;
	case RIGHT:
	    player_pos_x += 8;
	    camera_offset_x -= 8;
	    break;
        default:
	    break;
    }
}

void render(SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);

    move();

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 32;
    rect.h = 32;

    // should be based on the size of the map
    for (int x = 0; x < 16; x++)
    {
	for (int y = 0; y < 16; y++)
	{
	    rect.x = x * 32 + (32*6) + camera_offset_x;
	    rect.y = y * 32 + (32*4) + camera_offset_y;
	    switch (map[x][y])
	    {
	      case 0:
	  	  draw_rect(renderer, rect, 0, 0, 0, 255);
		  break;
	      case 1:
		  draw_rect(renderer, rect, 255, 255, 255, 255);
		  break;
	      case 2:
		  draw_rect(renderer, rect, 0, 255, 0, 255);
	    }
	}
    }

    // draw npc
    rect.x = npc_pos_x + camera_offset_x;
    rect.y = npc_pos_y + camera_offset_y;
    draw_rect(renderer, rect, 0, 0, 255, 255);

    // draw player
    rect.x = player_pos_x + camera_offset_x;
    rect.y = player_pos_y + camera_offset_y;
    draw_rect(renderer, rect, 255, 0, 0, 0);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
}

void load_media(){
}

TTF_Font* load_font(char* src, int size) {
    TTF_Font *font = TTF_OpenFont(src, size);
    if ( font == NULL )
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
    else
	printf("loaded: %s\n", src);
    //printf("loaded: /usr/share/fonts/truetype/noto/NotoMono-Regular.ttf\n");
    return font;
}

void toggle_command_line()
{
    command_line_open = !command_line_open;
    typing_mode = !typing_mode;
    printf("commandline set to: %d\n", command_line_open);
}
