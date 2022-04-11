#include "lib.h" 
#include <stdio.h> 
#include <stdlib.h> 

// functions about menu
void test_menu(void){
    int again = 1;
    int option = 0;
    printf("SELECT THE TEST YOU WANT TO RUN:\n");
    printf("1. Test example 1 - FUNCTIONS ABOUT BINARY SEARCH TREE \n");
    printf("2. Test example 2 - FUNCTIONS ABOUT AVL TREE\n");
    printf("3. Test example 3 - FUNCTIONS ABOUT FILE\n");
    printf("4. Exit - EXIT THE PROGRAM\n");
    scanf("%d", &option);
    if(option == 1){
        printf("\n>>>TEST EXAMPLE 1 IS RUNNING\n");
        test_example_1();
        printf("\n>>>TEST EXAMPLE 1 IS FINISHED\n");
        printf("\n>>>DO YOU WANT TO RUN ANOTHER TEST?\n");
        printf("1. YES\n");
        printf("2. NO\n");
        scanf("%d", &again);
        if(again == 1){
            test_menu();
        }
        else{
            printf("\n>>>THANK YOU FOR USING THE PROGRAM\n");
            exit(0);
        }
    }
    else if(option == 2){
        printf("\n>>>TEST EXAMPLE 2 IS RUNNING\n");
        test_example_2();
        printf("\n>>>TEST EXAMPLE 2 IS FINISHED\n");
        printf("\n>>>DO YOU WANT TO RUN ANOTHER TEST?\n");
        printf("1. YES\n");
        printf("2. NO\n");
        scanf("%d", &again);
        if(again == 1){
            test_menu();
        }
        else{
            printf("\n>>>THANK YOU FOR USING THE PROGRAM\n");
            exit(0);
        }        
    }
    else if(option == 3){
        printf("\n>>>TEST EXAMPLE 3 IS RUNNING\n");
        test_example_3();
        printf("\n>>>TEST EXAMPLE 3 IS FINISHED\n");
        printf("\n>>>DO YOU WANT TO RUN ANOTHER TEST?\n");
        printf("1. YES\n");
        printf("2. NO\n");
        scanf("%d", &again);
        if(again == 1){
            test_menu();
        }
        else{
            printf("\n>>>THANK YOU FOR USING THE PROGRAM\n");
            exit(0);
        }
    }
    else if(option == 4){
        printf("\n>>>EXITING THE PROGRAM\n");
        exit(0);
    }
    else{
        printf("\n>>>WRONG INPUT\n");
        test_menu();
    }
}

// functions about file manipulation
int fileExists(char *fileName){
    FILE *file;
    file = fopen(fileName, "r");
    if(file == NULL){
        printf("The file %s does not exist.\n", fileName);
        return 0;
    }
    fclose(file);
    printf("The file %s exists.\n", fileName);
    return 1;
}

int fileIsEmpty(char *fileName){
    FILE *file;
    file = fopen(fileName, "r");
    if(file == NULL){
        printf("The file %s does not exist.\n", fileName);
        return 0;
    }
    if(fgetc(file) == EOF){
        printf("The file %s is empty.\n", fileName);
        return 1;
    }
    fclose(file);
    printf("The file %s is not empty.\n", fileName);
    return 0;
}

node * readFile(char *fileName, node * root){
    FILE *file;
    int key;
    file = fopen(fileName, "r");
    if(file == NULL){
        printf("The file %s does not exist.\n", fileName);
        return root;
    }
    while(fscanf(file, "%d", &key) != EOF){
        root = treeInsert(root, key);
    }
    fclose(file);
    printf("The file %s was read.\n", fileName);
    return root;
}

void createFile(char *fileName){
    FILE *file;
    file = fopen(fileName, "w");
    if(file == NULL){
        printf("The file %s could not be created.\n", fileName);
        return;
    }
    fclose(file);
    printf("The file %s was created.\n", fileName);
}

void test_example_3(){
    node * root = NULL;
    createFile("test.txt");
    root = readFile("test.txt", root);
    treePrint(root);
    treeFree(root);
}

// functions about binary search tree
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

void test_example_1(void){
    node *root;
    root = nodeCreate(40);
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
    printf("\n>>>FULL TREE:\n");
    treePrint(root);
    printf("\n>>>SUB TREE WHEN THE KEY ARE 8674\n");
    treePrint(treeFind(root, 8674));
    printf("\n>>>SUB TREE WHEN THE KEY ARE 678\n");
    treePrint(treeFind(root, 678));
    printf("\n>>>TEST FINISHED\n");
    printf(">>>FULL TREE HIGH: %d\n", treeHeight(root));
    printf(">>>8674 TREE HIGH: %d\n", treeHeight(treeFind(root, 8674)));
    treeFree(root);
}

// functions about AVL tree
int treeHeight(node * root){
    if(root == NULL){
        return 0;
    }
    else{
        int left_height = treeHeight(root->left);
        int right_height = treeHeight(root->right);
        if(left_height > right_height){
            return left_height + 1;
        }
        else{
            return right_height + 1;
        }
    }
}

void treeCalculateFatBal(node * root){
    if(root == NULL){
        return;
    }
    else{
        int left_height = treeHeight(root->left);
        int right_height = treeHeight(root->right);
        root->fatbal = left_height - right_height;
        treeCalculateFatBal(root->left);
        treeCalculateFatBal(root->right);
    }
} 

void test_example_2(void){
    node *root;
    root = nodeCreate(40);
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
    printf("\n>>>FULL TREE:\n");
    treePrint(root);    

    printf("\n>>> BEFORE BALANCE\n");
    printf("fatbal node 40: %d\n", treeFind(root, 40)->fatbal);
    printf("fatbal node 54: %d\n", treeFind(root, 54)->fatbal);
    printf("fatbal node 1082: %d\n", treeFind(root, 1082)->fatbal );
    printf("fatbal node 678: %d\n", treeFind(root, 678)->fatbal);
    printf("fatbal node 8674: %d\n", treeFind(root, 8674)->fatbal);
    printf("fatbal node 87: %d\n", treeFind(root, 87)->fatbal);
    printf("fatbal node 89: %d\n", treeFind(root, 89)->fatbal);
    printf("fatbal node 990: %d\n", treeFind(root, 990)->fatbal);
    printf("fatbal node 7642: %d\n", treeFind(root, 7642)->fatbal);
    printf("fatbal node 9762: %d\n", treeFind(root, 9762)->fatbal);
    printf("fatbal node 2345: %d\n", treeFind(root, 2345)->fatbal);
    printf("fatbal node 34: %d\n", treeFind(root, 34)->fatbal);
    printf("fatbal node 897: %d\n", treeFind(root, 897)->fatbal);
    printf("fatbal node 182: %d\n", treeFind(root, 182)->fatbal);
    printf("fatbal node 9876: %d\n", treeFind(root, 9876)->fatbal);

    printf("\n>>> AFTER BALANCE\n");
    treePrint(root);
    treeCalculateFatBal(root);
    printf("\nfatbal node 40: %d\n", treeFind(root, 40)->fatbal);
    printf("fatbal node 54: %d\n", treeFind(root, 54)->fatbal);
    printf("fatbal node 1082: %d\n", treeFind(root, 1082)->fatbal );
    printf("fatbal node 678: %d\n", treeFind(root, 678)->fatbal);
    printf("fatbal node 8674: %d\n", treeFind(root, 8674)->fatbal);
    printf("fatbal node 87: %d\n", treeFind(root, 87)->fatbal);
    printf("fatbal node 89: %d\n", treeFind(root, 89)->fatbal);
    printf("fatbal node 990: %d\n", treeFind(root, 990)->fatbal);
    printf("fatbal node 7642: %d\n", treeFind(root, 7642)->fatbal);
    printf("fatbal node 9762: %d\n", treeFind(root, 9762)->fatbal);
    printf("fatbal node 2345: %d\n", treeFind(root, 2345)->fatbal);
    printf("fatbal node 34: %d\n", treeFind(root, 34)->fatbal);
    printf("fatbal node 897: %d\n", treeFind(root, 897)->fatbal);
    printf("fatbal node 182: %d\n", treeFind(root, 182)->fatbal);
    printf("fatbal node 9876: %d\n", treeFind(root, 9876)->fatbal);

    printf("\n>>>TEST FINISHED\n");

    treeFree(root);
}
