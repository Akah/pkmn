#include "common.h"

struct texture_array {
    int len;
    SDL_Texture **texture;
} texture_array;

struct node {
    char *key;
    struct texture_array *texture;
    struct node *left, *right;
};
typedef struct node Resource;

void load_resource(Resource **tree, char *key, char *source, SDL_Palette *palette);
