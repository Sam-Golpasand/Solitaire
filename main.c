#include <stdio.h>
#include "linkedList.h"

int main(void) {

    Node *head = NULL;
  
    FILE *lol = fopen("./games/orderedGame.txt", "r");

    loadFile(lol, &head);
    printf("all of your cards sir (ʘ‿ʘ)╯: \n");
    printList(head);

    printf("all of your cards after removing the top (ʘ‿ʘ)╯: \n");
    removeTop(&head);
    printList(head);
    return 0;
}