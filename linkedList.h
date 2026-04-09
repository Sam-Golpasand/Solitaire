#ifndef LINKEDLIST
#define LINKEDLIST
#include <stdio.h>
#include "load.h"


typedef struct Node {
    Card *Card;
    struct Node *next;
} Node;


void add(char data[2], Node **head);
void printList(Node *head);
int removeTop(Node **head);

#endif