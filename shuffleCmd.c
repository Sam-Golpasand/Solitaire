//
// Created by safi2 on 16-04-2026.
//

#include "shuffleCmd.h"
#include <stdlib.h>

#include "linkedList.h"
#include "load.h"

void shuffle() {
    Card tmpDeck[52];                       // Make an array with a capacity of 52 elements (i.e., a standard card deck).
    int nodeCount = 0;                      // Make a variable to track how many times we moved to the next card.

    Node *tmp = head;                       // Assign a temporary pointer that points at the head of linked list.

    while (tmp != NULL) {
        tmpDeck[nodeCount] = *tmp -> Card;  // Add the current pointer value of the card being pointed at.
        tmp = tmp -> next;
        nodeCount++;
        }

    Card shuffled[nodeCount];
    int shuffledIndex = 0;

    for (int i = 0; i < nodeCount; i++) {
        Card current = tmpDeck[i];
            const int pos = rand() % (shuffledIndex + 1);

        for (int j = shuffledIndex; j > pos; j--) {
            shuffled[j] = shuffled[j - 1];
        }
        shuffled[pos] = current;
        shuffledIndex++;
    }

    for (int i = 0; i < nodeCount; i++) {
        tmpDeck[i] = shuffled[i];
    }

    nodeCount = 0;
    tmp = head;

    while (tmp != NULL) {
        *tmp -> Card = tmpDeck[nodeCount];
        tmp = tmp -> next;
        nodeCount++;
    }
}