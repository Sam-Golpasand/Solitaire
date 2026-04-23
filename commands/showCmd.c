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
    char tab[] = "\t\t";

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
