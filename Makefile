CC = gcc
CFLAGS = -Wall

all: Solitaire

# Main build
Solitaire: main.o linkedList.o load.o shuffle.o utils.o
	$(CC) $(CFLAGS) main.o linkedList.o load.o shuffle.o utils.o -o Solitaire
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

shuffle.o: shuffle.c shuffle.h linkedList.h
	$(CC) $(CFLAGS) -c shuffle.c

# Clean script
clean:
	del /Q *.o Solitaire