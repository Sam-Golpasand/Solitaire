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

typedef struct {
    Node *C1;
    Node *C2;
    Node *C3;
    Node *C4;
    Node *C5;
    Node *C6;
    Node *C7;
    Node *F1;
    Node *F2;
    Node *F3;
    Node *F4;
} Board;

void add(char data[2], Node **head);
void printList(Node *head);
int removeTop(Node **head);

#endif