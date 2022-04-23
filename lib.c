#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MENU AND YOURS FUNCTIONS

void menu1_official(void)
{
    int option = 0;
    // int again = 1;
    node *root = NULL;

    do
    {
        printf("SELECT THE TEST YOU WANT TO RUN:\n");
        // Reads a CSV file and generates an ABP containing all the keys contained in it
        printf("1. GENERATE BINARY SEACH TREE - (Gerar ABP) \n");
        // Calculate and Stores the Balancing Factor of each node in its respective FatBal field
        printf("2. CALCULATE BALACING FACTOR - (Calcular Fator de balanceamento)\n");
        // Print the Key and FatBal of ABP nodes in ascending order
        printf("3. PRINTING BINARY SEACH TREE - (Imprimir ABP)\n");
        // Leave the program deallocating the nodes
        printf("4. EXIT THE PROGRAM - (Sair)\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nGenerating Binary Tree... \n ");
            root = official_options_1(root);
            if (root == NULL)
            {
                printf("Empty Tree/Node");
            }
            else
            {
                printf("Binary Tree Generated!\n\n");
            }
            break;
        case 2:
            printf("\nCalculating Balacing Factor Binary Tree...\n ");
            official_options_2(root);
            printf("Balacing Factor Binary Tree Calculated.\n\n");
            break;
        case 3:
            printf("\nPrinting Binary Tree... \n");
            official_options_3(root);
            break;
        case 4:
            printf("\nExiting program...\n");
            treeFree(root);
            // Deallocating remaining memory garbage from root
            if (root != NULL)
            {
                root = NULL;
            }
            break;
        default:
            printf("\nError! Input not Valid.\n");
            break;
        }

    } while (option != 4);
}

node *official_options_1(node *root)
{
    char nameArchive[100]; // Variable for store name of archive
    printf("Write name of archive: ");
    scanf("%s", nameArchive); // Expression for read at maximium 100 characters
    root = readCSV(nameArchive, root);
    if (root == NULL)
    {
        printf(">>Oops! The root has not been modified.\n");
        printf(">>Please, review the function 'readFile' to fix this bug.\n");
    }
    else
    {
        printf(">>The Binary Seaching Tree Has been Genareted.\n");
        return root;
    }
}

void official_options_2(node *root)
{
    treeCalculateFatBal(root);
}

void official_options_3(node *root)
{
    treePrintFatbal(root);
    printf("\n");
    printf(">>Full tree:\n");
    printTree(root, 1);
    printf("\n");
}

// FUNCTIONS IN GENERAL

// functions about file manipulation - 2
int fileExists(char *fileName)
{
    FILE *file;
    file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("The file %s does not exist.\n", fileName);
        return 0;
    }
    fclose(file);
    printf("The file %s exists.\n", fileName);
    return 1;
}

int fileIsEmpty(char *fileName)
{
    FILE *file;
    file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("The file %s does not exist.\n", fileName);
        return 0;
    }
    if (fgetc(file) == EOF)
    {
        printf("The file %s is empty.\n", fileName);
        return 1;
    }
    fclose(file);
    printf("The file %s is not empty.\n", fileName);
    return 0;
}

node *readFile(char *fileName, node *root)
{
    FILE *file;
    int key;
    file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("The file %s does not exist.\n", fileName);
        return root;
    }
    while (fscanf(file, "%d", &key) != EOF)
    {
        root = treeInsert(root, key);
    }
    fclose(file);
    printf("The file %s was read.\n", fileName);
    return root;
}

node *readCSV(char *filename, node *root)
{
    FILE *file = (FILE *)fopen(filename, "r");
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("The file %s does not exist.\n", filename);
        return root;
    }
    char line[100];
    char *token;
    int i = 0;
    // Select data to store in the array
    while (fgets(line, 100, file) != NULL)
    {
        token = strtok(line, ",");
        while (token != NULL)
        {
            if (i == 0)
            {
                root = treeInsert(root, atoi(token));
            }
            else
            {
                root = treeInsert(root, atoi(token));
            }
            token = strtok(NULL, ",");
            i++;
        }
        i = 0;
    }
    fclose(file);
    return root;
}

void createFile(char *fileName)
{
    FILE *file;
    file = fopen(fileName, "w");
    if (file == NULL)
    {
        printf("The file %s could not be created.\n", fileName);
        return;
    }
    fclose(file);
    printf("The file %s was created.\n", fileName);
}

// functions about binary search tree - 3
node *nodeCreate(int key)
{
    node *new_node = (node *)calloc(4, sizeof(node));
    new_node->key = key;
    new_node->fatbal = 0;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert node into the tree
node *treeInsert(node *root, int key)
{
    if (root == NULL)
    {
        return nodeCreate(key);
    }
    else if (key < root->key)
    {
        root->left = treeInsert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = treeInsert(root->right, key);
    }
    else
    {
        printf("Duplicate key: %d\n", key);
        return root;
    }
    return root;
}

// Search for node in the tree
node *treeFind(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (key < root->key)
    {
        return treeFind(root->left, key);
    }
    else if (key > root->key)
    {
        return treeFind(root->right, key);
    }
    else
    {
        return root;
    }
}

// Prints the tree number
void treeNumberPrint(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        treeNumberPrint(root->left);
        treeNumberPrint(root->right);
    }
}

// Prints the key and the fatbal
void treePrintFatbal(node *root)
{
    if (root != NULL)
    {

        treePrintFatbal(root->left);
        printf("Key: %d ", root->key);
        printf("Fatbal: %d \n", root->fatbal);
        treePrintFatbal(root->right);
    }
}

// Prints the tree
void printTree(node *root, int level)
{
    int i;
    if (root)
    {
        printTree(root->right, level + 1);
        printf("\n\n");
        for (i = 0; i < level; i++)
            printf("\t");
        printf("%d", root->key);
        printf(" (%d)", root->fatbal);
        printTree(root->left, level + 1);
    }
}

// Realizes the deallocation of the tree
void treeFree(node *root)
{
    if (root != NULL)
    {
        treeFree(root->left);
        treeFree(root->right);
        free(root);
    }
}

// Functions about AVL tree - 4
int treeHeight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int left_height = treeHeight(root->left);
        int right_height = treeHeight(root->right);
        if (left_height > right_height)
        {
            return left_height + 1;
        }
        else
        {
            return right_height + 1;
        }
    }
}

// Calculates the fatbal
void treeCalculateFatBal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        int left_height = treeHeight(root->left);
        int right_height = treeHeight(root->right);
        root->fatbal = left_height - right_height;
        treeCalculateFatBal(root->left);
        treeCalculateFatBal(root->right);
    }
}
/*
// FUNCTIONS TESTS

// functions about menu - 1
void test_menu(void)
{
    int again = 1;
    int option = 0;
    printf("SELECT THE TEST YOU WANT TO RUN:\n"); // Gera ABP e Imprime ABP
    printf("1. Test example 1 - FUNCTIONS ABOUT BINARY SEARCH TREE \n");
    printf("2. Test example 2 - FUNCTIONS ABOUT AVL TREE\n"); // Calcula Fator de Balanceamento
    printf("3. Test example 3 - FUNCTIONS ABOUT FILE\n");     // Gera ABP e Imprime ABP
    printf("4. Exit - EXIT THE PROGRAM\n");                   // Sair
    scanf("%d", &option);
    if (option == 1)
    {
        printf("\n>>>TEST EXAMPLE 1 IS RUNNING\n");
        test_example_1();
        printf("\n>>>TEST EXAMPLE 1 IS FINISHED\n");
        printf("\n>>>DO YOU WANT TO RUN ANOTHER TEST?\n");
        printf("1. YES\n");
        printf("2. NO\n");
        scanf("%d", &again);
        if (again == 1)
        {
            test_menu();
        }
        else
        {
            printf("\n>>>THANK YOU FOR USING THE PROGRAM\n");
            exit(0);
        }
    }
    else if (option == 2)
    {
        printf("\n>>>TEST EXAMPLE 2 IS RUNNING\n");
        test_example_2();
        printf("\n>>>TEST EXAMPLE 2 IS FINISHED\n");
        printf("\n>>>DO YOU WANT TO RUN ANOTHER TEST?\n");
        printf("1. YES\n");
        printf("2. NO\n");
        scanf("%d", &again);
        if (again == 1)
        {
            test_menu();
        }
        else
        {
            printf("\n>>>THANK YOU FOR USING THE PROGRAM\n");
            exit(0);
        }
    }
    else if (option == 3)
    {
        printf("\n>>>TEST EXAMPLE 3 IS RUNNING\n");
        test_example_3();
        printf("\n>>>TEST EXAMPLE 3 IS FINISHED\n");
        printf("\n>>>DO YOU WANT TO RUN ANOTHER TEST?\n");
        printf("1. YES\n");
        printf("2. NO\n");
        scanf("%d", &again);
        if (again == 1)
        {
            test_menu();
        }
        else
        {
            printf("\n>>>THANK YOU FOR USING THE PROGRAM\n");
            exit(0);
        }
    }
    else if (option == 4)
    {
        printf("\n>>>EXITING THE PROGRAM\n");
        exit(0);
    }
    else
    {
        printf("\n>>>WRONG INPUT\n");
        test_menu();
    }
}

void test_example_1()
{
    node *root = NULL;
    int arrayRoot[15] = {40, 54, 1082, 678, 8674, 87, 89, 990, 7642, 9762, 2345, 34, 897, 182, 9876};

    for (int i = 0; i < 15; i++)
    {
        root = treeInsert(root, arrayRoot[i]);
    }

    printf(">>> FULL TREE:\n");
    printTree(root, 1);

    printf("\n>>> TREE WHEN THE ROOT IS 8674:\n");
    treeNumberPrint(treeFind(root, 8674));

    printf("\n>>> TREE WHEN THE ROOT IS 678:\n");
    treeNumberPrint(treeFind(root, 678));

    printf("\n>>> FINISH TEST\n");

    treeFree(root);
}

void test_example_2()
{
    node *root = NULL;
    int arrayRoot[15] = {40, 54, 1082, 678, 8674, 87, 89, 990, 7642, 9762, 2345, 34, 897, 182, 9876};

    for (int i = 0; i < 15; i++)
    {
        root = treeInsert(root, arrayRoot[i]);
    }

    printf("\n>>> FATBAL BEFORE CALCULATION:\n");
    treePrintFatbal(root);
    printf(">>> FULL TREE:\n");
    printTree(root, 1);
    printf("\n");

    printf(">>> FATBAL AFTER CALCULATION:\n");
    treeCalculateFatBal(root);
    treePrintFatbal(root);
    printf("\n");

    printf(">>> FULL TREE:\n");
    printTree(root, 1);

    printf("\n>>> FINISH TEST\n");

    treeFree(root);
}

void test_example_3()
{
    node *root = NULL;
    // createFile("test.txt");
    char nameArchive[100]; // Variable for store name of archive
    scanf("%c");           // Scanf to catch buffer \n
    printf("Write name of archive: ");
    scanf("%100[^\n]", nameArchive); // expression for read at maximium 100 characters
    root = readCSV(nameArchive, root);
    if (root == NULL)
    {
        printf(">>Oops! The root has not been modified.\n");
        printf(">>Please, review the function 'readFile' to fix this bug.\n");
    }
    else
    {
        printf(">>The root has been modified.\n");
        printf(">>Full tree:\n");
        printTree(root, 1);
        printf("\n\n>>>Now the balance factor is being calculated\n");
        treeCalculateFatBal(root);

        printf(">>Full tree:\n");
        printTree(root, 1);
        printf("\n");
        treePrintFatbal(root);
        treeFree(root);
    }
}

*/