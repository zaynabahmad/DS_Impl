CC = gcc
CFLAGS = -Wall -g
OBJS =  main.o customer_ser.o queue.o stack.o 
TARGET = customer_serProgram

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c customer_ser/customer_ser.h queue/queue.h stack/stack.h global.h
	$(CC) $(CFLAGS) -c main.c -o main.o

queue.o: queue/queue.c queue/queue.h global.h
	$(CC) $(CFLAGS) -c queue/queue.c -o queue.o

stack.o: stack/stack.c stack/stack.h global.h
	$(CC) $(CFLAGS) -c stack/stack.c -o stack.o

customer_ser.o: customer_ser/customer_ser.c customer_ser/customer_ser.h queue/queue.h stack/stack.h global.h
	$(CC) $(CFLAGS) -c customer_ser/customer_ser.c -o customer_ser.o

clean:
	rm -f $(OBJS) $(TARGET)