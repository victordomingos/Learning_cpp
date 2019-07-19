// Exercise on queues
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


void displayQueue(node *queue)
{    
    int usedMemory = 0;
    int unitSize = sizeof(**queue);

    node cursor = *queue;
    while (cursor != NULL)
    {
        printf("%d  ", cursor->data);
        cursor=cursor->next;
        usedMemory += unitSize;
    }
    printf("\n==== Using %d bytes ====\n\n", usedMemory);
}


// Add a new element to the end of the queue
int enqueue(node *head, node *tail, int value)
{
    node newElement = createNode(value);

    if(newElement != NULL)
    {
        if (head == NULL)
        {
            (*head) = newElement;
            (*tail) = newElement;
        }
        else
        {
            (*tail)->next = newElement;
            (*tail) = (*tail)->next;
        }
        return 0;
    }
    else return 1;
}



// Get and remove the first queue element (== linked list head)
node dequeue(node *head, node *tail)
{
    node cursor = NULL;

    if (*head==*tail) // Is it a single element list?
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        cursor = *head;
        (*head) = (*head)->next;
        cursor->next = NULL;
    }
    return cursor;
}


int main()
{
    printf("\nCreating a new linked list based queue (first in, first out).\n");
    node head = createNode(10);
    node tail = head;
    printf("HEAD: %p \tTAIL: %p\n", (void *)head, (void *)tail);
    displayQueue(&head);


    printf("\nAdding 10 elements to the end of the queue.\n");
    for(int i = 0; i < 10; i++)
        enqueue(&head, &tail, i);

    printf("HEAD: %p \tTAIL: %p\n", (void *)head, (void *)tail);
    displayQueue(&head);


    printf("\nRemoving the first element.\n");
    dequeue(&head, &tail);
    printf("HEAD: %p \tTAIL: %p\n", (void *)head, (void *)tail);
    displayQueue(&head);
    
    printf("\nAdding 10 elements to the end of the queue.\n");
    for(int i = 100; i < 110; i++)
        enqueue(&head, &tail, i);

    printf("HEAD: %p \tTAIL: %p\n", (void *)head, (void *)tail);
    displayQueue(&head);


    printf("\nRemoving the first 15 elements.\n");
    for(int i = 0; i < 15; i++)
        dequeue(&head, &tail);

    printf("HEAD: %p \tTAIL: %p\n", (void *)head, (void *)tail);
    displayQueue(&head);



    printf("\nRemoving the remaining elements.\n");
    while (head != NULL)
    {
        printf("HEAD: %p \tTAIL: %p\n", (void *)head, (void *)tail);
        dequeue(&head, &tail);
        displayQueue(&head);
    }


    return 0;
}
