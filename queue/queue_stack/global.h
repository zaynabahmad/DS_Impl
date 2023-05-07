/**
 * @file global.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef GLOBAL_H
#define GLOBAL_H

#define MAX_STACK_SIZE 100
#define MAX_QUEUE_SIZE 100

typedef struct {
  char name[50];
  int id;
  int model_year;
} ElementType;

typedef ElementType StackEntry;
typedef ElementType QueueEntry;

#endif
