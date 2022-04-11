#ifndef _LIB_H
#define _LIB_H
typedef struct BinarySearchTree{
    int key;
    int fatbal;
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
}node;

// **************** FUNCTIONS - BINARY SEARCH TREE **************** //

// create a new node to be inserted into the tree
node * nodeCreate(int key);
// insert a new node into the tree
node * treeInsert(node * root, int key);
// print the tree in order
void treePrint(node * root);
// free the memory of the node
void treeFree(node * root);
// find the node with the given key
node * treeFind(node * root, int key);
//  function that balances a binary search tree
node * balanceTree(node * root);
// testing the functions with the first teacher pdf example
void test_example_1();

// **************** FUNCTIONS - AVL TREE **************** //

// find the height of the tree
int height(node * root);

// function that calculates the balance factor and stores in fatbal 
void treeCalculateFatBal(node * root);

// function that test the functions about the AVL tree
void test_example_2();

#endif

