#include <stdio.h>
#include <stdlib.h>
#define USE_LINKEDLIST_IMPLEMENTATION
#define STACK_USE_QUEUE_IMP
#include "queue.h"
#include "stack.h"

void createStack(Stack *ps) {
    CreateQueue(&ps->q1);
    CreateQueue(&ps->q2);
}

int isEmptyStack(Stack *ps) {
    return QueueEmpty(&ps->q1) && QueueEmpty(&ps->q2);
}

void push(Stack *ps, int data) {
    if (QueueEmpty(&ps->q1)) {
        Append(data ,&ps->q2);
    } else {
        Append(data ,&ps->q1);
    }
}

int pop(Stack *ps) {
    int data;
    if (isEmptyStack(ps)) {
        printf("Error: Stack underflow\n");
        return -1;
    }
    if (QueueEmpty(&ps->q1)) {
        while (!QueueEmpty(&ps->q2)) {
             Serve(&data ,&ps->q2);
            if (!QueueEmpty(&ps->q2)) {
                Append(data ,&ps->q1);
            }
        }
    } else {
        while (!QueueEmpty(&ps->q1)) {
             Serve(&data ,&ps->q1);
            if (!QueueEmpty(&ps->q1)) {
                Append(data ,&ps->q2);
            }
        }
    }
    return data;
}


