#ifndef TCP_HANDLER_H
#define TCP_HANDLER_H

#define TCP_DEFAULT_PORT 5050
#define BUFFERSIZE 2048
#include "./linkedList.h"
#include "utils.h"

int runTcpServer(int port);

static char *parseBoard(Board *board, char *response, Phase currentPhase, int commandStatus);

static char *parseDeck(Node *head, char *response, Phase currentPhase, int commandStatus);
#endif
