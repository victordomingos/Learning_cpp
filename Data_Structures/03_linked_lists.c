// Exercise on linked lists
// 2019 Victor Domingos

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


void displayLinkedList(node *linked_list)
{    
    int usedMemory = 0;
    int unitSize = sizeof(**linked_list);

    node cursor = *linked_list;
    while (cursor != NULL)
    {
        printf("%d  ", cursor->data);
        cursor=cursor->next;
        usedMemory += unitSize;
    }
    printf("\n==== Using %d bytes ====\n\n", usedMemory);
}


int insertAtHead(node *head, int value)
{
    node newHead = createNode(value);
    if(newHead != NULL)
    {
        newHead->next = *head;
        *head = newHead;
        return 0;    
    }
    else return 1;
}


int insertAtTail(node *head, node *tail, int value)
{
    node newTail = createNode(value);
    if(newTail != NULL)
    {
        (*tail)->next = newTail;
        (*tail) = newTail;
        return 0;
    }
    else return 1;
}


int removeFirstOccurrence(node *head, int value )
{
    node cursor = *head;

    while (cursor->next->data != value && cursor->next->next != NULL)
        cursor = cursor->next;
    
    if (cursor->next->data == value)
    {
        node p = cursor->next;
        cursor->next = cursor->next->next;
        free(p);
    }
    return 0;
}


int insertInAscendingOrder(node *head, node *tail, int value)
{
    node cursor;
    node newBodyNode = createNode(value);
    for(cursor = *head; cursor->next->data < newBodyNode->data; cursor=cursor->next)
        { } // Empty loop, just to set the cursor pointer to the intended position. 

    newBodyNode->next = cursor->next;
    cursor->next = newBodyNode;
    return 0;
}


int removeFirstElement(node *head, node *tail)
{
    if (*head==*tail) // Is it a single element list?
    {
        free(*head);
        *head=NULL;
        *tail=NULL;
        return 1;
    }
    else
    {
        node p = (*head)->next;
        free(*head);
        *head = p;
        return 0;
    }
}


int removeLastElement(node *head, node *tail)
{
    node cursor;

    if (*head==*tail) // Is it a single element list?
    {
        free(*head);
        head=NULL;
        tail=NULL;
        return 1;
    }
    else
    {
        cursor = *head;

        while (cursor->next->next != NULL)
            cursor = cursor->next;
        
        free(*tail);
        cursor->next = NULL;
        *tail = cursor;
        return 0;
    }
}


int main()
{
    printf("\nCreating a single element linked list.\n");
    node head = createNode(10);
    node tail = head;
    displayLinkedList(&head);


    printf("\nInserting 10 elements at head.\n");
    for(int i = 0; i < 10; i++)  { insertAtHead(&head, 8); }
    displayLinkedList(&head);


    printf("\nInserting one at tail.\n");
    insertAtTail(&head, &tail, 15);
    displayLinkedList(&head);
    
    
    printf("\nInserting one inside body, in ascending order.\n");
    insertInAscendingOrder(&head, &tail, 12);
    displayLinkedList(&head);


    printf("\nRemoving one from head.\n");
    removeFirstElement(&head, &tail);
    displayLinkedList(&head);


    printf("\nRemoving one from tail.\n");
    removeLastElement(&head, &tail);
    displayLinkedList(&head);


    printf("\nRemoving one from body where value == 10.\n");
    removeFirstOccurrence(&head, 10);
    displayLinkedList(&head);

    return 0;
}
