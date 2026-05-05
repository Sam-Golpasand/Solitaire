#include "moveHandler.h"

// SAme logic as the other parser in utils.c
int parseMove(char *input, Move *move)
{
    move->col = NULL;
    move->card = NULL;
    move->to = NULL;

    if (input == NULL || *input == '\0') {
        return 0;
    }

    char *dash = input;
    while (*dash != '-' && *dash != '\0') {
        dash++;
    }

    if (*dash == '\0') {
        return 0;
    }

    *dash = '\0';

    char *right = dash + 1;
    if (*right == '>') {
        right++;
    }

    if (*right == '\0') {
        return 0;
    }

    move->to = right;

    char *left = input;
    if (*left == '\0') {
        return 0;
    }

    char *colon = left;
    while (*colon != ':' && *colon != '\0') {
        colon++;
    }

    if (*colon == ':') {
        *colon = '\0';
        colon++;
        if (*colon == '\0') {
            return 0;
        }
        move->card = colon;
    }

    move->col = left;

    return 1;
}


 
int parseIndex(char *col)
{
    char type = col[0];
    int index = col[1] - '0';

    if (type == 'C' && index >= 1 && index <= 7)
        return index;

    if (type == 'F' && index >= 1 && index <= 4)
        return index;

    return -1;
}

Node **getColumn(Board *board, int index) {
    switch (index)
    {
    case 1: return &board->C1;
    case 2: return &board->C2;
    case 3: return &board->C3;
    case 4: return &board->C4;
    case 5: return &board->C5;
    case 6: return &board->C6;
    case 7: return &board->C7; 
    default:
        return NULL;
    }
}

Node **getFoundation(Board *board, int index)
{
    switch (index)
    {
        case 1: return &board->F1;
        case 2: return &board->F2;
        case 3: return &board->F3;
        case 4: return &board->F4;
        default:
            return NULL;
    }
}

int getRank (Card *card) {
    if (card->rank == 'A') {
        return 1;
    }
    if (card->rank == 'T') {
        return 10;
    }
    if (card->rank == 'J') {
        return 11;
    }
    if (card->rank == 'Q') {
        return 12;
    }
    if (card->rank == 'K') {
        return 13;
    }
    return card->rank - '0';
}

// 1 for red and 0 for black
int getColor(Card *card) {
    if (card->suit == 'H' || card->suit == 'D') {
        return 1;
    }
    return 0;
}

Node *findCard(Node *head, char *target, Node **prev)
{
    *prev = NULL;

    while (head)
    {
        if (head->card->rank == target[0] &&
            head->card->suit == target[1])
        {
            return head;
        }

        *prev = head;
        head = head->next;
    }

    return NULL;
}

int executeMove(Board *board, Move *move){
    if (!move->col || !move->to) {
        return 0;
    }

    int fromIndex = parseIndex(move->col);
    int toIndex = parseIndex(move->to);

    if (fromIndex == -1 || toIndex == -1) {
        return 0;
    }

    Node **fromPile;
    Node **toPile;

    if (move->col[0] == 'C') {
        fromPile = getColumn(board, fromIndex);
    } else {
        fromPile = getFoundation(board, fromIndex);
    }

    if (move->to[0] == 'C') {
        toPile = getColumn(board, toIndex);
    } else {
        toPile = getFoundation(board, toIndex);
    }


    if (!fromPile || !*fromPile || !toPile) {
        return 0;
    }

    // Only allow moving the top card from a foundation (no explicit card selection).
    if (move->col[0] == 'F' && move->card != NULL) {
        return 0;
    }

    // Same here but just if it is a definied foundation move.
    if (move->to[0] == 'F' && move->col[0] == 'F') {
        return 0;
    }
    
    //* movement tech
    Node *nodeBeforeMoveCard = NULL;
    Node *moveCard = NULL;

    if (move->card != NULL) {
        moveCard = findCard(*fromPile, move->card, &nodeBeforeMoveCard);
    } else {
        Node *current = *fromPile;
        Node *prev = NULL;

        // I want to use getLast() here but we also need the previous. Maybe a todo
        while (current && current->next) {
            prev = current;
            current = current->next;
        }
        moveCard = current;
        nodeBeforeMoveCard = prev;
    }

    if (!moveCard) {
        return 0;
    }

    // if there is a card before the card we are moving then make its next be null and detach
    if (nodeBeforeMoveCard) {
        nodeBeforeMoveCard->next = NULL;
    } else {
        *fromPile = NULL;
    }


    // Validaton. We do this now and rollback if its invalid since the validity depensd on the boards current state.
    int valid;
    if (move->to[0] == 'C') {
        valid = validColumnMove(*toPile, moveCard);
    } else {
        valid = validFoundationMove(*toPile, moveCard);
    }

    // rollback if not valid
    if (!valid) {
        if (nodeBeforeMoveCard) {
            nodeBeforeMoveCard->next = moveCard;
        } else {
            *fromPile = moveCard;
        }
        return 0;
    }

    if (nodeBeforeMoveCard && !nodeBeforeMoveCard->card->isVisible) {
        nodeBeforeMoveCard->card->isVisible = 1;
    }


    // actually move
    if (!*toPile) {
        *toPile = moveCard;
    } else {
        Node *last = getLast(*toPile);
        last->next = moveCard;
    }

    return 1;

}


int validColumnMove(Node *dest, Node *moveCard) {

    if (!dest) {
        if (getRank(moveCard->card) == 13) {
            return 1;
        }
    }

    if (!moveCard->card->isVisible) {
        return 0;
    }

    Node *lastCard = getLast(dest);

    int destRank = getRank(lastCard->card); 
    char destSuit = lastCard->card->suit;

    char moveSuit = moveCard->card->suit;
    int moveRank = getRank(moveCard->card);

    if (destSuit != moveSuit && destRank - 1 == moveRank ) {
        return 1;
    }
    
    return 0;

}

int validFoundationMove(Node *dest, Node *moveCard) {
    if (moveCard->next != NULL) {
        return 0;
    }

    if (!dest) {
        return getRank(moveCard->card) == 1;
    }

    Node *lastCard = getLast(dest);
    
    int destRank = getRank(lastCard->card); 
    char destSuit = lastCard->card->suit;

    char moveSuit = moveCard->card->suit;
    int moveRank = getRank(moveCard->card);

    if (destSuit == moveSuit && moveRank == destRank + 1) {
        return 1;
    }
    
    return 0;

}