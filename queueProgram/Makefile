CC = gcc
CFLAGS = -Wall -g
OBJS = queue_array_impl.o main.o 
TARGET = queue

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

queue_array_impl.o: queue_array_impl.c queue.h
	$(CC) $(CFLAGS) -c queue_array_impl.c

# if you will use the array based use these lines 
# instead of above line and comment out previous one

# queue_linked_impl.o : queue_linked_impl.c queue.h
#     $(CC) $(CFLAGS) -c queue_linked_impl.c


main.o: main.c queue.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(OBJS) $(TARGET)