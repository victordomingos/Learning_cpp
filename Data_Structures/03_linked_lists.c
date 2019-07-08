// Exercise on linked lists


#include <stdio.h>
#include <stdlib.h>


typedef struct node_structure
{
    int data;
    struct node_structure *next;
} *node;


node createNode(int value)
{
    node newNode = (node) malloc(sizeof(node));
    if (newNode != NULL)
    {
        newNode->data = value;
        newNode->next = NULL;
    }
    return newNode;
}

void displayLinkedList(node linked_list)
{    
    node cursor = linked_list;
    while (cursor != NULL)
    {
        printf("%d\n", cursor->data);
        cursor=cursor->next;
    }
    printf("---\n");
}


int main()
{
    node head = createNode(10);
    node tail = head;

    displayLinkedList(head);


    //Insert at head
    node newHead = createNode(8);
    if(newHead != NULL)
    {
        newHead->next = head;
        head = newHead;
    }
    displayLinkedList(head);


    //Insert at tail
    node newTail = createNode(15);
    if(newTail != NULL)
    {
        tail->next = newTail;
        tail = newTail;
    }
    displayLinkedList(head);
    
    
    //Insert inside  body
    


    //Remove from head



    //Remove from tail



    //Remove from body

    return 0;
}
