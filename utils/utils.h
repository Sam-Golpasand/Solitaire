#ifndef UTILS
#define UTILS
#include "linkedList.h"

typedef enum {
    STARTUP, PLAY
} phase;

int notImplemented();
int commandHandler(char *command, Node **head, phase *currentPhase);

#endif