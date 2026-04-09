CC = gcc
CFLAGS = -Wall

all: Solitaire

# Main build
Solitaire: main.o linkedList.o load.o
	$(CC) $(CFLAGS) main.o linkedList.o load.o -o Solitaire
	rm -f *.o

# Individual builds
main.o: main.c linkedList.h load.h
	$(CC) $(CFLAGS) -c main.c

linkedList.o: linkedList.c linkedList.h
	$(CC) $(CFLAGS) -c linkedList.c

load.o: load.c load.h linkedList.h
	$(CC) $(CFLAGS) -c load.c

# Clean script
clean:
	rm -f *.o Solitaire