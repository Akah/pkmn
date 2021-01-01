#include "resources.h"

/*
 * Three possible 'types':
 * - static image
 * - array of static images
 * - animated image (again just an array of static images)
 * 
 * arrays can be dynamically allocated based on an amount passed to insert function
 *
 */

/* struct node { */
/*     char *key; */
/*     SDL_Texture *texture; // (value) */
/*     struct node *left, *right; */
/* }; */
/* typedef Resource node; */

void load_resource(Resource **tree, char *key, char *source, SDL_Palette *palette)
{
    SDL_Surface *surface = IMG_Load(source);
    if (surface == NULL) printf("SDL_Error: %s\n", IMG_GetError());
    if (palette != NULL) surface->format->palette = palette;
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    node *temp = NULL;
    if (!(*tree)) {
	printf("creating new tree\n");
	temp = (node *)malloc(sizeof(node));
    }
}
