#ifndef _LIB_H
#define _LIB_H
typedef struct BinarySearchTree
{
    int key;
    int fatbal;
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
} node;

// **************** FUNCTIONS - OFFICIAL MENU **************** //

void menu1_official(void);

// function menus official

node *official_options_1(node *root); // Menu to generate binary tree at CSV
void official_options_2(node *root);  // Calculate FatBal
void official_options_3(node *root);  // Print binary tree
//void official_options_5(node *root, int key); // Find a root in a tree 

// **************** FUNCTIONS - MANIPULATION OF FILE **************** //

// Verifies if the file exists
int fileExists(char *fileName);
// Verifies if the file is empty
int fileIsEmpty(char *fileName);
// read the file and add the content to the tree
node *readFile(char *fileName, node *root);
// read the csv file and add the content to the binary search tree
node *readCSV(char *fileName, node *root);
// create a new file with the name given as parameter
void createFile(char *fileName);

// **************** FUNCTIONS - BINARY SEARCH TREE **************** //
// create a new node to be inserted into the tree
node *nodeCreate(int key);
// insert a new node into the tree
node *treeInsert(node *root, int key);
// find the node with the given key
node *treeFind(node *root, int key);
// print the tree in order
void treeNumberPrint(node *root);
// print the fatbal of each node
void treePrintFatbal(node *root);
// free the memory of the node
void treeFree(node *root);
//  function that balances a binary search tree
node *balanceTree(node *root);
// function that calculate the height of the tree
int treeHeight(node *root);
// function that printing the format of tree
void printTree(node *root, int level);
// function that calculates the balance factor and stores in fatbal
void treeCalculateFatBal(node *root);

// **************** FUNCTIONS - TEST MENU **************** //
// the function returns the number of the test that the user wants to run

// void test_menu(void);
// void test_example_1();
// void test_example_2();
// void test_example_3();
#endif
