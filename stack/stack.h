/*
*
*
*
*
*/

#ifndef stack_H_
#define stack_H_
#include <stdbool.h>

typedef char StackEntry;

typedef struct stack_node {
    StackEntry entry;
    struct stack_node *next;
} StackNode;

typedef struct stack {
    StackNode *top;
    StackNode *min_top;
    StackEntry Size;
} Stack;

void CreateStack(Stack *ps);
void Push(StackEntry e, Stack *ps);
void Pop(StackEntry *pe, Stack *ps);
bool StackEmpty(Stack *ps);
bool StackFull(Stack *ps);
void ClearStack(Stack *ps);
int StackSize(Stack *ps);
StackEntry FindMin(Stack *ps);
StackEntry Peek(Stack *ps);
void DestroyStack(Stack *ps);
int FirstElementAdded(Stack* ps);
void TraverseStack(Stack *ps, void(*pf)(StackEntry));
void CopyStack (Stack *ps , Stack *ps2);
int Matching_parentheses(StackEntry *ptr );

#endif 