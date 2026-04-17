#include <stdio.h>
#include "linkedList.h"
#include <string.h>
#include "utils.h"

int main(void) {

    //? the max length for a command could be changed later. Not sure what to set it to yet though.
    char command[256] = ""; 
    int lastIsValid = 1; // 1 for valid, 0 for invalid

    Node *head = NULL;

    while(1) {
        stdOut(command, &lastIsValid, &head);
    }

    return 0;
}
