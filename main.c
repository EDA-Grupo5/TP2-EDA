#include <stdio.h>
#include <stdlib.h>
#include "lib.c"

int main (void)
{
    node * root = nodeCreate(40);
    root = treeInsert(root, 54);
    root = treeInsert(root, 1082);
    root = treeInsert(root, 678);
    root = treeInsert(root, 8674);
    root = treeInsert(root, 87);
    root = treeInsert(root, 89);
    root = treeInsert(root, 990);
    root = treeInsert(root, 7642);
    root = treeInsert(root, 9762);
    root = treeInsert(root, 2345);
    root = treeInsert(root, 34);
    root = treeInsert(root, 897);
    root = treeInsert(root, 182);
    root = treeInsert(root, 9876);
    printf("\nFULL TREE:\n");
    treePrint(root);
    printf("\nSUB TREE WHEN THE KEY ARE 990\n");
    root = treeFind(root, 990);
    treePrint(root);
    printf("\nSUB TREE WHEN THE KEY ARE 1082\n");
    root = treeFind(root, 34);
    treeFree(root);
    return 0;
}