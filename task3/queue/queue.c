/**
 * @file queue.c
 * @author zaynap(you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

 #include<stdio.h>
#include<stdlib.h>
#include "queue.h"

#ifdef USE_ARRAY_IMPLEMENTATION




/************************array based ****************************************/

/**
 * Initializes the queue by setting its front and rear indices and size to default values.
 *
 * @param pq pointer to the queue
 */
void CreateQueue (Queue *pq){
     // Set the front index to 0
    pq->front = 0;
    // Set the rear index to -1
    pq->rear = -1;
    // Set the size to 0
    pq->size = 0;
}

/**
 * Adds an element to the end of the queue.
 *
 * @param e the element to be added
 * @param pq pointer to the queue
 */
void Append(QueueEntry e, Queue *pq) {
    // Increment the rear index and use modular arithmetic to ensure it stays within bounds
    pq->rear = (pq->rear + 1) % MAXQUEUE;
    // Set the entry at the rear index to the element being added
    pq->entry[pq->rear] = e;
    // Increment the size of the queue
    pq->size++;
}

/**
 * Removes an element from the front of the queue.
 *
 * @param pe pointer to the variable that will hold the removed element
 * @param pq pointer to the queue
 */
void Serve(QueueEntry *pe, Queue *pq) {
    // Set the removed element to the entry at the front index
    *pe = pq->entry[pq->front];
    // Increment the front index and use modular arithmetic to ensure it stays within bounds
    pq->front = (pq->front + 1) % MAXQUEUE;
    // Decrement the size of the queue
    pq->size--;
}

/**
 * Checks if the queue is empty.
 *
 * @param pq pointer to the queue
 * @return 1 if the queue is empty, 0 otherwise
 */
int QueueEmpty(Queue *pq) {
    // If the size of the queue is 0, it is empty
    return !pq->size;
}

/**
 * Checks if the queue is full.
 *
 * @param pq pointer to the queue
 * @return 1 if the queue is full, 0 otherwise
 */
int QueueFull(Queue *pq) {
    // If the size of the queue is equal to the maximum queue size, it is full
    return (pq->size == MAXQUEUE);
}

/**
 * Gets the size of the queue.
 *
 * @param pq pointer to the queue
 * @return the size of the queue
 */
int QueueSize(Queue *pq) {
    // Return the size of the queue
    return pq->size;
}

/**
 * Clears the queue by resetting its front and rear indices and size to default values.
 *
 * @param pq pointer to the queue
 * @return 1 if the operation was successful, 0 otherwise
 */
int ClearQueue(Queue *pq) {
    // Set the front index to 0
    pq->front = 0;
    // Set the rear index to -1
    pq->rear = -1;
    // Set the size to 0
    pq->size = 0;
    // Return 1 to indicate success
    return 1;
}

/**
 * Applies a function to each element of the queue.
 *
 * @param pq pointer to the queue
 * @param pf pointer to the function to apply to each element
 */
void TraverseQueue(Queue *pq, void (*pf)(QueueEntry)) {
    int pos, s;
    // Iterate through each element of the queue
          for(pos=pq->front, s=0 ;s<pq->size; s++){
            (*pf) (pq->entry[pos]);
            pos=(pos+1) % MAXQUEUE;
          }  
}


/***********************************linked based ***********************/
#else 

#define USE_LINKEDLIST_IMPLEMENTATION


/**
 * Initializes the queue by setting its front and rear pointers and size to default values.
 *
 * @param pq pointer to the queue
 */
void CreateQueue(Queue *pq){
    pq->front=NULL;
    pq->rear=NULL;
    pq->size=0;

}

/**
 * Appends an element to the rear of the queue.
 *
 * @param e the element to be appended
 * @param pq pointer to the queue
 * @return 1 if the element is successfully appended, 0 otherwise
 */
int Append(QueueEntry e , Queue * pq){
    QueueNode *pn = (QueueNode *)malloc(sizeof( QueueNode));
    if (!pn)
        return 0;
    else {
    pn->next=NULL;
    pn->entry=e;
    if(!pq->rear)
      pq->front=pn;
      else
      {
        pq->rear->next =pn;
      }
      pq->rear=pn;
      pq->size++;
      return 1;
    }

}

/**
 * Removes the front element from the queue and assigns it to the given variable.
 *
 * @param pe pointer to the variable that will hold the removed element
 * @param pq pointer to the queue
 */
void serve (QueueEntry *pe, Queue * pq){
    QueueNode * pn = pq->front;
    *pe =pn->entry ;
    pq->front=pn->next;
    free(pn);
    if(!pq->front)
    pq->rear=NULL;
    pq->size--;


}

/**
 * Determines if the queue is empty.
 *
 * @param pq pointer to the queue
 * @return 1 if the queue is empty, 0 otherwise
 */
int QueueEmpty(Queue* pq){
    return !pq->front;
}

/**
 * Determines the size of the queue.
 *
 * @param pq pointer to the queue
 * @return the size of the queue
 */
int QueueSize(Queue* pq){
    return pq->size;
}

/**
 * Determines if the queue is full. For linked list implementation, the queue can never be full.
 *
 * @param pq pointer to the queue
 * @return always returns 0
 */
int QueueFull (Queue *pq){
    return 0;
}

/**
 * Removes all elements from the queue.
 *
 * @param pq pointer to the queue
 * @return 1 if the queue is successfully cleared, 0 otherwise
 */
int ClearQueue (Queue *pq){    //again
    while (pq->front){
        pq->rear =pq->front->next;
        free(pq->front);
        pq->front=pq->rear;
    }
    pq->size =0;
    // Return 1 to indicate success
    return 1;
}

/**
 * Traverses the queue, applying the given function to each element.
 *
 * @param pq pointer to the queue
 * @param pf pointer to the function that will be applied to each element
 */
void TraverseQueue(Queue *pq ,void (*pf)(QueueEntry)){
    for (QueueNode * pn =pq->front ; pn ; pn=pn->next){
        (*pf)(pn->entry);
    }
}

#endif
