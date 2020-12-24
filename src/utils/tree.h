#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct bin_tree {
    char *key;
    int value;
    struct bin_tree * right, * left;
};
typedef struct bin_tree tree_node;

void tree_insert(tree_node ** tree, char *key, int value);

void tree_print(tree_node * tree);

void tree_delete(tree_node * tree);

tree_node* tree_search(tree_node ** tree, char* key);
