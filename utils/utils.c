#include "./utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./linkedList.h"
#include "../commands/loadCmd.h"
#include "../commands/saveCmd.h"
#include "../commands/shuffleCmd.h"
#include "../commands/splitCmd.h"
#include "../commands/showCmd.h"
#include "../commands/playCmd.h"
#include "./moveHandler.h"


//TODO: LD still returns OK message if a new deck is attempted to be loaded, but no new deck is loaded


int commandHandler(char *command, Node **head, Phase *currentPhase, Board *board) {

    char *cmd;
    char *arg;

    parseInput(command, &cmd, &arg);

    if (cmd == NULL) {
        return 0;
    }

    cmds cmdEnum = stringToCmd(cmd);

    // could change to a switch statement later with hashing and enums. To lazy to do now
    // Change the notImplemented() methods to your command function.

    if (*currentPhase == STARTUP) {
        switch (cmdEnum) {

            case LD: {
                // its NULL because it picks up where the last one left off
                char *fileName = arg;

                int success = loadFile(fileName, head);
                if (success) {
                    //int fileLoaded = 1; // Perhaps have a variable in the active game session later
                    // (to use for eligibility of commands)
                    //printList(*head);
                    show(*head,0);
                }
                return success;
            }

            case SW:
                return show(*head,1);

            case SI: {
                int split = 0;

                if (arg != NULL) {
                    split = atoi(arg);
                }

                if (splitDeck(split, head) == NULL) {
                    return 0;
                }

                printList(*head);
                return 1;
            }

            case SR:
                shuffle(*head);
                printList(*head);
                return 1;

            case SD: {
                // its NULL because it picks up where the last one left off
                char *fileName = arg;

                int success = saveGame(head, fileName);
                if (success) {
                    printList(*head);
                }
                return success;
            }

            case P:
                if (head == NULL || *head == NULL || board == NULL) {
                    return 0;
                }
                play(*head, board);
                *currentPhase = PLAY;
                return 1;

            case QQ:
                return -1;

            default:
                return 0;
        }
    } 
    else if (*currentPhase == PLAY) {
        switch (cmdEnum) {
            case Q:
                *currentPhase = STARTUP;
                return 1;

            default: {
                
                Move move;
                
                if (board == NULL) {
                    return 0;
                }

                int isValidMove= parseMove(cmd, &move);

                if (!isValidMove) {
                    return 0;
                }
                //TODO make executeMove in moveHanlder.c
                return executeMove(board, &move);
            }
        }
    }

    return 0;
}

void parseInput(char *command, char **cmd, char **arg) {
    *cmd = command;
    *arg = NULL;

    // move throught memory
    while (*command != ' ' && *command != '\0') {
        command++;
    }

    // check if there is anything else
    if (*command == '\0') {
        return;
    }

    // make a terminator for the cmd.
    *command = '\0';
    command++;

    // so we ignore any extra spaces
    while (*command == ' ') {
        command++;
    }

    // now the rest is the argument.
    if (*command != '\0') {
        *arg = command;
    }
}

cmds stringToCmd(char* str) {
    if (strcmp(str, "LD") == 0) return LD;
    if (strcmp(str, "SW") == 0) return SW;
    if (strcmp(str, "SI") == 0) return SI;
    if (strcmp(str, "SR") == 0) return SR;
    if (strcmp(str, "SD") == 0) return SD;
    if (strcmp(str, "QQ") == 0) return QQ;
    if (strcmp(str, "P") == 0) return P;
    if (strcmp(str, "Q") == 0) return Q;
    // Here we add logic for game moves

    return INVALID;
}

int notImplemented() {
    return 1;
}

