CC = gcc
CFLAGS = -Wall -g
OBJS = stack.o main.o
TARGET = stack

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

main.o: main.c stack.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(OBJS) $(TARGET)
