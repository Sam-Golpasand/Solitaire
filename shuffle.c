//
// Created by safi2 on 16-04-2026.
//

#include "shuffle.h"
#include <stdlib.h>
#include "load.h"

void shuffle(Card deck[52]) {
    Card shuffled[52];
    int shuffledIndex = 0;

    for (int i = 0; i < 52; i++) {
        Card current = deck[i];
            const int pos = rand() % (shuffledIndex + 1);

        for (int j = shuffledIndex; j > pos; j--) {
            shuffled[j] = shuffled[j - 1];
        }
        shuffled[pos] = current;
        shuffledIndex++;
    }

    for (int i = 0; i < 52; i++) {
        deck[i] = shuffled[i];
    }
}
