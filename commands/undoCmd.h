//
// Created by Albi :0 on 08/05/2026.
//

#ifndef SOLITAIRE_UNDOCMD_H
#define SOLITAIRE_UNDOCMD_H

#include <stdlib.h>
#include "../utils/moveHandler.h"

typedef struct HistoryNode {
    Move move;
    struct HistoryNode *next;
} HistoryNode;

typedef struct {
    HistoryNode *head;
} MoveHistory;

int undoCmd(Board *board, MoveHistory *history);

Move popMove(MoveHistory *history);


#endif //SOLITAIRE_UNDOCMD_H
