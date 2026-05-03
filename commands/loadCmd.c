#include <stdlib.h>
#include <stdio.h>
#include "loadCmd.h"
#include "../utils/linkedList.h"
#include "showCmd.h"

int loadFile(char *fileName, Node **head) {
    char line[16]; // size of each line in the file. OBS Change if you want larger line sizes.



    FILE *fp = fopen(fileName, "r");
    // TODO Differentiate between not having any filename vs invalid filename
    if (fp == NULL) {
        fp = fopen("games/orderedGame.txt", "r");
    }


    // basically it checks if there is a character. NULL checks for both EOF and I/O errors.
    while (fgets(line, sizeof(line), fp) != NULL) {
        char data[2];


        // check if first char is not a valid char
        if (line[0] == '\0' || line[0] == '\n') {
            continue;
        }

        // checks second
        if (line[1] == '\0' || line[1] == '\n') {
            continue;
        }

        data[0] = line[0];
        data[1] = line[1];
        add(data, head);
    }

    fclose(fp);
    return 1;
}

