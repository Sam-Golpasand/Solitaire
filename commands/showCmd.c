#include "showCmd.h"
#include "../utils/linkedList.h"
#include <stdlib.h>

//Now returns 1 if successful and 0 if unsuccessful
int show(Node *head) {

    if (head == NULL) {
        return 0;
    }
    //Normalized spacing
    //char spacing[] = "   ";
    char tab[] = "\t";

    //Print the column titles
    printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%c%c",
        "C1", tab, "C2", tab, "C3", tab, "C4", tab,
        "C5", tab, "C6", tab, "C7", tab,
        '\n','\n');
    Node *current = head;
    int counter = 0;  //Counter for each row
    int fieldNum = 1; //Field no. counter

    while (current != NULL) {

        //Prints a card
        printf("%c%c", current->card->rank, current->card->suit);
        printf("%s", tab);
        counter++;


        //If 7 cards are printed go to next row, for every second row, make a field (idk the name)
        if (counter % 7 == 0) {
            if (counter % 2 != 0) {
                printf("%s%s%s%c%i", tab, "[]", tab, 'F', fieldNum);
                fieldNum++;
            }
            printf("%c", '\n');
        }
        current = current->next;
    } printf("%c",'\n');
    return 1;
}

// This is vibecoded.
int showBoard(Board *board) {

    if (board == NULL) {
        return 0;
    }

    char tab[] = "\t";

    printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%c%c",
        "C1", tab, "C2", tab, "C3", tab, "C4", tab,
        "C5", tab, "C6", tab, "C7", tab,
        '\n','\n');

    Node *cols[7] = {
        board->C1, board->C2, board->C3, board->C4,
        board->C5, board->C6, board->C7
    };
    Node *foundations[4] = { board->F1, board->F2, board->F3, board->F4 };

    int maxLen = 0;
    for (int i = 0; i < 7; i++) {
        int len = 0;
        Node *current = cols[i];
        while (current != NULL) {
            len++;
            current = current->next;
        }
        if (len > maxLen) {
            maxLen = len;
        }
    }

    if (maxLen < 4) {
        maxLen = 4;
    }

    for (int row = 0; row < maxLen; row++) {
        for (int col = 0; col < 7; col++) {
            if (cols[col] != NULL && cols[col]->card != NULL) {
                printf("%c%c", cols[col]->card->rank, cols[col]->card->suit);
                cols[col] = cols[col]->next;
            }
            printf("%s", tab);
        }

        if (row < 4) {
            char fcard[3] = "[]";
            if (foundations[row] != NULL) {
                Node *last = getLast(foundations[row]);
                if (last != NULL && last->card != NULL) {
                    fcard[0] = last->card->rank;
                    fcard[1] = last->card->suit;
                    fcard[2] = '\0';
                }
            }
            printf("%s%s%s%c%d", tab, fcard, tab, 'F', row + 1);
        }

        printf("\n");
    }

    printf("\n");
    return 1;
}
