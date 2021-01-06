#ifndef RESOURCES_H
#define RESOURCES_H

#include <SDL2/SDL.h>

// instead of fixed size array; list/tree would be required to store values
// ^ possible TODO
struct texture_array {
    int len;
    SDL_Texture* texture[6]; // max number of animation frames?
    
};
typedef struct texture_array Texture_array;

struct node {
    char *key;
    struct texture_array *textures;
    struct node *left, *right;
};
typedef struct node Node;
typedef struct node Tree;

// void load_resource(Resource **tree, char *key, char *source, SDL_Palette *palette);

Tree* resource_create(char* source, char* key, SDL_Palette* palette, int length);

Tree* resource_search(Tree** tree, char* key);

void resource_insert(Tree** tree, Node* node);

void resource_delete(Node* node);

void resource_print(Node* resource);

void print_helper(Node* node, int space);

#endif
