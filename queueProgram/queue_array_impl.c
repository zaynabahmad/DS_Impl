/**
 * @file queue_array.c
 * @author zaynap (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<stdio.h>
#include<stdlib.h>

#define USE_ARRAY_IMPLEMENTATION

#include "queue.h"

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
