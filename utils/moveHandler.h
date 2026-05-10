#ifndef MOVEHANDLER
#define MOVEHANDLER
#include "linkedList.h"
#include "utils.h"

int parseIndex(char *col);
int parseMove(char *input, Move *move);
int executeMove(Board *board, Move *move);
Node **getColumn(Board *board, int index);
Node **getFoundation(Board *board, int index);

int validColumnMove(Node *dest, Node *moveCard);
int validFoundationMove(Node *dest, Node *moveCard);
#endif