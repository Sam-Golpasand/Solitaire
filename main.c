#include <stdio.h>
#include "linkedList.h"
#include <string.h>
#include "utils.h"
#include <time.h>
#include <stdlib.h>

int main(void) {

    //? the max length for a command could be changed later. Not sure what to set it to yet though.
    char command[256] = "";
    int lastIsValid = 1; // 1 for valid, 0 for invalid

    Node *head = NULL;

    // This is for seeding the rand() function for the shuffle implementations.
    srand(time(NULL));
    while (1) {
        if (strcmp(command, "QQ") == 0) {
            break;
        }

        

        printf("LAST Command: %s\n", command);
        printf("Message: ");

        if (lastIsValid == 0) {
            printf("last command not valid \n");
        } else {
            printf("\n");
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

        lastIsValid = commandHandler(command, &head);

        // TODO make this print the SW when it is done.
        printf("\n");
    }

    return 0;
}