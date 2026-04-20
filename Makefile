# detect if Windows
ifeq ($(OS),Windows_NT)
    EXE = .exe
    RM = del /Q
else
    EXE =
    RM = rm -f
endif

CC = gcc
CFLAGS = -Wall
TARGET = Solitaire$(EXE)
OBJS = main.o linkedList.o loadCmd.o utils.o SI.o saveCmd.o

all: $(TARGET)

# main builds
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
	$(RM) *.o

# Individual
main.o: main.c linkedList.h loadCmd.h utils.h
	$(CC) $(CFLAGS) -c main.c

linkedList.o: linkedList.c linkedList.h
	$(CC) $(CFLAGS) -c linkedList.c

loadCmd.o: loadCmd.c loadCmd.h linkedList.h
	$(CC) $(CFLAGS) -c loadCmd.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

SI.o: SI.c SI.h linkedList.h
	$(CC) $(CFLAGS) -c SI.c

saveCmd.o: saveCmd.c saveCmd.h loadCmd.h
	$(CC) $(CFLAGS) -c saveCmd.c

# Clean
clean:
	$(RM) *.o $(TARGET)