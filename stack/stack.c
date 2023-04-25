#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* 
 * Initialize the stack
 */
void CreateStack(Stack *ps) {
    ps->top = NULL;
    ps->Size=0;
    ps->min_top = NULL;
}
/* 
 * Push an element onto the stack
 */
void Push(StackEntry e, Stack *ps) {
    StackNode *pn = (StackNode*) malloc(sizeof(StackNode));
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
    if (ps->min_top == NULL || e <= ps->min_top->entry) {
        StackNode *min_node = (StackNode*) malloc(sizeof(StackNode));
        min_node->entry = e;
        min_node->next = ps->min_top;
        ps->min_top = min_node;
    }
    ps->Size++;
}

/*
 * Pop an element from the stack
 */
void Pop(StackEntry *pe, Stack *ps) {
    
    StackNode* pn= ps->top;
    *pe =ps->top->entry;
    ps->top=ps->top->next;
    ps->Size--;
    free (pn);
     if (ps->min_top != NULL && *pe == ps->min_top->entry) {
        StackNode *min_node = ps->min_top;
        ps->min_top = min_node->next;
        free(min_node);
    }
}

/* 
 * find if the stack is empty or not 
 */
 bool StackEmpty(Stack *ps) {
    return ps->top == NULL;
}

bool StackFull(Stack *ps) {
    return false; // stack implemented with linked list cannot be full
}

void ClearStack(Stack * ps){
    StackNode *pn = ps->top;
    StackNode *temp;
    while(pn != NULL) {
        temp = pn;
        pn = pn->next;
        free(temp);
    }
    ps->top = NULL;
    ps->min_top = NULL;
    ps->Size = 0;
}

void TraverseStack(Stack *ps , void(*pf)(StackEntry)){
  StackNode *pn = ps->top;
  while (pn != NULL) {
     (*pf)(pn->entry);
     pn =pn->next;
  
  }
}

int StackSize(Stack *ps){
    return ps->Size;
}
StackEntry FindMin(Stack *ps) {
    if (ps->min_top != NULL) {
        return ps->min_top->entry;
    }
    return 0; // or any other default value if the stack is empty
}

StackEntry Top_FirstElement(Stack *ps) {      //peek fuction 
    if (ps->top == NULL) {
        printf("Error: Stack is empty\n");
        return -1; // Assuming -1 is not a valid element in the stack
    }
    return ps->top->entry;
}

void destroy_stack(Stack * ps) {
    if (ps == NULL) {
        return;
    }
    while (ps->top != NULL) {
        StackNode* temp = ps->top;
        ps->top = ps->top->next;
        free(temp);
        StackNode* temp_min = ps->min_top;
        ps->min_top = ps->min_top->next;
        free(temp_min);
    }
    
    free(ps);
}

