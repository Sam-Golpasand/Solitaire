#include <stdio.h>
#include "linkedList.h"
#include <string.h>

int notImplemented();
int checkInput(char *command);
void stdOut(char *command, int *lastIsValid);

int main(void) {

    char command[8] = "";
    int lastIsValid = 1; // 1 for valid, 0 for invalid

    while(1) {
        stdOut(command, &lastIsValid);
    }

    return 0;
}

void stdOut(char *command, int *lastIsValid) {


    printf("LAST Command: %s\n", command);
    printf("Message: ");

    if (*lastIsValid == 0) {
        printf("last command not valid \n");
    } else {
        printf("\n");
    }

    printf("INPUT> ");
    scanf("%s", command);
    *lastIsValid = checkInput(command);
    printf("\n"); // make this print the SW when it is done.
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