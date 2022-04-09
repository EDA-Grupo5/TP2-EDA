#ifndef _LIB_H
#define _LIB_H
typedef struct BinarySearchTree{
    int key;
    int fatbal;
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
}node;

// create a new node to be inserted into the tree
node * create_node(int key);

// print the key of the node
void print_node(node * root);

#endif

