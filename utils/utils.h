#ifndef UTILS
#define UTILS
#include "linkedList.h"

typedef struct MoveHistory MoveHistory;

typedef enum {
    STARTUP, 
    PLAY,
    WON
} Phase;

typedef enum {
    LD,
    SW,
    SI,
    SR,
    SD,
    QQ,
    P,
    Q,
    U,
    INVALID
} cmds;



int notImplemented();
int commandHandler(char *command, Node **head, Phase *currentPhase, Board *board, struct MoveHistory *history, char *errorMessage);
cmds stringToCmd(char *str);
void parseInput(char *command, char **cmd, char **arg);
int checkWinState(Board *board);

#endif