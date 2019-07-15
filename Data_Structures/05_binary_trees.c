// Exercise on binary trees
// 2019 Victor Domingos

#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} *node;


node createNode(int value)
{
    node newNode = malloc(sizeof(struct node));
    if (newNode != NULL)
    {
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

/*
void displayTree(node *tree)
{    
    int usedMemory = 0;
    int unitSize = sizeof(**tree);
	int n = 0;
    node cursor = *linked_list;
    while (cursor != NULL)
    {
        printf("%d\t DATA: %d \tTHIS: %p \tPREV: %p \tNEXT: %p\n", n, cursor->data, (void*)cursor, (void *)cursor->prev, (void *)cursor->next);
        cursor=cursor->next;
        usedMemory += unitSize;
		n++;
    }
    printf("\n==== Using %d bytes ====\n\n", usedMemory);
}
*/

void showPreOrder(node root)
{
    if (root!=NULL)
    {
        printf("    %p DATA: %d \tLEFT: %p \tRIGHT: %p\n", (void *)root, root->data, (void *) root->left, (void *)root->right);
        showPreOrder(root->left);
        showPreOrder(root->right);
    }
}


node addNode(node root, int value)
{
    node newNode = createNode(value);
    
    if(root == NULL)
        return newNode; // Creating 1st element, so newNode must become the root.
    else
    {
        if (value < root->data)
            root->left = addNode(root->left, value);
        else
            root->right = addNode(root->right, value);
    return root;
    }
}



int main()
{
    printf("\nCreating a single element linked list.\n");
    node root = NULL;
    root = addNode(root, 10);
    showPreOrder(root);

    printf("\nInserting a new node (8)\n");
    root = addNode(root, 8);
    showPreOrder(root);

    printf("\nInserting a new node (15)\n");
    root = addNode(root, 15);
    showPreOrder(root);

    printf("\nInserting a new node (9)\n");
    root = addNode(root, 9);
    showPreOrder(root);
    

    printf("\nInserting a new node (11)\n");
    root = addNode(root, 11);
    showPreOrder(root);

    printf("\nInserting a new node (12)\n");
    root = addNode(root, 12);
    showPreOrder(root);

    return 0;
}
