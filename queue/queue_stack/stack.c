/**
 * @file stack.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include "stack.h"

void CreateStack(Stack* s) {
  s->top = -1;
}

int isStackEmpty(Stack* s) {
  return (s->top == -1);
}

int isStackFull(Stack* s) {
  return (s->top == MAX_STACK_SIZE - 1);
}

void push(StackEntry e, Stack* s) {
  if (isStackFull(s)) {
    printf("Stack overflow\n");
  } else {
    s->entry[++s->top] = e;
  }
}

void pop(StackEntry* e, Stack* s) {
  if (isStackEmpty(s)) {
    printf("Stack underflow\n");
  } else {
    *e = s->entry[s->top--];
  }
}

void ClearStack(Stack* s) {
  s->top = -1;
}
