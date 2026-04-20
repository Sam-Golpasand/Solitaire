#include "shuffleCmd.h"
#include <stdlib.h>

#include "linkedList.h"
#include "loadCmd.h"

void shuffle(Node *head) {
    if (head == NULL) {
        return;
    }

    // Adding each card into an array
    Card tmpDeck[52];
    int nodeCount = 0;                      // Make a variable to track how many times we moved to the next card.

    Node *tmp = head;                       // Assign a temporary pointer that points at the head of linked list.

    while (tmp != NULL) {
        tmpDeck[nodeCount] = *tmp -> Card;  // Add the current pointer value of the card being pointed at to the array.
        tmp = tmp -> next;                  // Save the next value in the list
        nodeCount++;
        }

    // The actual shuffle mechanism
    // Array probably redundant. Might solve it later
    Card shuffled[52];
    int shuffledIndex = 0;

    for (int i = 0; i < nodeCount; i++) {
        Card current = tmpDeck[i];
            const int pos = rand() % (shuffledIndex + 1);   // Algorithm to randomly shuffle deck. Could eventually be improved without seeding.

        for (int j = shuffledIndex; j > pos; j--) {
            shuffled[j] = shuffled[j - 1];
        }
        shuffled[pos] = current;
        shuffledIndex++;
    }

    // Changing card value in linked list from shuffled array
    nodeCount = 0;
    tmp = head;

    while (tmp != NULL) {
        *tmp -> Card = shuffled[nodeCount]; //
        tmp = tmp -> next;
        nodeCount++;
    }
}