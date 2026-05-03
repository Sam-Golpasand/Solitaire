#include <stdio.h>
#include "./utils/linkedList.h"
#include <string.h>
#include "./utils/utils.h"
#include <time.h>
#include <stdlib.h>
#include "commands/showCmd.h"
#include "commands/loadCmd.h"
#include "./utils/tcpHandler.h"

int main(int argc, char **argv) {

    // This is for seeding the rand() function for the shuffle implementations.
    srand(time(NULL));

    if (argc > 1 && strcmp(argv[1], "server") == 0) {
        int port = TCP_DEFAULT_PORT;
        if (argc > 2) {
            port = atoi(argv[2]);
            if (port <= 0 || port > 65535) {
                port = TCP_DEFAULT_PORT;
            }
        }
        return runTcpServer(port);
    }

    Phase currentPhase = STARTUP;

    //? the max length for a command could be changed later. Not sure what to set it to yet though.
    char command[256] = "";
    char rawCommand[256] = "";
    int commandStatus = 1; // 1 for valid, 0 for invalid and -1 for break

    Node *head = NULL;
    Board board = {0};


    while (1) {

        if (currentPhase == PLAY) {
            showBoard(&board);
        }

        printf("LAST Command: %s\n", rawCommand);
        printf("Message: ");

        if (commandStatus == 0) {
            printf("last command not valid\n");
        } else {
            printf("OK\n");
        }

        printf("INPUT> ");

        // wait for user input. Make sure the fgets size is the same as command length.
        fgets(command, 256, stdin);

        // remove the new line terminator so we can compare it later with strcmp() in checkInput    
        int i = 0;
        while (command[i] != '\n' && command[i] != '\0') {
            i++;
        }

        command[i] = '\0';

        strcpy(rawCommand, command);

        commandStatus = commandHandler(command, &head, &currentPhase, &board);

        // exit signal
        if (commandStatus == -1) {
            break;
        }
        // TODO make this print the SW when it is done.
        printf("\n");
    }

    return 0;
}