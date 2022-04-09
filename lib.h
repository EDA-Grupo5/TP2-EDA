#ifndef _LIB_H
#define _LIB_H
typedef struct BinarySearchTree{
    int key;
    int fatbal;
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
}node;

// create a new node to be inserted into the tree
node * nodeCreate(int key);

// insert a new node into the tree
node * treeInsert(node * root, int key);

// print the tree in order
void treePrint(node * root);

// free the memory of the node
void treeFree(node * root);

#endif

