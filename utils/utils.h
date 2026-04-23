#ifndef UTILS
#define UTILS
#include "linkedList.h"

typedef enum {
    STARTUP, PLAY
} phase;

typedef struct {
    Node *C1;
    Node *C2;
    Node *C3;
    Node *C4;
    Node *C5;
    Node *C6;
    Node *C7;
    Node *C8;
    Node *C9;
    Node *C10;
    Node *C11;
} board;

int notImplemented();
int commandHandler(char *command, Node **head, phase *currentPhase);

#endif