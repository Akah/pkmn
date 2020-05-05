#include "main.h"

static int quit = 0;

int camera_offset_x = 0;
int camera_offset_y = 0;

int player_pos_x = 9*SCALED_TILE_SIZE;
int player_pos_y = 7*SCALED_TILE_SIZE;

int npc_pos_x = 7*SCALED_TILE_SIZE;
int npc_pos_y = 13*SCALED_TILE_SIZE;

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

void handleInput(SDL_Event e) 
{
    if( e.type == SDL_QUIT )
    {
        quit = 1;
    }
    else
    {
	if (e.type == SDL_KEYUP)
	{
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
		break;
            default:
                printf("undefined key pressed: %c\n", e.key.keysym.sym);
                break;
	    }
	}
    }
    
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
    rect.w = SCALED_TILE_SIZE;
    rect.h = SCALED_TILE_SIZE;

    // should be based on the size of the map
    for (int x = 0; x < 16; x++)
    {
	for (int y = 0; y < 16; y++)
	{
	    rect.x = x * SCALED_TILE_SIZE + (TILE_SIZE *10) + camera_offset_x;
	    rect.y = y * SCALED_TILE_SIZE + (TILE_SIZE *6) + camera_offset_y;
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
