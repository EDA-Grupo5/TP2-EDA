#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

node * create_node(int key)
{
    node * new_node = (node *) malloc(sizeof(node));
    new_node->key = key;
    new_node->fatbal = 10;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void print_node(node * root)
{
    printf("Key: %d\n", root->key);
    printf("Fatbal: %d\n", root->fatbal);
}
