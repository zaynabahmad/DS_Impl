/**
 * @file queue.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "global.h"
    #define MAXQUEUE 100  
    #define QueueEntry int

typedef struct {
  int front;
  int rear;
  int size;
  QueueEntry entry[MAX_QUEUE_SIZE];
} Queue;

void CreateQueue(Queue* q);
int isQueueEmpty(Queue* q);
int isQueueFull(Queue* q);
void Append(QueueEntry e, Queue* pq);
void serve(QueueEntry* e, Queue* pq);
int ClearQueue(Queue* pq);
int QueueSize(Queue *pq);
void displayQueue(Queue* q);

#endif
