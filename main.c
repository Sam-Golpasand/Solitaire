#include <stdio.h>
#include "linkedList.h"

int main(void) {

    Node *head = NULL;
   
    add("5D\n", &head);
    add("5S\n", &head);
    add("KD\n", &head);
    add("9D\n", &head);

    printf("all of your cards sir (ʘ‿ʘ)╯: \n");
    printList(head);
    return 0;
}