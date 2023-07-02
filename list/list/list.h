/**
 * @file list.h
 * @author zaynap (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef LIST_H
#define LIST_H

#define MAXLIST 50
#define _linked_IMPL_list

typedef int ListEntry;

#ifdef _linked_IMPL_list

/*****************linked based *********************/

typedef struct listnode{
    ListEntry entry;
    struct listnode *next;
}ListNode;

typedef struct list{
    ListNode *head;
    int size;
}list;

#else

/*****************array based *********************/
 #define _LIST_ARRAY_
typedef struct list{
    int size;
    ListEntry list[MAXLIST];
}list;

void CreateList(list *pl);
int ListEmpty(list *pl);
int ListFull(list *pl);
int ListSize(list *pl);
void DistroyList(list *pl);
void IntsertList(int p, ListEntry e, list *pl);
void DeleteList(int p, ListEntry *pe, list *pl);
void RetrieveList(int p, ListEntry *pe, list *pl);
void ReplaceList(int p, ListEntry e, list *pl);
void TraverseList(list *pl ,void (*Vist)(ListEntry));

#endif
#endif
