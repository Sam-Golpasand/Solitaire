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
        tmp = tmp -> next;                  // Save the next value in the list
        nodeCount++;
        }

    Card shuffled[52];               // Create a temporary array of cards to hold the shuffled deck.
    int shuffledIndex = 0;

    for (int i = 0; i < nodeCount; i++) {
        Card current = tmpDeck[i];
            const int pos = rand() % (shuffledIndex + 1);   // Algorithm to randomly shuffle deck.

        for (int j = shuffledIndex; j > pos; j--) {
            shuffled[j] = shuffled[j - 1];
        }
        shuffled[pos] = current;            // Insert the card into the "pos" area inside the new array
        shuffledIndex++;
    }

    nodeCount = 0;
    tmp = head;

    while (tmp != NULL) {
        *tmp -> Card = shuffled[nodeCount];
        tmp = tmp -> next;
        nodeCount++;
    }
}