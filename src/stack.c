//
// Created by jrstringfellow on 2/5/18.
//
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "dll.h"

struct stack{
     DLL *list;
}stack;

STACK *newSTACK(void (*d)(void *,FILE *),void (*f)(void *)){
    STACK *items =malloc(sizeof(STACK));
    items->list = newDLL(d,f);
    return items;
}
void push(STACK *items,void *value){
    insertDLL(items->list,0,value);
}
void *pop(STACK *items){
    void *value = removeDLL(items->list,0);
    return value;
}
void *peekSTACK(STACK *items){
    return getDLL(items->list,0);
}
int sizeSTACK(STACK *items){ return sizeDLL(items->list);}

void displaySTACK(STACK *items,FILE *fp){ if(items->list->head == 0)
    {
        fprintf(fp,"||");
        return;
    }
    NODE *curr = items->list->head;
    fprintf(fp,"|");
    for(int i = 0; i < sizeDLL(items->list); i++)
    {
        if(i == items->list->size - 1 )
        {
            items->list->display( curr->value, fp);
        }
        else
        {
            items->list->display(curr->value, fp);
            fprintf(fp,",");
        }
        curr = curr->next;
    }
    fprintf(fp,"|");}

void displaySTACKdebug(STACK *items,FILE *fp){displayDLLdebug(items->list,fp);}
void freeSTACK(STACK *items){freeDLL(items->list);
free(items);}