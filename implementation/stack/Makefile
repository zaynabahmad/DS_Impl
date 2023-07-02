CC = gcc
CFLAGS = -Wall -g
OBJS = stack_linked_impl.o main.o 
TARGET = stack

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

stack_linked_impl.o: stack_linked_impl.c stack.h
	$(CC) $(CFLAGS) -c stack_linked_impl.c

# if you will use the array based use these lines 
# instead of above line and comment out previous one

# stack_array_impl.o : stack_array_impl.c stack.h
#     $(CC) $(CFLAGS) -c stack_array_impl.c


main.o: main.c stack.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(OBJS) $(TARGET)