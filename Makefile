CC = gcc
CFLAGS = -Wall

all: Solitaire

# Main build
Solitaire: main.o linkedList.o
	$(CC) $(CFLAGS) main.o linkedList.o -o Solitaire
	rm -f *.o

# Individual builds
main.o: main.c linkedList.h
	$(CC) $(CFLAGS) -c main.c

linkedList.o: linkedList.c linkedList.h
	$(CC) $(CFLAGS) -c linkedList.c

# Clean script
clean:
	rm -f *.o Solitaire