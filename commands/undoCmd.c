//
// Created by Albi :0 on 08/05/2026.
//

#include "undoCmd.h"

#include <stdlib.h>
#include <string.h>
#include "../utils/moveHandler.h"

int undoMove(Board *board, MoveHistory *history) {
    // 1. Get the last move
    Move lastMove = popMove(history);
    if (lastMove.col == NULL) return 0; // History was empty

    // 2. Identify the piles (Note: 'from' and 'to' are swapped for undo)
    Node **currentPile; // Where the cards are now (the original 'to')
    Node **originalPile; // Where the cards came from (the original 'from')

    int currentIndex = parseIndex(lastMove.to);
    int originalIndex = parseIndex(lastMove.col);

    if (lastMove.to[0] == 'C') currentPile = getColumn(board, currentIndex);
    else currentPile = getFoundation(board, currentIndex);

    if (lastMove.col[0] == 'C') originalPile = getColumn(board, originalIndex);
    else originalPile = getFoundation(board, originalIndex);

    // 3. Find the card in the current pile to move it back
    Node *nodeBefore = NULL;
    Node *moveCard = NULL;

    // If we moved a specific card/stack, find it. If not (like foundation), get the last.
    if (lastMove.card != NULL) {
        moveCard = findCard(*currentPile, lastMove.card, &nodeBefore);
    } else {
        Node *curr = *currentPile;
        while (curr && curr->next) {
            nodeBefore = curr;
            curr = curr->next;
        }
        moveCard = curr;
    }

    if (!moveCard) return 0;

    // 4. Detach from current pile
    if (nodeBefore) nodeBefore->next = NULL;
    else *currentPile = NULL;

    // 5. Handle the revealed card flip-back
    // If executeMove revealed a card, the card before our moveCard on the
    // original pile must be hidden again.
    if (lastMove.revealedCard) {
        Node *prevOnOriginal = getLast(*originalPile);
        if (prevOnOriginal) prevOnOriginal->card->isVisible = 0;
    }

    // 6. Attach back to original pile
    if (!*originalPile) {
        *originalPile = moveCard;
    } else {
        Node *last = getLast(*originalPile);
        last->next = moveCard;
    }

    return 1;
}


Move popMove(MoveHistory *history) {
    if (history->head == NULL) {
        Move empty = {NULL, NULL, NULL};
        return empty;
    }
    HistoryNode *oldHead = history->head;
    Move moveData = oldHead->move;
    history->head = oldHead->next;
    free(oldHead);
    return moveData;
}



void pushMove(MoveHistory *history, Move move) {
    HistoryNode *newNode = (HistoryNode *)malloc(sizeof(HistoryNode));
    if (newNode == NULL) return;

    // Copy the move data.
    newNode->move.col = strdup(move.col);
    newNode->move.to = strdup(move.to);

    newNode->move.card = (move.card != NULL) ? strdup(move.card) : NULL;

    newNode->move.revealedCard = move.revealedCard;

    newNode->next = history->head;
    history->head = newNode;
}