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


node addNode(node root, int value)
{
    node newNode = createNode(value);

    if(root == NULL)
        root = newNode; // Creating 1st element, so newNode must become the root.
    else
    {
        if (value < root->data)
            addNode(root->left, value);
        else
            addNode(root->right, value);
    }
    return root;
}


void showTree(node root)
{

    if(root == NULL)
        {
            printf("== No mode elements ==\n");
        }
    else
        if(root->left != NULL)
            showTree(root->left);
        if(root->right != NULL)
            showTree(root->right);
            //TODO




    {
        if (value < root->data)
            addNode(root->left, value);
        else
            addNode(root->right, value);
    }
    return root;
}


int main()
{
    printf("\nCreating a single element linked list.\n");
    node root = NULL;
    root = addNode(root, 10);
    printf("ROOT - D: %d \tL: %p \tR: %p\n", root->data, (void *)root->left, (void *)root->right);
    root = addNode(root, 8);
    printf("ROOT - D: %d \tL: %p \tR: %p\n", root->data, (void *)root->left, (void *)root->right);
    
    root = addNode(root, 15);
    printf("ROOT - D: %d \tL: %p \tR: %p\n", root->data, (void *)root->left, (void *)root->right);
    return 0;
}
