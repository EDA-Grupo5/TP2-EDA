#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

node * nodeCreate(int key)
{
    node * new_node = (node *) malloc(sizeof(node));
    new_node->key = key;
    new_node->fatbal = 0;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node * treeInsert(node * root, int key){
    if(root == NULL){
        return nodeCreate(key);
    }
    else if(key < root->key){
        root->left = treeInsert(root->left, key);
    }
    else if(key > root->key){
        root->right = treeInsert(root->right, key);
    }
    else{
        printf("Duplicate key: %d\n", key);
        return root;
    }
    return root;
}

node * treeFind(node * root, int key){
    if(root == NULL){
        return NULL;
    }
    else if(key < root->key){
        return treeFind(root->left, key);
    }
    else if(key > root->key){
        return treeFind(root->right, key);
    }
    else{
        return root;
    }
}

void treePrint(node * root)
{
    if (root != NULL){
        printf("%d ", root->key);
        treePrint(root->left);
        treePrint(root->right);
    }
}

void treeFree(node * root){
    if (root != NULL){
        treeFree(root->left);
        treeFree(root->right);
        free(root);
    }
}




