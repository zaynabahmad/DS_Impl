/**
 * @file queue_using_stack.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_USE_STACK_IMP
#include "stack.h"
#include "queue.h"

// Initialize the two stacks that will be used to implement the queue
void createQueue(Queue* queue) {
    queue->stack1 = (Stack*) malloc(sizeof(Stack));
    queue->stack1->top = NULL;
    queue->stack2 = (Stack*) malloc(sizeof(Stack));
    queue->stack2->top = NULL;
}

// Add an element to the end of the queue
void Append(QueueEntry data , Queue* queue) {
    push(queue->stack1, data);
}

// Remove the first element from the queue and return it
void Serve(QueueEntry *data, Queue* queue) {
    // If both stacks are empty, the queue is empty
    if (isEmpty(queue->stack1) && isEmpty(queue->stack2)) {
        printf("Error: Queue underflow\n");
        return;
    }
    if (isEmpty(queue->stack2)) {
        // If stack 2 is empty, move all elements from stack 1 to stack 2 to reverse their order
        while (!isEmpty(queue->stack1)) {
            QueueEntry item = pop(queue->stack1);
            push(queue->stack2, item);
        }
    }
    // Remove the top element from stack 2 and return it
    *data = pop(queue->stack2);
}
// Check if the queue is empty
int QueueEmpty(Queue *pq){
    return isEmpty(pq->stack1) && isEmpty(pq->stack2);
}






