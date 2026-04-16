CC = gcc
CFLAGS = -Wall

all: Solitaire

# Main build
Solitaire: main.o linkedList.o load.o shuffleCmd.o utils.o
	$(CC) $(CFLAGS) main.o linkedList.o load.o shuffleCmd.o utils.o -o Solitaire
	del /Q *.o

# Individual builds
main.o: main.c linkedList.h load.h
	$(CC) $(CFLAGS) -c main.c

linkedList.o: linkedList.c linkedList.h
	$(CC) $(CFLAGS) -c linkedList.c

load.o: load.c load.h linkedList.h
	$(CC) $(CFLAGS) -c load.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

shuffleCmd.o: shuffleCmd.c shuffleCmd.h linkedList.h
	$(CC) $(CFLAGS) -c shuffleCmd.c

# Clean script
clean:
	del /Q *.o Solitaire