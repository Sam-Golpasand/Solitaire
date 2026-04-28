#include "moveHandler.h";


// SAme logic as the other parser in utils.c
int parseMove(char *input, Move *move) {
    move->col = input;
    move->from = NULL;
    move->to = NULL;

    while (*input != ':' && *input != '\0') {
        input++;
    }

    if (*input == '\0') return 0;

    *input = '\0';
    input++;

    move->from = input;

    while (*input != '-' && *input != '\0') {
        input++;
    }
    if (*input == '\0') return 0;

    *input = '\0';
    input++;

    if (*input == '>') {
        input++;
    }

    move->to = input;

    return 1;
}


int executeMove(Board *board, Move *move) {

}