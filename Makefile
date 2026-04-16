CC = gcc
CFLAGS = -Wall

all: Solitaire

# Main build
Solitaire: main.o linkedList.o loadCmd.o utils.o
	$(CC) $(CFLAGS) main.o linkedList.o loadCmd.o utils.o -o Solitaire
	rm -f *.o

# Individual builds
main.o: main.c linkedList.h loadCmd.h utils.h
	$(CC) $(CFLAGS) -c main.c

linkedList.o: linkedList.c linkedList.h
	$(CC) $(CFLAGS) -c linkedList.c

loadCmd.o: loadCmd.c loadCmd.h linkedList.h
	$(CC) $(CFLAGS) -c loadCmd.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

# Clean script
clean:
	rm -f *.o Solitaire