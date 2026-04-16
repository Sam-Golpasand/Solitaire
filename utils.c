#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "loadCmd.h"
#include "linkedList.h"



void stdOut(char *command, int *lastIsValid, Node **head) {

    printf("LAST Command: %s\n", command);
    printf("Message: ");

    if (*lastIsValid == 0) {
        printf("last command not valid \n");
    } else {
        printf("\n");
    }

    printf("INPUT> ");

    // wait for user inpiut
    fgets(command, 80, stdin);

    int i = 0;
    while (command[i] != '\n' && command[i] != '\0') {
        i++;
    }
    command[i] = '\0';

    // Validate input and also run the function for the command. (the name could be better lol)
    *lastIsValid = checkInput(command, head);  

    // make this print the SW when it is done.
    printf("\n"); 
}



int checkInput(char *command, Node **head) {
    // get the command
    char* onlyCommand = strtok(command, " ");
    
    if (onlyCommand == NULL) {
        return 0;
    }

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