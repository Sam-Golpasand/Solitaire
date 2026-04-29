#ifndef MOVEHANDLER
#define MOVEHANDLER
#include "linkedList.h"


typedef struct {
    char *col;
    char *from;
    char *to;
} Move;

int parseMove(char *input, Move *move);
int executeMove(Board *board, Move *move);

#endif