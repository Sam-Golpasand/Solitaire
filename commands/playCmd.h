#ifndef PLAYCMD_H
#define PLAYCMD_H
#include "../utils/linkedList.h"

Node *copyList(Node *head);
void play(Node *head, Board *board);
void playLocal(Node *head, Board *board);

#endif //PLAYCMD_H