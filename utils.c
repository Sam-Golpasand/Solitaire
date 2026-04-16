#include <stdio.h>
#include <string.h>
#include "utils.h"

void stdOut(char *command, int *lastIsValid) {

    printf("LAST Command: %s\n", command);
    printf("Message: ");

    if (*lastIsValid == 0) {
        printf("last command not valid \n");
    } else {
        printf("\n");
    }

    printf("INPUT> ");

    // wait for user inpiut
    scanf("%s", command); 

    // Validate input and also run the function for the command. (the name could be better lol)
    *lastIsValid = checkInput(command);  

    // make this print the SW when it is done.
    printf("\n"); 
}

int checkInput(char *command) {

    // could change to a switch statement later with hashing and enums. To lazy to do now
    // Change the notImplemented() methods to your command function.
    if (strcmp(command, "LD") == 0) {
        return notImplemented();
    } else if (strcmp(command, "SW") == 0) {
        return notImplemented();
    } else if (strcmp(command, "SL") == 0) {
        return notImplemented();
    } else if (strcmp(command, "SR") == 0) {
        return notImplemented();
    } else if (strcmp(command, "SD") == 0) {
        return notImplemented();
    } else if (strcmp(command, "QQ") == 0) {
        return notImplemented();
    } else {
        return 0;
    }
}

int notImplemented() {
    return 1;
}