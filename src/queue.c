//
// Created by jrstringfellow on 2/5/18.
//
#include <stdlib.h>
#include "queue.h"
#include "sll.h"

QUEUE *newQUEUE(void (*d)(void *,FILE *),void (*f)(void *))   //constructor
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
void *peekQUEUE(QUEUE *items)               //returns a generic value
{
    return getSLL(items->list,0);
}
int sizeQUEUE(QUEUE *items)
{
    return sizeSLL(items->list);
}
void displayQUEUE(QUEUE *items,FILE *fp)
{
    displaySLL(items->list,fp);
//    if(items->list->head == 0)
//    {
//        fprintf(fp,"<>");
//        return;
//    }
//    NODE *curr = items->list->head;
//    fprintf(fp,"<");
//    for(int i = 0; i < sizeSLL(items->list); i++)
//    {
//        if(i == items->list->size - 1 )
//        {
//            items->list->display( curr->value, fp);
//        }
//        else
//        {
//            items->list->display(curr->value, fp);
//            fprintf(fp,",");
//        }
//        curr = curr->next;
//    }
//    fprintf(fp,">");
}

void displayQUEUEdebug(QUEUE *items, FILE *fp){displaySLLdebug(items->list,fp);}

void freeQUEUE(QUEUE *items){
    freeSLL(items->list);
    free(items);
}
