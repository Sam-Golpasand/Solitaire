#ifndef MOVEHANDLER
#define MOVEHANDLER
#include "linkedList.h"

// This instead of #include to avoid circular dependencies
typedef struct MoveHistory MoveHistory;

typedef struct {
    char *col;
    char *card;
    char *to;
    int revealedCard;
} Move;

int parseIndex(char *col);
int parseMove(char *input, Move *move);
int executeMove(Board *board, Move *move, struct MoveHistory *history);
Node **getColumn(Board *board, int index);
Node **getFoundation(Board *board, int index);
Node *findCard(Node *head, char *target, Node **prev);
int validColumnMove(Node *dest, Node *moveCard);
int validFoundationMove(Node *dest, Node *moveCard);
#endif