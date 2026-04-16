#include <stdio.h>
#include "linkedList.h"

void stdOut(char *buffer);

int main(void) {

    char buffer[8] = {};

    while(1) {
        stdOut(buffer);
    }

    return 0;
}

void stdOut(char *buffer) {
    printf("LAST Command: %s\n", buffer);
    printf("Message: \n");
    printf("INPUT> ");
    scanf("%s", buffer);
    printf("\n"); // make this print the SW when it is done.
}