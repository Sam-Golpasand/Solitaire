#include <stdlib.h>

#include "../utils/linkedList.h"

void appendNode(Node **head, Node *node) {
    Node *tmp = *head;

    if (*head == NULL) {
        *head = node;
        return;
    }

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = node;
}

void play(Node *head, Board *board) {
    int ROW = 0;
    Node *current = head;

    if (head == NULL || board == NULL) {
        return;
    }

    board->C1 = NULL;
    board->C2 = NULL;
    board->C3 = NULL;
    board->C4 = NULL;
    board->C5 = NULL;
    board->C6 = NULL;
    board->C7 = NULL;

    while (current != NULL && ROW < 11) {
        if (ROW <= 0 && current != NULL) {
            Node *next = current->next;
            current->next = NULL;
            appendNode(&board->C1, current);
            current = next;
        }

        if (ROW <= 5 && current != NULL) {
            Node *next = current->next;
            current->next = NULL;
            appendNode(&board->C2, current);
            current = next;
        }

        if (ROW <= 6 && current != NULL) {
            Node *next = current->next;
            current->next = NULL;
            appendNode(&board->C3, current);
            current = next;
        }

        if (ROW <= 7 && current != NULL) {
            Node *next = current->next;
            current->next = NULL;
            appendNode(&board->C4, current);
            current = next;
        }

        if (ROW <= 8 && current != NULL) {
            Node *next = current->next;
            current->next = NULL;
            appendNode(&board->C5, current);
            current = next;
        }

        if (ROW <= 9 && current != NULL) {
            Node *next = current->next;
            current->next = NULL;
            appendNode(&board->C6, current);
            current = next;
        }

        if (ROW <= 10 && current != NULL) {
            Node *next = current->next;
            current->next = NULL;
            appendNode(&board->C7, current);
            current = next;
        }
        ROW++;
    }
}