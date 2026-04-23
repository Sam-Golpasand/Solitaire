#ifndef UTILS
#define UTILS
#include "linkedList.h"

typedef enum {
    STARTUP, 
    PLAY
} phase;

typedef enum {
    LD,
    SW,
    SI,
    SR,
    SD,
    QQ,
    P,
    Q,
    INVALID
} cmds;

int notImplemented();
int commandHandler(char *command, Node **head, phase *currentPhase);
cmds cmdToString(char *str);
void parseInput(char *command, char **cmd, char **arg);

#endif