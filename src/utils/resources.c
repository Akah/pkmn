#include <SDL2/SDL_image.h>

#include "resources.h"
#include "../asset/asset_manager.h"

/*
 * Three possible 'types':
 * - static image
 * - array of static images
 * - animated image (again just an array of static images)
 * 
 * arrays can be dynamically allocated based on an amount passed to insert function
 *
 */

Tree* create_resource(char* source, char* key, SDL_Palette* palette, int length)
{
    // init texture array
    Texture_array* texture_array = malloc(sizeof(Texture_array));
    SDL_Texture* texture = load_texture(source, palette);
    
    texture_array->len = length;
    texture_array->texture[1] = texture;

    int w = 0, h = 0;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    printf("%d, %d\n", w, h);
    
    // init tree node
    Tree *resource = malloc(sizeof(Tree));
    resource->key      = key;
    resource->textures = texture_array;
    resource->left     = NULL;
    resource->right    = NULL;
    return resource;
}

void print_resource(struct node* resource)
{
    return;
}
