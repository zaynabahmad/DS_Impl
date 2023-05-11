/**
 * @file stack.c
 * @author zaynap (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */



 #include "stack.h"

 #ifdef LINKED_STACK


/****************************** Linked implementation*****************************/

/**
 * @brief Create a StackNode with the given item.
 * 
 * @param item : The item to create a node for.
 * @return StackNode* : A pointer to the created node.
 */
StackNode *MakeStackNode(StackEntry item){
	StackNode *p;

	p=(StackNode *)malloc(sizeof(StackNode));
	p->entry=item;
	p->next=NULL;
	return p;
}

/**
 * @brief Push an item onto the top of the stack.
 * 
 * @param item : The item to be pushed onto the stack.
 * @param ps : Pointer to the stack.
 */
void Push(StackEntry item, Stack *ps){
	StackNode *p=MakeStackNode(item);
	p->next=ps->top;
	ps->top=p;
}

/**
 * @brief Pop the top item from the stack.
 * 
 * @param pitem : Pointer to where the popped item will be stored.
 * @param ps : Pointer to the stack.
 */
void Pop(StackEntry *pitem, Stack *ps){
	StackNode *p;

	*pitem=ps->top->entry;
	p=ps->top;
	ps->top=ps->top->next;
	free(p);
}

/**
 * @brief Determine if the stack is empty.
 * 
 * @param ps : Pointer to the stack.
 * @return int : Non-zero if the stack is empty, zero otherwise.
 */
int StackEmpty(Stack *ps){
	return ps->top==NULL;
}

/**
 * @brief Determine if the stack is full.
 * 
 * @param ps : Pointer to the stack.
 * @return int : Non-zero if the stack is full, zero otherwise.
 */
int StackFull(Stack *ps){
	return 0;
}

/**
 * @brief Create an empty stack.
 * 
 * @param ps : Pointer to the stack.
 */
void CreateStack(Stack *ps){
    ps->top=NULL;
}

/**
 * @brief Retrieve the item on top of the stack.
 * 
 * @param pitem : Pointer to where the top item will be stored.
 * @param ps : Pointer to the stack.
 */
void StackTop(StackEntry *pitem, Stack *ps){
    *pitem=ps->top->entry;
}

/**
 * @brief Determine the size of the stack.
 * 
 * @param ps : Pointer to the stack.
 * @return int : The number of items in the stack.
 */
int StackSize(Stack *ps){
    int x;
    StackNode *ptrs=ps->top;
    for(x=0; ptrs; ptrs=ptrs->next)
        x++;
    return x;
}

/**
 * @brief Remove all items from the stack.
 * 
 * @param ps : Pointer to the stack.
 */
void ClearStack(Stack *ps){
    StackNode *p=ps->top;
    while(p){
        p=p->next;
        free(ps->top);
        ps->top=p;
    }
}

/**
 * @brief Traverse the stack, calling a function on each item.
 * 
 * @param ps : Pointer to the stack.
 * @param pvisit : Pointer to the function to be called on each item.
 */
void TraverseStack(Stack *ps, void (*pvisit)(StackEntry)){
    for(StackNode *p=ps->top; p; p=p->next)
        (*pvisit)(p->entry);
}


#else

/***************************array based ******************************/

/**
 * @brief Push : push an item onto the stack
 *       
 * @param item : the item to push into stack with type stackentry
 * @param ps   : pointer to the stack 
 */
void Push(StackEntry item, Stack *ps){
	ps->entry[ps->top++] = item;
}


/**
 * @brief Pop: pop an item from the stack.
 * 
 * @param item : the element to pop form the stack
 * @param ps   : pointer to the stack
 */
void Pop(StackEntry *item, Stack *ps){
	*item = ps->entry[--ps->top];
}

/**
 * @brief StackEmpty: returns non-zero if the stack is empty
 *        
 * @param ps : pointer to the stack 
 * @return int 
 */
int StackEmpty(Stack *ps){
     return ps->top <= 0;
	
}

/**
 * @brief StackFull: returns non-zero if the stack is full.
 *       
 * @param ps : pointer to the stack 
 * @return int 
 */
int StackFull(Stack *ps){
	return ps->top >= MAXSTACK;

}

/**
 * @brief CreateStack: initialize the stack to be empty.

 * 
 * @param ps : pointer to the stack
 */
void CreateStack(Stack *ps){
     ps->top = 0;
}

/**
 * @brief Retrieve the item on top of the stack.
 * 
 * @param item : pointer to where the top item will store
 * @param ps : pointer to the stack
 */
void StackTop(StackEntry *item, Stack *ps){                   
    *item = ps->entry[ps->top-1];   
}                     

/**
 * @brief Determine the size of the stack.
 * 
 * @param ps : Pointer to the stack.
 * @return int : The number of items in the stack.
 */
int StackSize(Stack *ps){
     return ps->top;
}

/**
 * @brief Remove all items from the stack.
 * 
 * @param ps : Pointer to the stack.
 */
void ClearStack(Stack *ps){
     ps->top = 0;
}

/**
 * @brief Traverse the stack, calling a function on each item.
 * 
 * @param ps : Pointer to the stack.
 * @param pvisit : Pointer to the function to be called on each item.
 */
void TraverseStack(Stack *ps, void (*pvisit)(StackEntry)){
	for(int i=ps->top; i>0; i--)
		(*pvisit)(ps->entry[i-1]);
}                                             

#endif