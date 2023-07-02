/**
 * Implementation of a stack data structure with along with its operations, 
 * supports a function that returns the first element in a stack.
 * and a function to destroy a stack.
 * and a function to copy a stack to another.
 * and a function to return the size of a stack
 * 
 * Author: [Zaynap]
 * Date: 
 */

#include <stdio.h>
#include <stdlib.h>

#define _STACK_ARRAY_IMPL_
#include "stack.h"
/***********************************array based ***********************/

    /**
    * Initializes a new stack with empty top node, with the top index zero .
    */
    void CreateStack(Stack *ps) {
        ps->top = 0;
    } //O(1)


    /**
    * Pushes a new element onto the top of the stack and updates the minimum node if 
    * the new element is smaller than or equal to the current minimum.
    * 
    * @param e the element to be pushed onto the stack
    * @param ps a pointer to the stack
    */
    void Push(StackEntry e, Stack *ps) {
        ps->entry[ps->top++]=e;

    }


    /**
    * Removes the top element from the stack and updates the minimum node if necessary.
    * 
    * @param pe a pointer to store the removed element
    * @param ps a pointer to the stack
    */
    void Pop(StackEntry *pe, Stack *ps) {
        
    }


    /**
    * Returns true if the stack is empty and false if it has elements.
    * 
    * @param ps a pointer to the stack
    * @return true if the stack is empty and false if it has elements
    */
    bool StackEmpty(Stack *ps) {
       
    }


    /**
    * Returns false since the stack is never full (limited by available memory).
    * 
    * @param ps a pointer to the stack
    * @return false
    */
    bool StackFull(Stack *ps) {
        
    }


    /**
    * Removes all the saved elements in the stakc also free the memory from the heap
    * 
    * @param ps a pointer to the stack
    * 
    */
    void ClearStack(Stack *ps) {
        
    }


    /**
    * Traverses the stack and applies a function to each element
    * 
    * @param ps a pointer to the stack
    * @param pf a function pointer to a function that takes a StackEntry as argument and returns void
    * 
    */
    void TraverseStack(Stack *ps, void(*pf)(StackEntry)) {
       
    }


    /**
    * Returns the number of elements in the stack
    * 
    * @param ps a pointer to the stack
    * @return an integer representing the number of elements in the stack
    * 
    */
    int StackSize(Stack *ps) {
        
    }


    /**
    * Returns the minimum value in the stack
    * 
    * @param ps a pointer to the stack
    * @return a StackEntry representing the minimum value in the stack
    * 
    */
    StackEntry FindMin(Stack *ps) {
       
    }


    /**
    * Returns the top element in the stack without removing it
    * 
    * @param ps a pointer to the stack
    * @return a StackEntry representing the top element in the stack
    * 
    */
    StackEntry Peek(Stack *ps) {
       
    }


    /**
    * Frees the memory allocated for the stack and all its elements
    * 
    * @param ps a pointer to the stack
    * 
    */
    void DestroyStack(Stack *ps) {
        
    } 


    /**
    * Returns the first element that was added to the stack.
    * If the stack is empty, returns -1 and prints an error message.
    * 
    * @param ps Pointer to the stack
    * @return The first element that was added to the stack, or -1 if the stack is empty
    */
    int FirstElementAdded(Stack* ps) {
        
    }


    /**
    * copying the first stack to the second one .
    * coping the content , size , min_value_stack
    * 
    * @param ps Pointer to the  first stack
    * @param ps2 Pointer to the  second stack
    */
    void CopyStack(Stack *ps, Stack *ps2) {
        
    }






