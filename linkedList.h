#ifndef LINKEDLIST
#define LINKEDLIST
#include <stdio.h>


typedef struct Node {
    char data[3];
    struct Node *next;
} Node;


void add(char data[3], Node **head);
void printList(Node *head);

#endif