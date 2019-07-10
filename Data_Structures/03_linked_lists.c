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
    int usedMemory = 0;
    int unitSize = sizeof(*linked_list);

    node cursor = linked_list;
    while (cursor != NULL)
    {
        printf("%d\n", cursor->data);
        cursor=cursor->next;
        usedMemory += unitSize;
    }
    printf("-------- Used %d bytes --------\n", usedMemory);
    
}


node insertAtHead(node head, int value)
{
    node newHead = createNode(value);
    if(newHead != NULL)
    {
        newHead->next = head;
        head = newHead;
    }
    return head;    
}





int main()
{
    node head = createNode(10);
    node tail = head;
    node cursor;

    displayLinkedList(head);


    //Insert at head
    node p = insertAtHead(head, 8);
    if (p != NULL)
        head = p;

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
    node newBodyNode = createNode(12);
    for(cursor = head; cursor->next->data < newBodyNode->data; cursor=cursor->next)
    {
        // Empty loop, just to set the cursor pointer to the intended position.
    }

    newBodyNode->next = cursor->next;
    cursor->next = newBodyNode;
    displayLinkedList(head);


    //Remove from head
    if (head==tail) // Clean a single element list
    {
        free(head);
        head=NULL;
        tail=NULL;
    }
    else
    {
        node p = head->next;
        free(head);
        head = p;
    }
    displayLinkedList(head);



    //Remove from tail
    if (head==tail) // Clean a single element list
    {
        free(head);
        head=NULL;
        tail=NULL;
    }
    else
    {
        node p;
        cursor = head;

        while (cursor != NULL)
        {
            cursor = cursor->next;
        }
        p = cursor;
        free(tail);
        cursor->next = NULL;
        tail = cursor;
    }
    displayLinkedList(head);




    //Remove from body

    return 0;
}
