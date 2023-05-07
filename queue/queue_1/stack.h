/**
 * @file stack.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>
#ifdef QUEUE_USE_STACK_IMP 

 
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;
    int size;
} Stack;


void push(Stack* stack, int data);
int pop(Stack* stack);
int isEmpty(Stack* stack);

#elif defined STACK_USE_QUEUE_IMP
    #define USE_LINKEDLIST_IMPLEMENTATION
    #include "queue.h"
     
typedef struct stack {
    Queue q1;
    Queue q2;
} Stack;

#endif
#endif
