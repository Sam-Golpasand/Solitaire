#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "tcpHandler.h"
#include "utils.h"

int runTcpServer(int port) {
    int serverFD, newSocket;

    // structure to hold the socket address information
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFERSIZE] = {0};
    char response[BUFFERSIZE] = {0};

    // create a socket file descriptor
    if ((serverFD = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Server failes to create socket");
        exit(EXIT_FAILURE);
    }

    // set socket settings
    if (setsockopt(serverFD, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // set addres settings
    address.sin_family = AF_INET;

    address.sin_addr.s_addr = INADDR_ANY;

    address.sin_port = htons(port);

    if (bind(serverFD, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(serverFD, 3) < 0) {
        perror("listening failed");
        exit(EXIT_FAILURE);
    }

    printf("This little maneuver's gonna cost us 51 years...\nlistening on port %d\n", port);

    // This loop accept new clients continuously
    while (1) {
        printf("Waiting for connection...\n");

        if ((newSocket = accept(serverFD, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept failed");
            continue;
        }

        printf("Client connected: %s\n", inet_ntoa(address.sin_addr));

        Board board = {0};
        Phase currentPhase = STARTUP;
        int commandStatus = 1;
        // exit signal
        if (commandStatus == -1) {
            break;
        }
        Node *head = NULL;

        // This loop read/respond until client disconnects
        ssize_t valread;
        while ((valread = read(newSocket, buffer, BUFFERSIZE - 1)) > 0) {
            buffer[valread] = '\0'; // add a terminator to the buffer so we dont overflow.

            if (currentPhase == PLAY) {
                showBoard(&board);
            }

            commandStatus = commandHandler(buffer, &head, &currentPhase, &board);

            // exit signal
            if (commandStatus == -1) {
                break;
            }

            
            char response[1024];
            char *boardString = parseBoard(&board, response, currentPhase, commandStatus);

            // response
            // snprintf(response, sizeof(response), "Server received: %.2030s", buffer);
            if (send(newSocket, boardString, strlen(boardString), 0) < 0) {
                perror("send failed");
                break;
            }

            // reset buffer and response so its ready.
            memset(buffer, 0, sizeof(buffer));
            memset(response, 0, sizeof(response));
        }

        if (valread == 0) {
            printf("Client disconnected.\n");
        }
        else if (valread < 0) {
            perror("read failed");
        }

        close(newSocket);
    }

    close(serverFD);
    return 0;
}

char *parseBoard(Board *board, char *response, Phase currentPhase, int commandStatus) {

    response[0] = '\0';

    char *columnFoundationNames[] = {"C1", "C2", "C3", "C4", "C5", "C6", "C7", "F1", "F2", "F3", "F4"};

    sprintf(response, "%s|%d|", commandStatus ? "OK" : "ERROR", currentPhase);

    int count = 11;

    for (int i = 0; i < 11; i++) {
        const char *currentCol = columnFoundationNames[i];
        Node *col = getColumnByName(board, currentCol);

        strcat(response, currentCol);
        strcat(response, "=");

        while (col != NULL) {
            char cardStr[16];

            sprintf(cardStr, "%s%s%d", col->card->rank, col->card->suit, col->card->isVisible);

            strcat(response, cardStr);
            
            if (col->next != NULL) {
                strcat(response, ",");
            }
                

            col = col->next;
        }
        if (i < count - 1) {
            strcat(response, ";");
        }
            
    }

    return response;

}