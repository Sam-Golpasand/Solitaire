//
// Created by Albi :0 on 08/05/2026.
//

#include "undoCmd.h"

#include <stdlib.h>
#include <string.h>
#include "../utils/moveHandler.h"

// Very similar implementation to executeMove(), but skips validity checks
int undoMove(Board *board, MoveHistory *history) {
    // Get and remove (Pop) the last move, since it shouldn't exist in history anymore
    Move lastMove = popMove(history);
    if (lastMove.col == NULL || lastMove.to == NULL) return 0;


    // Opposite from executeMove() as we are undoing the move
    int fromIndex = parseIndex(lastMove.to);
    int toIndex = parseIndex(lastMove.col);

    if (fromIndex == -1 || toIndex == -1) {
        return 0;
    }

    Node **fromPile;
    Node **toPile;

    if (lastMove.to[0] == 'C') {
        fromPile = getColumn(board, fromIndex);
    } else {
        fromPile = getFoundation(board, fromIndex);
    }

    if (lastMove.col[0] == 'C') {
        toPile = getColumn(board, toIndex);
    } else {
        toPile = getFoundation(board, toIndex);
    }

    Node *nodeBeforeMoveCard = NULL;
    Node *moveCard = NULL;

    // If we moved a specific card/stack, find it. If not (like foundation), get the last.
    if (lastMove.card != NULL) {
        moveCard = findCard(*fromPile, lastMove.card, &nodeBeforeMoveCard);
    } else {
        Node *current = *fromPile;


        while (current && current->next) {
            nodeBeforeMoveCard = current;
            current = current->next;
        }
        moveCard = current;
    }
    //This shouldn't happen, especially since we already popped the last move but oh well
    if (!moveCard) return 0;

    // if there is a card before the card we are moving then make its next be null and detach
    if (nodeBeforeMoveCard) {
        nodeBeforeMoveCard->next = NULL;
    } else {
        *fromPile = NULL;
    }


    // If executeMove revealed a card, the card before our moveCard on the
    // original pile must be hidden again. (AI came up with the idea for this)
    if (lastMove.revealedCard) {
        Node *revealedCard = getLast(*toPile);
        if (revealedCard) revealedCard->card->isVisible = 0;
    }


    if (!*toPile) {
        *toPile = moveCard;
    } else {
        Node *last = getLast(*toPile);
        last->next = moveCard;
    }

    return 1;
}

//gets and removes a move from the history of moves
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


//Adds a move to the history of moves
void pushMove(MoveHistory *history, Move move) {
    HistoryNode *newNode = (HistoryNode *)malloc(sizeof(HistoryNode));
    if (newNode == NULL) return;

    newNode->move.col = strdup(move.col);
    newNode->move.to = strdup(move.to);
    newNode->move.card = (move.card != NULL) ? strdup(move.card) : NULL;
    newNode->move.revealedCard = move.revealedCard;
    newNode->next = history->head;
    history->head = newNode;
}