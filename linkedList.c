#include <stdlib.h>
#include <stdio.h>
#include "./linkedList.h"

// Helper function to create a new empty node.
Node *createNode(char datas[3]) {
    Node *lol = malloc(sizeof(Node));

    if (lol != NULL) {
        lol->data[0] = datas[0]; 
        lol->data[1] = datas[1];  
        lol->data[2] = '\0';
        lol->next = NULL;
    }
    return lol;
}

// Add to the top of the list and update head.
void add(char data[3], Node **head) {

    Node *newNode = createNode(data);

    if (newNode != NULL) {
        newNode->next = *head;

        *head = newNode;
    }
}

// TODO figure out how to do a pop() method instead and return the top element
// Removes the top.
int removeTop(Node **head) {

    if (head == NULL || *head == NULL) {
        return 0;
    }

    Node *oldHead = *head;
    *head = (*head)->next;
    free(oldHead);
    
    return 1;
}

void printList(Node *head) {

    Node *tmp = head;
    
    while (tmp != NULL) {
        printf("%s\n", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}




