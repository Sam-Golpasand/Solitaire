//
// Created by Albi :0 on 21/04/2026.
//

#include "showCmd.h"
#include "../utils/linkedList.h"
#include <stdlib.h>


void show(Node *head) {

    if (head == NULL) {
        return;
    }
    //Normalized spacing
    char spacing[] = "   ";

    //Print the column titles
    printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%c%c",
        "C1", spacing, "C2", spacing, "C3", spacing, "C4", spacing,
        "C5", spacing, "C6", spacing, "C7", spacing,
        '\n','\n');

    Node *current = head;
    int counter = 0;  //Counter for each row
    int fieldNum = 1; //Field no. counter

    while (current != NULL) {

        //Prints a card
        printf("%c%c", current->card->rank, current->card->suit);
        printf("%s", spacing);
        counter++;


        //If 7 cards are printed go to next row, for every second row, make a field (idk the name)
        if (counter % 7 == 0) {
            if (counter % 2 != 0) {
                printf("%s%s%s%s%c%i", spacing, spacing, "[]", spacing, 'F', fieldNum);
                fieldNum++;
            }
            printf("%c", '\n');
        }
        current = current->next;
    } printf("%c",'\n');

}
