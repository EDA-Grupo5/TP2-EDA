#include <stdio.h>
#include <stdlib.h>
#include "lib.c"

int main (void)
{
    node * root = create_node(10);
    node * root2 = create_node(20);
    print_node(root);
    print_node(root2);
    free(root);
    free(root2);
    
    return 0;
}