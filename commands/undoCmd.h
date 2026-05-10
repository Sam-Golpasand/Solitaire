//
// Created by Albi :0 on 08/05/2026.
//

#ifndef SOLITAIRE_UNDOCMD_H
#define SOLITAIRE_UNDOCMD_H

#include "../utils/moveHandler.h"

typedef struct HistoryNode {
    Move move;
    struct HistoryNode *next;
} HistoryNode;

typedef struct MoveHistory{
    HistoryNode *head;
} MoveHistory;

int undoMove(Board *board, MoveHistory *history);

Move popMove(MoveHistory *history);
void pushMove(MoveHistory *history, Move move);


#endif //SOLITAIRE_UNDOCMD_H
