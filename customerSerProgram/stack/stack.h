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

#ifndef STACK_H
#define STACK_H

#include "../global.h"

typedef struct {
  int top;
  StackEntry entry[MAX_STACK_SIZE];
} Stack;

void CreateStack(Stack* s);
int isStackEmpty(Stack* s);
int isStackFull(Stack* s);
void push(StackEntry e, Stack* s);
void pop(StackEntry* e, Stack* s);
void ClearStack(Stack* s);

#endif
