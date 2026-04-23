#include "../utils/linkedList.h"

void play(Node *head, Board *board) {

    Node *currentHead = head;
    // add the first card to each row
    Node *currentC1Head = currentHead;
    currentHead = currentHead->next;
    Node *currentC2Head = currentHead;
    currentHead = currentHead->next;
    Node *currentC3Head = currentHead;
    currentHead = currentHead->next;
    Node *currentC4Head = currentHead;
    currentHead = currentHead->next;
    Node *currentC5Head = currentHead;
    currentHead = currentHead->next;
    Node *currentC6Head = currentHead;
    currentHead = currentHead->next;
    Node *currentC7Head = currentHead;

    board->C1 = currentC1Head;
    board->C2 = currentC2Head;
    board->C3 = currentC3Head;
    board->C4 = currentC4Head;
    board->C5 = currentC5Head;
    board->C6 = currentC6Head;
    board->C7 = currentC7Head;

    int ROW = 1; // we have already taken 7 cards from the deck (1 row)

    // loops through the deck and adds a card to each row.
    while (ROW < 11) {
        if (ROW < 6) {
            currentHead = currentHead->next;
            currentC2Head->next = currentHead;
            currentC2Head = currentC2Head->next;
        }
        if (ROW < 7) {
            currentHead = currentHead->next;
            currentC3Head->next = currentHead;
            currentC3Head = currentC3Head->next;
        }
        if (ROW < 8) {
            currentHead = currentHead->next;
            currentC4Head->next = currentHead;
            currentC4Head = currentC4Head->next;
        }
        if (ROW < 9) {
            currentHead = currentHead->next;
            currentC5Head->next = currentHead;
            currentC5Head = currentC5Head->next;
        }
        if (ROW < 10) {
            currentHead = currentHead->next;
            currentC6Head->next = currentHead;
            currentC6Head = currentC6Head->next;
        }
        if (ROW < 11) {
            currentHead = currentHead->next;
            currentC7Head->next = currentHead;
            currentC7Head = currentC7Head->next;
        }
        ROW++;
    }

    // makes the last card in each column point to NULL, to split the link between the different linked lkists
    currentC1Head->next = NULL;
    currentC2Head->next = NULL;
    currentC3Head->next = NULL;
    currentC4Head->next = NULL;
    currentC5Head->next = NULL;
    currentC6Head->next = NULL;
    currentC7Head->next = NULL;

    return;
}