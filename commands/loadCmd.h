#ifndef LOADCMD
#define LOADCMD
#include <stdio.h>

typedef struct Node Node;

typedef struct Card {
    char rank; // number/picture of card.
    char suit; // suit
    int isVisible; // 0 for false, 1 for true.
} Card;

int loadFile(char *fileName, Node **head);


#endif