#ifndef PLAYCMD_H
#define PLAYCMD_H
#include "../utils/linkedList.h"

typedef struct {
    Node *rows[11];
    Node *columns[7];
} gameState;

void play(Node *head);

#endif //PLAYCMD_H