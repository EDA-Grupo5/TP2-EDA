#include <stdio.h>
#include <stdlib.h>
#include "lib.c"

int main (void)
{
    node * root = nodeCreate(10);
    root = treeInsert(root, 5);
    root = treeInsert(root, 20);
    root = treeInsert(root, 4);
    root = treeInsert(root, 6);
    root = treeInsert(root, 21);
    root = treeInsert(root, 19);
    treePrint(root);
    treeFree(root);
    return 0;
}