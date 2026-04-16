CC = gcc
CFLAGS = -Wall

all: Solitaire

# Main build
Solitaire: main.o linkedList.o load.o utils.o SI.o
	$(CC) $(CFLAGS) main.o linkedList.o load.o utils.o -o Solitaire
	rm -f *.o

# Individual builds
main.o: main.c linkedList.h load.h utils.h
	$(CC) $(CFLAGS) -c main.c

linkedList.o: linkedList.c linkedList.h
	$(CC) $(CFLAGS) -c linkedList.c

load.o: load.c load.h linkedList.h
	$(CC) $(CFLAGS) -c load.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

SI.o: SI.c SI.h linkedList.h
	$(CC) $(CFLAGS) -c SI.c

# Clean script
clean:
	rm -f *.o Solitaire