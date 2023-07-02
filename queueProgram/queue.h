/**
 * @file queue.h
 * @author zaynap (you@domain.com)
 * @brief 
 * @version 0.2
 * @date 2023-07-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>


#ifdef USE_ARRAY_IMPLEMENTATION
    #define MAXQUEUE 100  
    #define QueueEntry char

    typedef struct queue {
        int front;
        int rear;
        int size;
        QueueEntry entry[MAXQUEUE];
    } Queue;

    void CreateQueue(Queue *pq);
    void Append(QueueEntry e, Queue *pq);
    void Serve(QueueEntry *pe, Queue *pq);
    int QueueEmpty(Queue *pq);
    int QueueFull(Queue *pq);
    int QueueSize(Queue *pq);
    int ClearQueue(Queue *pq);
    void TraverseQueue(Queue *pq, void (*pf)(QueueEntry));

#elif defined USE_LINKEDLIST_IMPLEMENTATION
    #define QueueEntry int

    typedef struct queueNode {
        QueueEntry entry;
        struct queueNode *next;
    } QueueNode;

    typedef struct queue {
        QueueNode *front;
        QueueNode *rear;
        int size;
    } Queue;

    void CreateQueue(Queue *pq);
    int Append(QueueEntry e, Queue *pq);
    void Serve(QueueEntry *pe, Queue *pq);
    int QueueEmpty(Queue *pq);
    int QueueFull(Queue *pq);
    int QueueSize(Queue *pq);
    int ClearQueue(Queue *pq);
    void TraverseQueue(Queue *pq, void (*pf)(QueueEntry));


#elif defined QUEUE_USE_STACK_IMP
    
    #include "stack.h"
    #define QueueEntry int
    
    typedef struct queue {
    Stack* stack1;
    Stack* stack2;
    } Queue;

    void CreateQueue(Queue *pq);
    void Append(QueueEntry e, Queue *pq);
    void Serve(QueueEntry *pe, Queue *pq);
    int QueueEmpty(Queue *pq);
    int QueueFull(Queue *pq);
    int QueueSize(Queue *pq);
    int ClearQueue(Queue *pq);
    void TraverseQueue(Queue *pq, void (*pf)(QueueEntry));


#endif
#endif

