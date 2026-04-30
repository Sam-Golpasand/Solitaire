#ifndef MOVEHANDLER
#define MOVEHANDLER
#include "linkedList.h"


typedef struct {
    char *col;
    char *card;
    char *to;
} Move;

int parseMove(char *input, Move *move);
int executeMove(Board *board, Move *move);

int validColumnMove(Node *dest, Node *moveCard);
int validFoundationMove(Node *dest, Node *moveCard);
#endif