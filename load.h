#ifndef LOAD
#define LOAD
#include <stdio.h>


typedef struct Card {
    char rank; // number/picture of card.
    char suit; // suit
    int isVisible; // 0 for false, 1 for true.
} Card;

struct Node;
int loadFile(FILE *fp, struct Node **head);


#endif