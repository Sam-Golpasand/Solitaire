#include <stdlib.h>
#include <stdio.h>
#include "./linkedList.h"
#include "./loadCmd.h"

// Helper function to create a new empty node.
Node *createNode() {
    Node *lol = malloc(sizeof(Node));

    if (lol != NULL) {
        lol->Card = NULL;
        lol->next = NULL;
    }
    return lol;
}

// Add to the top of the list and update head.
void add(char data[2], Node **head) {
    if (head == NULL) {
        return;
    }

    Node *newNode = createNode();

    if (newNode != NULL) {
        Card *cardP = malloc(sizeof(Card));
        if (cardP == NULL) {
            free(newNode);
            return;
        }

        cardP->isVisible = 0;
        cardP->rank = data[0];
        cardP->suit = data[1];
        newNode->Card = cardP;

        if (*head == NULL) {
            *head = newNode;
        } else {
            newNode->next = *head;
            *head = newNode;
        }
    }
}

// TODO figure out how to do a pop() method instead and return the top element
// Removes the top.
int removeTop(Node **head) {

    if (head == NULL || *head == NULL) {
        return 0;
    }

    Node *oldHead = *head;
    *head = (*head)->next;
    free(oldHead->Card);
    free(oldHead);
    
    return 1;
}

void printList(Node *head) {

    Node *tmp = head;
    while (tmp != NULL) {
        Card *card = tmp->Card;
        if (card != NULL) {
            printf("%c%c\n", card->rank, card->suit);
        }
        tmp = tmp->next;
    }
    printf("\n");
}




