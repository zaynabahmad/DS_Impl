/**
 * @file list.c
 * @author zaynap
 * @brief 
 * @version 0.1
 * @date 2023-05-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdlib.h>
#include "list.h"

#ifdef _LIST_ARRAY_

/*****************array based *********************/


/**
 * @brief Create a List object
 * 
 * @param pl : pointer to the list 
 */
void CreateList(list *pl){
    pl->size = 0;
}

/**
 * @brief Check if the list is empty
 * 
 * @param pl 
 * @return int 1 if the list is empty, 0 otherwise
 */
int ListEmpty(list *pl){
    return !pl->size;
}

/**
 * @brief Check if the list is full
 * 
 * @param pl 
 * @return int 1 if the list is full, 0 otherwise
 */
int ListFull(list *pl){
    return pl->size == MAXLIST;
}

/**
 * @brief Return the size of the list
 * 
 * @param pl 
 * @return int the size of the list
 */
int ListSize(list *pl){
    return pl->size;
}

/**
 * @brief Destroy the list by setting its size to 0
 * 
 * @param pl 
 */
void DistroyList(list *pl){
    pl->size = 0;
}

/**
 * @brief Insert an element into the list at a specified position
 * 
 * @param p the position at which to insert the element
 * @param e the element to insert
 * @param pl 
 */
void IntsertList(int p, ListEntry e, list *pl){
    if(p < 0 || p > pl->size) return; // Invalid position

    int i;
    for(i = pl->size - 1; i >= p; i--)
        pl->list[i+1] = pl->list[i];
    pl->list[p] = e;
    pl->size++;
}

/**
 * @brief Delete an element from the list at a specified position
 * 
 * @param p the position of the element to delete
 * @param pe pointer to the variable to hold the deleted element
 * @param pl 
 */
void DeleteList(int p, ListEntry *pe, list *pl){
    if(p < 0 || p >= pl->size) return; // Invalid position

    int i;
    *pe = pl->list[p];
    for(i = p + 1; i < pl->size; i++)
        pl->list[i-1] = pl->list[i];
    pl->size--;
}

/**
 * @brief Retrieve an element from the list at a specified position
 * 
 * @param p the position of the element to retrieve
 * @param pe pointer to the variable to hold the retrieved element
 * @param pl 
 */
void RetrieveList(int p, ListEntry *pe, list *pl){
    if(p < 0 || p >= pl->size) return; // Invalid position

    *pe = pl->list[p];
}

/**
 * @brief Replace an element in the list at a specified position
 * 
 * @param p: the position of the element to replace
 * @param e the new element to replace with
 * @param pl 
 */
void ReplaceList(int p, ListEntry e, list *pl){
    if(p < 0 || p >= pl->size) return; // Invalid position

    pl->list[p] = e;
}

/**
 * @brief Traverse the list and apply a function to each element.
 * 
 * @param pl Pointer to the list.
 * @param pvisit Pointer to the function to apply to each element.
 */
void TraverseList(list *pl ,void (*Vist)(ListEntry)){
    int i;
    for(i=0;i<pl->size;i++){
        (*Vist)(pl->list[i]);
}
}

#else 

/********************************linked IMPL*****************/

#define _linked_IMPL_list

/**
 * @brief Create a List object
 * 
 * @param pl : pointer to the list 
 */
void CreateList(list *pl){
    pl->head=NULL;
    pl->size=0;
}

/**
 * @brief Check if the list is empty
 * 
 * @param pl 
 * @return int 1 if the list is empty, 0 otherwise
 */
int ListEmpty(list *pl){
    return (pl->size==0);
}

/**
 * @brief Check if the list is full
 * 
 * @param pl 
 * @return int 1 if the list is full, 0 otherwise
 */
int ListFull(list *pl){
    return 0;
}

/**
 * @brief Return the size of the list
 * 
 * @param pl 
 * @return int the size of the list
 */
int ListSize(list *pl){
    return pl->size;
}

/**
 * @brief Destroy the list by setting its size to 0
 * 
 * @param pl : pointer to the list 
 */
void DestoryList(list *pl ){
    ListNode *q;
    while(pl->head){
        q=pl->head;
        pl->head=pl->head->next;
        free(q);
        pl->head=q;

    }
    pl->size=0;
}

/**
 * @brief Traverse the list and apply a function to each element.
 * 
 * @param pl Pointer to the list.
 * @param visit Pointer to the function to apply to each element.
 */
void TraverseList(list *pl ,void (*visit)(ListEntry)){
    ListNode *p = pl->head;
    while(p){
        (*visit)(p->entry);
        p = p->next;

    }
}

/**
 * @brief Insert an element into the list at a specified position
 * 
 * @param pos the position at which to insert the element
 * @param e the element to insert
 * @param pl pointer to list
 */
void InsertList (int pos , ListEntry e , list *pl){
    ListNode *p , *q;
    int i ;
    p=(ListNode *)malloc(sizeof(ListNode));
    p->entry =e;
    p->next = NULL;

    if(pos ==0){
        p->next = pl->head;
        pl->head = p;
    }
    else {
        for (q=pl->head ,i=0 ; i<pos-1 ; i++){
            q=q->next;
            p->next =q->next;
            q->next = p;
        }
        pl->size++;
    }
}

/**
 * @brief Delete an element from the list at a specified position
 * 
 * @param pos the position of the element to delete
 * @param pe pointer to the variable to hold the deleted element
 * @param pl pointer to the list
 */
void DeleteList (int pos ,ListEntry *pe , list *pl){
    int i ;
    ListNode *q ,*tmp;
    if(pos ==0){
        *pe = pl->head->entry;
        tmp = pl->head->next;
        free(pl->head);
        pl->head = tmp;
        }
        else {
            for (q=pl->head ,i=0 ; i<pos-1 ; i++){
                q=q->next;
            }
            *pe = q->next->entry;
            tmp = q->next->next;
            free(q->next);
            q->next = tmp;
        }
        pl->size--;
}

#endif
















