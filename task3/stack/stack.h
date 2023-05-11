/**
 * @file stack.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

 #ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 100
typedef int StackEntry;

#ifdef LINKED_STACK

/****************************** Linked implementation*****************************/

typedef struct stacknode {
StackEntry entry;
struct stacknode *next;
}StackNode;

typedef struct stack {
StackNode *top;
}Stack;

/* functions prototypes*/
StackNode *MakeStackNode(StackEntry item);
void Push(StackEntry item, Stack *ps);
void Pop(StackEntry *pitem, Stack *ps);
int StackEmpty(Stack *ps);
int StackFull(Stack *ps);
void CreateStack(Stack *ps);
void StackTop(StackEntry *pitem, Stack *ps);
int StackSize(Stack *ps);
void ClearStack(Stack *ps);
void TraverseStack(Stack *ps, void (*pvisit)(StackEntry));

#else

/***************************array based ******************************/

typedef struct stack {
int top;
StackEntry entry[MAXSTACK];
}Stack;

/* functions prototypes*/
void Push(StackEntry item, Stack *ps);
void Pop(StackEntry *item, Stack *ps);
int StackEmpty(Stack *ps);
int StackFull(Stack *ps);
void CreateStack(Stack *ps);
void StackTop(StackEntry *item, Stack *ps);
int StackSize(Stack *ps);
void ClearStack(Stack *ps);

#endif // LINKED_STACK

#endif /* STACK_H_ */