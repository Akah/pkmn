#ifndef RESOURCES_H
#define RESOURCES_H

#include <SDL2/SDL.h>

// instead of fixed size array; list/tree would be required to store values
struct texture_array {
    int len;
    SDL_Texture* texture[64];
    
};
typedef struct texture_array Texture_array;

struct node {
    char *key;
    struct texture_array *textures;
    struct node *left, *right;
};
typedef struct node Tree;

// void load_resource(Resource **tree, char *key, char *source, SDL_Palette *palette);

Tree* create_resource(char* source, char* key, SDL_Palette* palette, int length);

void print_resource(struct node* resource);

#endif
