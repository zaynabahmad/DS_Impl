/**
 * @file stack_used_fun.c
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

void push(Stack* stack, int data) {
    StackNode* newNode = (StackNode*) malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Stack underflow\n");
        return -1;
    }
    StackNode* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}
