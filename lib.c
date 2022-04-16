#include "lib.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

// functions about menu - 1
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





// functions about file manipulation - 2
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

node *readCSV(char * filename, node * root){
    FILE *file = (FILE *)fopen(filename, "r");
    file = fopen(filename, "r");
    if(file == NULL){
        printf("The file %s does not exist.\n", filename);
        return root;
    }
    char line[100];
    char *token;
    int i = 0;
    while(fgets(line, 100, file) != NULL){
        token = strtok(line, ",");
        while(token != NULL){
            if(i == 0){
                root = treeInsert(root, atoi(token));
            }
            else{
                root = treeInsert(root, atoi(token));
            }
            token = strtok(NULL, ",");
            i++;
        }
        i = 0;
    }

    free(file);
    fclose(file);
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
    node * root = (node *)malloc(sizeof(node));
    root = NULL;
    //createFile("test.txt");
    root = readCSV("test.txt", root);
    if (root == NULL)
    {
        printf(">>Oops! The root has not been modified.\n");
        printf(">>Please, review the function 'readFile' to fix this bug.\n");
    }
    else{
        printf(">>The root has been modified.\n");
        printf(">>Full tree:\n");
        imprimir(root,1);
        printf(">>\n>>>Now the balance factor is being calculated\n");
        treeCalculateFatBal(root);
        treePrintFatbal(root);
        //printExample3(root);
        treeFree(root);
    }
}






// functions about binary search tree - 3
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

void treePrintFatbal(node * root)
{
    if (root != NULL){
        
        treePrintFatbal(root->left);
        printf("Key: %d ", root->key);
        printf("Fatbal: %d \n", root->fatbal);
        treePrintFatbal(root->right);
    }
}

void imprimir(node *root, int nivel){ 
    int i; 
    if(root){ 
        imprimir(root->right, nivel + 1); 
        printf("\n\n"); 
        for(i = 0; i < nivel; i++) 
            printf("\t"); 
        printf("%d", root->key);  
        imprimir(root->left, nivel + 1); 
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
<<<<<<< HEAD
    node *root =(node *) malloc(sizeof(node)*30);
=======
    node *root =(node *) malloc(sizeof(node));
    int nm[] = {40,54,1082,678,8674,8789,990,7642,9762,2345,34,897,182,9876};
    int i;
>>>>>>> b208ba1927d6acda41354e582546c73cb69581bc
    root = nodeCreate(40);
    for(i = 1; i< 14; i++){
        root = treeInsert(root, nm[i]);
    }
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






// functions about AVL tree - 4
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








