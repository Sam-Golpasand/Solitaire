#include "SI.h"

Node* splitDeck(int split, Node **head) {
    if (split > 52 || split <= 0 || head == NULL || *head == NULL) {
        return NULL;
    }

    Node *head1 = *head;
    Node *head2 = *head;

    for (int i = 0; i < split; i++) {
        if (head2->next == NULL) {
            return NULL;
        }
        head2 = head2->next;
        if (i == split - 1) {
            head1->next = NULL;
            break;
        }
        head1 = head1->next;
    }

    head1 = *head;
    Node *rHead;
    Node *tempHead;
    int firstFlag = 1;
    while (head1 != NULL && head2 != NULL) {
        if (firstFlag == 1) {
            rHead = head1;
            head1 = head1->next;
            tempHead = rHead;
            tempHead->next = head2;
            firstFlag = 0;
            tempHead = tempHead->next;
            head2 = head2->next;
            continue;
        }
        tempHead->next = head1;
        head1 = head1->next;
        tempHead = tempHead->next;
        tempHead->next = head2;
        head2 = head2->next;
        tempHead = tempHead->next;
    }
    if (head1 == NULL) {
        tempHead->next = head2;
    }
    else if (head2 == NULL) {
        tempHead->next = head1;
    }
    else {
        return NULL;
    }

    return rHead;
}
