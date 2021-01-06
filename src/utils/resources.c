#include <SDL2/SDL_image.h>
#include "resources.h"
#include "../asset/asset_manager.h"


Tree* resource_create(char* source, char* key, SDL_Palette* palette, int length)
{
    // init texture array
    Texture_array* texture_array = malloc(sizeof(Texture_array));
    SDL_Texture* texture = load_texture(source, palette);
    
    texture_array->len = length;
    texture_array->texture[1] = texture;

    int w = 0, h = 0;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    //printf("%d, %d\n", w, h);
    
    // init tree node
    Tree *resource = malloc(sizeof(Tree));
    resource->key      = key;
    resource->textures = texture_array;
    resource->left     = NULL;
    resource->right    = NULL;
    return resource;
}

void resource_insert(Tree** tree, Node* node) // possibly should be using double pointer???
{
    if (!(*tree)) {
	*tree = node;
	return;
    }

    if (strcmp(node->key, (*tree)->key) < 0) {
	resource_insert(&(*tree)->left, node);
    } else if (strcmp(node->key, (*tree)->key) > 0) {
	resource_insert(&(*tree)->right, node);
    }
}

Tree* resource_search(Tree** tree, char* key)
{
    if (!(*tree)) {
	return NULL;
    }

    if (strcmp(key, (*tree)->key) > 0) {
	resource_search(&(*tree)->right, key);
    } else if (strcmp(key, (*tree)->key) < 0) {
	resource_search(&(*tree)->left, key);
    } else if (strcmp(key, (*tree)->key) == 0) {
	return *tree;
    }
}

void print_helper(Node* node, int space) 
{  
    if (node == NULL) 
        return; 
  
    space += 10; 
  
    print_helper(node->right, space); 
  
    printf("\n"); 
    for (int i = 10; i < space; i++) 
        printf(" "); 
    printf("%s\n", node->key); 
  
    print_helper(node->left, space); 
} 
  
void resource_print(Node *root) 
{ 
  print_helper(root, 0); 
} 
