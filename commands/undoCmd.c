//
// Created by Albi :0 on 08/05/2026.
//

#include "undoCmd.h"

int undoCmd(Board *board, MoveHistory *history) {

    Move lastMove = popMove(history);

    if (lastMove.col == NULL) { return 0;}

    int fromIndex = parseIndex(lastMove.col);
    int toIndex = parseIndex(lastMove.to);

    if (fromIndex == -1 || toIndex == -1) {
        return 0;
    }

    Node **fromPile = (lastMove.col[0] == 'C') ? getColumn(board, fromIndex) : getFoundation(board, fromIndex);
    Node **toPile = (lastMove.to[0] == 'C') ? getColumn(board, toIndex) : getFoundation(board, toIndex);

    Node *prev = NULL;
    Node *cardToMoveBack = *toPile;

    while (cardToMoveBack && cardToMoveBack->next) {
        prev = cardToMoveBack;
        cardToMoveBack = cardToMoveBack->next;
    }

    if (prev) {
        prev->next = NULL;
    } else {
        *toPile = NULL;
    }

    if (*fromPile == NULL) {
        *fromPile = cardToMoveBack;
    } else {
        Node *lastInFrom = getLast(*fromPile);
        lastInFrom->next = cardToMoveBack;
    }

    free(lastMove.col);
    free(lastMove.to);
    if (lastMove.card) free(lastMove.card);

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