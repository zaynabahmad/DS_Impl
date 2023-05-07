CC = gcc
CFLAGS = -Wall -g
OBJS =  main.o customer_ser.o queue.o stack.o 
TARGET = task1

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c stack.h queue.h customer_ser.h global.h
	$(CC) $(CFLAGS) -c main.c

queue.o: queue.c queue.h global.h
	$(CC) $(CFLAGS) -c queue.c

stack.o: stack.c global.h stack.h
	$(CC) $(CFLAGS) -c stack.c

customer_ser.o: customer_ser.c queue.h stack.h global.h customer_ser.h
	$(CC) $(CFLAGS) -c customer_ser.c



clean:
	rm -f $(OBJS) $(TARGET)