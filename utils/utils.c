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


int commandHandler(char *command, Node **head) {
    // get the command
    char* onlyCommand = strtok(command, " ");
    
    if (onlyCommand == NULL) {
        return 0;
    }

    // could change to a switch statement later with hashing and enums. To lazy to do now
    // Change the notImplemented() methods to your command function.
    if (strcmp(onlyCommand, "LD") == 0) {

        // its NULL because it picks up where the last one left off
        char *fileName = strtok(NULL, " ");
        
        if (fileName == NULL) {
            printf("Error: LD requires a filename (e.g., LD deck.txt)\n");
            return 0;
        }


        int success = loadFile(fileName, head);
        if (success) {
            printList(*head);
        }
        return success;

    } else if (strcmp(onlyCommand, "SW") == 0) {
        show(*head);
        return 1;
    } else if (strcmp(onlyCommand, "SI") == 0) {
        char *splitArg = strtok(NULL, " ");
        int split = 0;

        if (splitArg != NULL) {
            split = atoi(splitArg);
        }

        if (splitDeck(split, head) == NULL) {
            return 0;
        }

        printList(*head);
        return 1;

    } else if (strcmp(onlyCommand, "SR") == 0) {
        shuffle(*head);
        printList(*head);
        return 1;
    } else if (strcmp(onlyCommand, "SD") == 0) {
        
        // its NULL because it picks up where the last one left off
        char *fileName = strtok(NULL, " ");

        int success = saveGame(head, fileName);
        if (success) {
            printList(*head);
        }
        return success;

    } else if (strcmp(onlyCommand, "QQ") == 0) {
        return notImplemented();
    } else {
        return 0;
    }

    return 0;
}

int notImplemented() {
    return 1;
}
