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
    DLL *list = items->list;
    return list->head->value;
}
int sizeSTACK(STACK *items){ return sizeDLL(items->list);}
void displaySTACK(STACK *items,FILE *fp){displayDLL(items->list,fp);}
void displaySTACKdebug(STACK *items,FILE *fp){displayDLLdebug(items->list,fp);}
void freeSTACK(STACK *items){freeDLL(items->list);}