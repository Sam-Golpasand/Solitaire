#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SI.h"

Node* splitDeck(int split, Node **head) {
    // safety checks
    if (split > 51 || head == NULL || *head == NULL) {
        return NULL;
    }

    if (split <= 0) {
        // Seed the generator
        srand(time(NULL));

        // Generate number between 1 and 51
        split = (rand() % 51) + 1;
    }

    Node *head1 = *head;
    Node *head2 = *head;

    // this loop splits the original deck into two new decks
    for (int i = 0; i < split; i++) {
        if (head2->next == NULL) {
            return NULL;
        }
        head2 = head2->next;
        if (i == split - 1) {
            head1->next = NULL;
            break;
        }
        head1 = head1->next;
    }

    head1 = *head;
    Node *rHead;
    Node *tempHead;
    int firstFlag = 1;
    while (head1 != NULL && head2 != NULL) {
        // if it is the first loop through the loop, different logic is need for making the new deck
        if (firstFlag == 1) {
            rHead = head1;
            head1 = head1->next;
            tempHead = rHead;
            tempHead->next = head2;
            tempHead = tempHead->next;
            head2 = head2->next;
            firstFlag = 0;
            continue;
        }
        // takes the top card from each deck and adds it to the new deck
        tempHead->next = head1;
        head1 = head1->next;
        tempHead = tempHead->next;
        tempHead->next = head2;
        head2 = head2->next;
        tempHead = tempHead->next;
    }

    // adding the rest of the two split decks to the new deck
    if (head1 == NULL) {
        tempHead->next = head2;
    }
    else if (head2 == NULL) {
        tempHead->next = head1;
    }
    else {
        return NULL;
    }

    *head = rHead;

    return rHead;
}
