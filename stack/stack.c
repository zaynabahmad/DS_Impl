/**
 * Implementation of a stack data structure with a minimum function that returns
 * the minimum value in the stack in constant time. The minimum value is stored
 * in a separate stack and updated when new elements are pushed or popped. The 
 * stack is implemented using a singly-linked list with a pointer to the top node.
 * 
 * Author: [Zaynap]
 * Date: 
 */




#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/**
 * Initializes a new stack with empty top node, size zero and null minimum node.
 */

void CreateStack(Stack *ps) {
    ps->top = NULL;
    ps->Size = 0;
    ps->min_top = NULL;
}

/**
 * Pushes a new element onto the top of the stack and updates the minimum node if 
 * the new element is smaller than or equal to the current minimum.
 * 
 * @param e the element to be pushed onto the stack
 * @param ps a pointer to the stack
 */

void Push(StackEntry e, Stack *ps) {
    // Allocate memory for new stack node
    StackNode *pn = (StackNode*) malloc(sizeof(StackNode));
    if (pn == NULL) {
        printf("Error: Could not allocate memory for new node\n");  //error
        exit(1);
    }

    // Initialize new node with given entry and update stack top
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;

    // Update minimum node if new element is smaller than or equal to current minimum
    StackEntry min;
    if (ps->min_top == NULL || e <= ps->min_top->entry) {
        min = e;
    } else {
        min = ps->min_top->entry;
    }
    StackNode *min_node = (StackNode*) malloc(sizeof(StackNode));
    if (min_node == NULL) {
        printf("Error: Could not allocate memory for new minimum node\n");  //error
        free(pn);
        exit(1); 
    }
    min_node->entry = e;
    min_node->entry = min;
    min_node->next = ps->min_top;
    ps->min_top = min_node;

    // Increment stack size
    ps->Size++;

}

/**
 * Removes the top element from the stack and updates the minimum node if necessary.
 * 
 * @param pe a pointer to store the removed element
 * @param ps a pointer to the stack
 */
void Pop(StackEntry *pe, Stack *ps) {
    // Remove top node and update stack top and size
    StackNode *pn = ps->top;
    if (pn == NULL) {
      printf("Error: Stack is empty\n");
      exit(1);
    }
    *pe = pn->entry;
    ps->top = pn->next;
    ps->Size--;
    free(pn);

    // Remove the top element from the minimum stack and update its top
    StackNode *min_node = ps->min_top;
    ps->min_top = min_node->next;
    free(min_node);

}

/**
 * Returns true if the stack is empty and false if it has elements.
 * 
 * @param ps a pointer to the stack
 * @return true if the stack is empty and false if it has elements
 */
bool StackEmpty(Stack *ps) {
    return ps->top == NULL;
}

/**
 * Returns false since the stack is never full (limited by available memory).
 * 
 * @param ps a pointer to the stack
 * @return false
 */
bool StackFull(Stack *ps) {
    return false;
}

/**
 * Removes all the saved elements in the stakc also free the memory from the heap
 * 
 * @param ps a pointer to the stack
 * 
 */
void ClearStack(Stack *ps) {
    StackNode *pn = ps->top;
    StackNode *temp;
    // remove the elements until it has no elements
    while (pn != NULL) {
        temp = pn;
        pn = pn->next;
        free(temp);
    }
    // free the memory allocated for min_top pointer
    while (ps->min_top != NULL) {
        temp = ps->min_top;
        ps->min_top = ps->min_top->next;
        free(temp);
    }
    // update the stack
    ps->top = NULL;
    ps->min_top = NULL;
    ps->Size = 0;
}

/**
 * Traverses the stack and applies a function to each element
 * 
 * @param ps a pointer to the stack
 * @param pf a function pointer to a function that takes a StackEntry as argument and returns void
 * 
 */
void TraverseStack(Stack *ps, void(*pf)(StackEntry)) {
    StackNode *pn = ps->top;
    while (pn != NULL) {
        (*pf)(pn->entry);
        pn = pn->next;
    }
}

/**
 * Returns the number of elements in the stack
 * 
 * @param ps a pointer to the stack
 * @return an integer representing the number of elements in the stack
 * 
 */
int StackSize(Stack *ps) {
    return ps->Size;
}

/**
 * Returns the minimum value in the stack
 * 
 * @param ps a pointer to the stack
 * @return a StackEntry representing the minimum value in the stack
 * 
 */
StackEntry FindMin(Stack *ps) {
    if (ps->min_top != NULL) {
        return ps->min_top->entry;
    }
    printf("Error: Stack is empty\n");
    exit(1);
}

/**
 * Returns the top element in the stack without removing it
 * 
 * @param ps a pointer to the stack
 * @return a StackEntry representing the top element in the stack
 * 
 */
StackEntry Peek(Stack *ps) {
    if (StackEmpty(ps)) {
        printf("Error: Stack is empty\n");
        exit(1);
    }
    return ps->top->entry;
}

/**
 * Frees the memory allocated for the stack and all its elements
 * 
 * @param ps a pointer to the stack
 * 
 */
void DestroyStack(Stack *ps) {
    if (ps == NULL) {
        exit(0);
    }
   if (ps) {
    
    
        while (ps->top != NULL) {
            StackNode* temp = ps->top;
            ps->top = ps->top->next;
            free(temp);
            StackNode* temp_min = ps->min_top;
            ps->min_top = ps->min_top->next;
            free(temp_min);
        }
        // free the memory of the stack itself
        free(ps->min_top);
        free(ps->top);
        ps->Size=0;
        


    }
} 

/**
 * Returns the first element that was added to the stack.
 * If the stack is empty, returns -1 and prints an error message.
 * 
 * @param ps Pointer to the stack
 * @return The first element that was added to the stack, or -1 if the stack is empty
 */
int FirstElementAdded(Stack* ps) {
    // Check if the stack is empty
    if (ps == NULL) {
        printf("Error: stack is empty.\n");
        return -1;
    }
    // Traverse the stack until the first element is reached
    StackNode *pl = ps->top;
    while (pl->next != NULL) {
        pl = pl->next;
    }
    // returns the value of the first element in the stack
    return pl->entry;
}

/**
 * copying the first stack to the second one .
 * coping the content , size , min_value_stack
 * 
 * @param ps Pointer to the  first stack
 * @param ps2 Pointer to the  second stack
 */
void CopyStack(Stack *ps, Stack *ps2) {
    if (ps == NULL || ps2 == NULL) {
        printf("Error: both stacks or one of them is invalid.\n");
        return;
    }
      // copying the content
       StackNode *pn = ps->top;
       StackNode *temp = NULL;
    while (pn != NULL) {
        StackNode *new_node = (StackNode*) malloc(sizeof(StackNode));
        new_node->entry = pn->entry;
        new_node->next = NULL;

        if (temp == NULL) {
            ps2->top = new_node;
        } else {
            temp->next = new_node;
        }

        temp = new_node;
        pn = pn->next;
    }
    //coping the size 
    ps2->Size = ps->Size;
    

    // Copy minimum value stack
    ps2->min_top = (StackNode*) malloc(sizeof(StackNode));
    ps2->min_top->entry = ps->min_top->entry;
    ps2->min_top->next = NULL;
    pn = ps->min_top->next;
    temp = ps2->min_top;
    while (pn != NULL) {
        StackNode *new_node = (StackNode*) malloc(sizeof(StackNode));
        new_node->entry = pn->entry;
        new_node->next = NULL;

        temp->next = new_node;
        temp = new_node;
        pn = pn->next;
    }

}


