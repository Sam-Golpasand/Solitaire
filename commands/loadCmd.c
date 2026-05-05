#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "loadCmd.h"
#include "../utils/linkedList.h"
#include "showCmd.h"

static void clearList(Node **head) {
    if (head == NULL) {
        return;
    }
    while (*head != NULL) {
        removeTop(head);
    }
}

int loadFile(char *fileName, Node **head, char *errorMessage) {
    char line[16]; // size of each line in the file. OBS Change if you want larger line sizes.
    int seen[4][13] = {0};
    int cardCount = 0;
    int ok = 1;
    Node *newHead = NULL;
    char *ranks = "A23456789TJQK";
    char *suits = "CDHS";

    if (head == NULL) {
        return 0;
    }

    FILE *fp = NULL;
    if (fileName == NULL || *fileName == '\0') {
        fp = fopen("games/orderedGame.txt", "r");
    } else {
        fp = fopen(fileName, "r");
    }
    if (fp == NULL) {
        strcat(errorMessage, "File does not exist");
        return 0;
    }

    // basically it checks if there is a character. NULL checks for both EOF and I/O errors.
    while (fgets(line, sizeof(line), fp) != NULL) {
        size_t len = strcspn(line, "\r\n");
        line[len] = '\0';

        if (len == 0) {
            continue;
        }

        if (len != 2) {
            ok = 0;
            break;
        }

        char *rankPos = strchr(ranks, line[0]);
        char *suitPos = strchr(suits, line[1]);
        if (rankPos == NULL || suitPos == NULL) {
            ok = 0;
            break;
        }

        int rankIdx = (int)(rankPos - ranks);
        int suitIdx = (int)(suitPos - suits);
        if (seen[suitIdx][rankIdx]) {
            ok = 0;
            break;
        }
        seen[suitIdx][rankIdx] = 1;

        cardCount++;
        if (cardCount > 52) {
            ok = 0;
            break;
        }

        char data[2];
        data[0] = line[0];
        data[1] = line[1];
        add(data, &newHead);
    }

    fclose(fp);

    if (!ok || cardCount != 52) {
        clearList(&newHead);
        return 0;
    }

    clearList(head);
    *head = newHead;
    return 1;
}

