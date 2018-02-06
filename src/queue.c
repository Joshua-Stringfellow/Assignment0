//
// Created by jrstringfellow on 2/5/18.
//
#include <stdlib.h>
#include "queue.h"

QUEUE *newQueue(void (*d)(FILE *,void *),void (*f)(void *))   //constructor
{
    QUEUE *items = malloc(sizeof(QUEUE));
    items->list = newSLL(d,f);
    return items;
}
void enqueue(QUEUE *items,void *value)      //stores a generic value
{
    insertSLL(items->list,sizeSLL(items->list),value);
}
void *dequeue(QUEUE *items)                 //returns a generic value
{
    void * a =removeSLL(items->list,0);
    return a;
}
void *peekQueue(QUEUE *items)               //returns a generic value
{
    return items->list->tail->value;
}
int sizeQueue(QUEUE *items)
{
    return items->list->size;
}
void displayQueue(FILE *fp,QUEUE *items)
{
    displaySLL(items->list,fp);
}
