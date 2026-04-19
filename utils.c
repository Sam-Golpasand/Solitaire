#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "loadCmd.h"
#include "linkedList.h"

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
        char* fileName = strtok(NULL, " ");
        
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
        return notImplemented();
    } else if (strcmp(onlyCommand, "SL") == 0) {
        return notImplemented();
    } else if (strcmp(onlyCommand, "SR") == 0) {
        return notImplemented();
    } else if (strcmp(onlyCommand, "SD") == 0) {
        return notImplemented();
    } else if (strcmp(onlyCommand, "QQ") == 0) {
        return notImplemented();
    } else {
        return 0;
    }
}

int notImplemented() {
    return 1;
}
