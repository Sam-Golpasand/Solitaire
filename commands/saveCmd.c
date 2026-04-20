#include <stdlib.h>
#include <stdio.h>
#include "loadCmd.h"
#include "../utils/linkedList.h"

int saveGame(Node **head, char *fileName)
{

    if (head == NULL || *head == NULL) {
        return 0;
    }

    if (fileName == NULL) {
        fileName = "./cards.txt";
    }

    FILE *fp = fopen(fileName, "w");

    // basically it checks if there is a character. NULL checks for both EOF and I/O errors.
    Node *current = *head;
    while (current != NULL)
    {
        char currentCard[4]; 
        currentCard[0] = current->Card->rank;
        currentCard[1] = current->Card->suit;
        currentCard[2] = '\n'; // TODO this shouldn't run on the last card because then the save file would have 53 lines instead of 52
        currentCard[3] = '\0';

        // Write to file - using format specifiers
        fprintf(fp, currentCard);

        current = current->next;
    }

    fclose(fp);
    return 1;
}
