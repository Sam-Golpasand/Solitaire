#ifndef TCP_HANDLER_H
#define TCP_HANDLER_H

#define TCP_DEFAULT_PORT 5050
#define BUFFERSIZE 2048
#include "./linkedList.h"
#include "utils.h"
#include "../commands/undoCmd.h"

typedef struct MoveHistory MoveHistory;

int runTcpServer(int port, struct MoveHistory *history);

#endif
