#include <stdio.h>
#include <stdlib.h>


typedef struct node_structure {
	int data;
	struct node_structure *prev;
	struct node_structure *next;
} *node;


node createNode(int value) {
	node newNode = (node) malloc(sizeof(node));
	if (newNode != NULL) {
		newNode->data = value;
		newNode->prev = NULL;
		newNode->next = NULL;
	}
	return newNode;
}


void displayLinkedList(node linked_list) {
	node cursor = linked_list;
	while (cursor != NULL) {
		printf("DATA: %d \tTHIS:%p \tPREV:%p \tNEXT:%p\n", cursor->data, (void*)cursor, (void *)cursor->prev, (void *)cursor->next);
		cursor=cursor->next;
	}
}


int insertAtHead(node *head, int value) {
	node newHead = createNode(value);
	if(newHead != NULL) {
		(*head)->prev = newHead;
		newHead->next = *head;
		*head = newHead;
		return 0;
	}
	else return 1;
}


int main() {
	printf("\nCreating a single element linked list.\n");
	node head = createNode(10);
	displayLinkedList(head);
	
	printf("\nInserting 10 elements at head.\n");
	for(int i = 0; i < 10; i++) { 
		insertAtHead(&head, 8); 
	}
	displayLinkedList(head);
		
	return 0;
}

