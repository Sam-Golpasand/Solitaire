//
// Created by Albi :0 on 21/04/2026.
//

#include "showCmd.h"
#include "../utils/linkedList.h"
#include <stdlib.h>

//Now returns 1 if successful and 0 if unsuccessful
//Now takes int visible to determine if cards should be face up or face down
int show(Node *head, int visible) {

    if (head == NULL) {
        return 0;
    }


    char tab[] = "\t\t";

    //Print the column titles
    printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%c%c",
        "C1", tab, "C2", tab, "C3", tab, "C4", tab,
        "C5", tab, "C6", tab, "C7", tab,
        '\n','\n');

    Node *current = head;
    int counter = 0;  //Counter for each row
    int foundationNum = 1; //Foundation no. counter

    while (current != NULL) {
        if (visible == 1) {
            //Prints a card
            printf("%c%c", current->card->rank, current->card->suit);
            printf("%s", tab);
            counter++;
        } else if (visible == 0) {
            //Prints face down card
            printf("%s", "[]");
            printf("%s", tab);
            counter++;
        }

            //Print 4 foundation fields
        if (counter % 7 == 0) {
            if (counter % 2 != 0) {
                if (foundationNum < 5) {
                    printf("%s%s%s%c%i", tab, "[]", tab, 'F', foundationNum);
                    foundationNum++;
                }
            } printf("%c", '\n');
        } current = current->next;

    } printf("%c",'\n');

    return 1;
}