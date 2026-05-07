#include "showCmd.h"
#include "../utils/linkedList.h"
#include <stdlib.h>

//Now returns 1 if successful and 0 if unsuccessful
int show(Node *head, int visible) {
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

        if (visible) {
            //Prints a card
            printf("%c%c", current->card->rank, current->card->suit);
        } else {
            printf("%s", "[]");
        }
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


int showBoard(Board *board) {

    if (board == NULL) {
        return 0;
    }

    char tab[] = "\t";

    printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%c%c",
        "C1", tab, "C2", tab, "C3", tab, "C4", tab,
        "C5", tab, "C6", tab, "C7", tab,
        '\n','\n');

    //Initialise arrays of pointers to 7 columns and 4 foundation piles
    Node *cols[7] = {
        board->C1, board->C2, board->C3, board->C4,
        board->C5, board->C6, board->C7
    };
    Node *foundations[4] = { board->F1, board->F2, board->F3, board->F4 };


    //Count the number of nodes in each list to make sure we can print many cards per column
    int maxLen = 0;
    for (int i = 0; i < 7; i++) {
        int len = countList(cols[i]);
        if (len > maxLen) {
            maxLen = len;
        }
    }
    //We need at least 4 rows for the foundation piles
    if (maxLen < 4) {
        maxLen = 4;
    }

    //Print each card in the row if visible
    for (int row = 0; row < maxLen; row++) {
        for (int col = 0; col < 7; col++) {
            if (cols[col] != NULL && cols[col]->card != NULL) {
                if (cols[col]->card->isVisible) {
                    printf("%c%c", cols[col]->card->rank, cols[col]->card->suit);
                } else {
                    printf("[]");
                }
                cols[col] = cols[col]->next;
            }
            printf("%s", tab);
        }

        //Print top card in foundation piles in each list
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


void STARTUPShow() {
    char tab[] = "\t";

    printf("C1%sC2%sC3%sC4%sC5%sC6%sC7\n", tab, tab, tab, tab, tab, tab, tab);

    for (int i = 1; i <= 4; i++) {
        printf("\n%s%s%s%s%s%s%s%s%s%s[]%sF%d\n",
        tab, tab, tab, tab, tab, tab, tab, tab, tab, tab, tab, i);
    }
    printf("\n\n");
}

