#include "tree.h"

void tree_insert(tree_node ** tree, char *key, int value)
{
    tree_node *temp = NULL;
    if(!(*tree)) {
	printf("adding '%s' to list\n", key);
        temp = (tree_node *)malloc(sizeof(tree_node));
        temp->left = temp->right = NULL;
        temp->key = key;
	temp->value = value;
        *tree = temp;
        return;
    }

    if (strcmp(key, (*tree)->key) < 0) {
	tree_insert(&(*tree)->left, key, value);
    } else if (strcmp(key, (*tree)->key) > 0) {
	tree_insert(&(*tree)->right, key, value);
    }
}

void tree_print(tree_node * tree)
{
    if (tree) {
        tree_print(tree->left);
        printf("%s: %d\n",tree->key, tree->value);
        tree_print(tree->right);
    }
}

void tree_delete(tree_node * tree)
{
    if (tree) {
        tree_delete(tree->left);
        tree_delete(tree->right);
        free(tree);
    }
}

tree_node* tree_search(tree_node ** tree, char* key) {
    if(!(*tree)) return NULL;

    if (strcmp(key, (*tree)->key) > 0) {
	tree_search(&(*tree)->right, key);
    } else if (strcmp(key, (*tree)->key) < 0) {
	tree_search(&(*tree)->left, key);
    } else if (strcmp(key, (*tree)->key) == 0) {
	return *tree;
    }
}
