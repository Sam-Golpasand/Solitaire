#include <stdio.h>
#include "linkedList.h"
#include <string.h>
#include "utils.h"

int main(void) {

    char command[8] = "";
    int lastIsValid = 1; // 1 for valid, 0 for invalid

    while(1) {
        stdOut(command, &lastIsValid);
    }

    return 0;
}
