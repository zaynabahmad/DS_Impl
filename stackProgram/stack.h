/*
* this file for linked impl and array based impl
*
*
*
*/

#ifndef stack_H_
#define stack_H_
#include <stdbool.h>

typedef char StackEntry;
/*******************linked impl***********************/
#ifdef _STACK_LINKED_IMPL_


    typedef struct stack_node {
        StackEntry entry;
        struct stack_node *next;
    } StackNode;

    typedef struct stack {
        StackNode *top; // aointer to the stacknode 
        StackNode *min_top; //pointer to the minumium element in the stack 
        StackEntry Size; //a field to hold the size 
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



 #elif defined _STACK_ARRAY_IMPL_
/**************array implementation of a stack************************/

    #define MAXSTACK 10000 
    typedef struct stack{
        int top ;   /* index of next available slot */
        StackEntry entry[MAXSTACK];
    }Stack;

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





#endif //STACK_LINKED_IMPL_
#endif //stack_H_