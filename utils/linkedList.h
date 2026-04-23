#ifndef LINKEDLIST
#define LINKEDLIST
#include <stdio.h>

typedef struct Card {
    char rank; // number/picture of card.
    char suit; // suit
    int isVisible; // 0 for false, 1 for true.
} Card;


typedef struct Node {
    Card *card;
    struct Node *next;
} Node;


void add(char data[2], Node **head);
void printList(Node *head);
int removeTop(Node **head);

#endif