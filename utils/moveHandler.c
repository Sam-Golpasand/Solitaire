#include "moveHandler.h";

// SAme logic as the other parser in utils.c
int parseMove(char *input, Move *move)
{
    move->col = input;
    move->from = NULL;
    move->to = NULL;

    while (*input != ':' && *input != '\0')
    {
        input++;
    }

    if (*input == '\0')
        return 0;

    *input = '\0';
    input++;

    move->from = input;

    while (*input != '-' && *input != '\0')
    {
        input++;
    }
    if (*input == '\0')
        return 0;

    *input = '\0';
    input++;

    if (*input == '>')
    {
        input++;
    }

    move->to = input;

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
    if (!move->col || !move->to || !move->from) {
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


    if (!fromPile || !*fromPile || !toPile || !*toPile) {
        return 0;
    }
    
    Node *nodeBeforeMoveCard = NULL;
    Node *moveCard = findCard(*fromPile, move->from, &nodeBeforeMoveCard);


    if (!moveCard) {
        return 0;
    }

    // if there is a card before the card we are moving then make its next be null and detach
    if (nodeBeforeMoveCard) {
        nodeBeforeMoveCard->next = NULL;
    } else {
        *fromPile = NULL;
    }





}


int validColumnMove(Node *dest, Node *moveCard) {

    if (!dest) {
        if (getRank(moveCard->card) == 13) {
            return 1;
        }
    }

    Node *lastCard = getLast(dest);

    int destRank = getRank(lastCard->card); 
    int destColor = getColor(lastCard->card);

    int moveColor = getColor(moveCard->card);
    int moveRank = getRank(moveCard->card);
    
    if (destColor != moveColor && destRank - 1 == moveRank ) {
        return 1;
    }
    
    return 0;

}