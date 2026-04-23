#include <stdlib.h>

#include "../utils/linkedList.h"

void play(Node *head, Board *board) {
    int ROW = 0;
    Node *current = head;

    if (head == NULL || board == NULL) {
        return;
    }

    while (current != NULL) {
        if (ROW < 1) {
            board->C1 = current;
            current = current->next;
        }

        if (ROW < 6) {
            board->C2 = current;
            current = current->next;
        }

        if (ROW < 7) {
            board->C3 = current;
            current = current->next;
        }

        if (ROW < 8) {
            board->C4 = current;
            current = current->next;
        }

        if (ROW < 9) {
            board->C5 = current;
            current = current->next;
        }

        if (ROW < 10) {
            board->C6 = current;
            current = current->next;
        }

        if (ROW < 11) {
            board->C7 = current;
            current = current->next;
        }

        ROW++;
    }
}

static void appendNode(Card card, Node *head) {


}