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
        printf("%d  ", cursor->data);
        cursor=cursor->next;
        usedMemory += unitSize;
    }
    printf("\n- Used %d bytes -\n", usedMemory);
    
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
    printf("\n\nCreating a single element linked list.\n");
    node head = createNode(10);
    node tail = head;
    node cursor;

    
    displayLinkedList(head);

    printf("\n\nInsert 10 elements at head\n");
    for(int i = 0; i < 10; i++)
    {
        node p = insertAtHead(head, 8);
        if (p != NULL)
            head = p;
    }

    displayLinkedList(head);


    printf("\n\nInsert one at tail\n");
    node newTail = createNode(15);
    if(newTail != NULL)
    {
        tail->next = newTail;
        tail = newTail;
    }
    displayLinkedList(head);
    
    
    printf("\n\nInserting one inside body, in crescent order.\n");
    node newBodyNode = createNode(12);
    for(cursor = head; cursor->next->data < newBodyNode->data; cursor=cursor->next)
    {
        // Empty loop, just to set the cursor pointer to the intended position.
    }

    newBodyNode->next = cursor->next;
    cursor->next = newBodyNode;
    displayLinkedList(head);


    printf("\n\nRemoving one from head.\n");
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



    printf("\n\nRemoving one from tail.\n");
    if (head==tail) // Clean a single element list
    {
        free(head);
        head=NULL;
        tail=NULL;
    }
    else
    {
        cursor = head;

        while (cursor->next->next != NULL)
            cursor = cursor->next;
        
        free(tail);
        cursor->next = NULL;
        tail = cursor;
    }
    displayLinkedList(head);



    //Remove from body
    printf("\n\nRemoving one from body where value == 10.\n");
    
    cursor = head;
    printf("cursor: %d", cursor->data);  


    while (cursor->next->data != 10 && cursor->next->next != NULL)
        cursor = cursor->next;
    
    if (cursor->next->data == 10)
    {
        node p = cursor->next;
        cursor->next = cursor->next->next;
        free(p);
    }
    displayLinkedList(head);

    return 0;
}
