#include <stdlib.h>

#include "../utils/linkedList.h"

// Helper function to append notes to list
static void appendNode(Node **head, Node *node) {
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

// Frees all nodes in a linked list and their Card data
// DO NOT USE OUTSIDE THIS FILE - KEEP STATIC
static void freeList(Node *head) {
    while (head != NULL) {
        Node *next = head->next;
        free(head->card);
        free(head);
        head = next;
    }
}

// Helper function to free board and reset pointers
void freeBoard(Board *board) {
    freeList(board->C1);
    freeList(board->C2);
    freeList(board->C3);
    freeList(board->C4);
    freeList(board->C5);
    freeList(board->C6);
    freeList(board->C7);

    board->C1 = NULL;
    board->C2 = NULL;
    board->C3 = NULL;
    board->C4 = NULL;
    board->C5 = NULL;
    board->C6 = NULL;
    board->C7 = NULL;
}

Node *copyList(Node *head) {
    if (head == NULL) return NULL;

    Node *newHead = NULL;
    Node *tail = NULL;

    while (head != NULL) {
        Node *n = malloc(sizeof(Node));
        n->card = malloc(sizeof(Card));
        *n->card = *head->card;

        n->next = NULL;

        if (newHead == NULL) {
            newHead = n;
            tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
        head = head->next;
    }
    return newHead;
}



void play(Node *head, Board *board) {
    int ROW = 0;
    Node *current = head;

    if (head == NULL || board == NULL) {
        return;
    }
    while (current != NULL && ROW < 11) {
        if (ROW <= 0) {
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

        if (current != NULL) {
            Node *next = current->next;
            current->next = NULL;
            appendNode(&board->C7, current);
            current = next;
        }
        ROW++;
    }
}