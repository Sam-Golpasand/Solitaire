#include <stdlib.h>
#include <stdio.h>
#include "./linkedList.h"
#include "../commands/loadCmd.h"

// Helper function to create a new empty node.
Node *createNode() {
    Node *lol = malloc(sizeof(Node));

    if (lol != NULL) {
        lol->card = NULL;
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
        newNode->card = cardP;

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
    free(oldHead->card);
    free(oldHead);
    
    return 1;
}

void printList(Node *head) {

    Node *tmp = head;
    while (tmp != NULL) {
        Card *card = tmp->card;
        if (card != NULL) {
            printf("%c%c\n", card->rank, card->suit);
        }
        tmp = tmp->next;
    }
    printf("\n");
}

Node *getLast(Node *head) {
    if (!head) return NULL;

    while (head->next)
        head = head->next;

    return head;
}

void clearList(Node **head) {
    if (head == NULL) {
        return;
    }

    while (*head != NULL) {
        removeTop(head);
    }
}

void clearBoard(Board *board) {
    if (board == NULL) {
        return;
    }

    clearList(&board->C1);
    clearList(&board->C2);
    clearList(&board->C3);
    clearList(&board->C4);
    clearList(&board->C5);
    clearList(&board->C6);
    clearList(&board->C7);
    clearList(&board->F1);
    clearList(&board->F2);
    clearList(&board->F3);
    clearList(&board->F4);
}


int countList(Node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}