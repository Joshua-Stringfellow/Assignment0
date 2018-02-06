//
// Created by jrstringfellow on 2/4/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dll.h"

struct dll {
    NODE *head;
    NODE *tail;
    int size;
    void (*display)(void *, FILE *);
    void *free;
};

DLL *newDLL(void (*d)(void *,FILE *),void (*f)(void *))
{
    DLL *items = malloc(sizeof(DLL));
    assert(items != 0);
    items->head = 0;
    items->tail = 0;
    items->size = 0;
    items->display = d;
    items->free = f;
    return items;
}

struct node{
    void *value;
    NODE *next;
    NODE *prev;
};

NODE *newDLLnode(void *value){
    NODE *m_node = malloc(sizeof(NODE));
    assert(m_node != 0);
    m_node->value = value;
    m_node->next = 0;
    m_node->prev = 0;
    //printf("Created new node");
    return m_node;
}
void insertDLL(DLL *items,int index,void *value){
    assert(index >= 0 && index <= sizeDLL(items));
    NODE *node = newDLLnode(value);
    //printf("Inserting At Index %d\n", index);
    if (index == 0)
    {
        printf("Inserting value %d at head\n", *(int *)value);
//		puts("Im in insertDLL index == 0");
        // printf("Debug 1 index = %d\n", index);
        if(sizeDLL(items) != 0)
        {
            NODE *temp = items->head;
            node->next = items->head;
            temp->prev= node;
        }

        items->head = node;

    }
    else if(index == sizeDLL(items))
    {
        printf("Inserting value %d at tail\n", *(int *)value);
        NODE * temp = items->tail;
        temp-> next = node;
        node->prev = items->tail;
    }
    else
    {
        NODE *curr = items->head;
        printf("Inserting value %d at mid\n", *(int *)value);
        if (index<sizeDLL(items)/2){
            for(int i=0; i<index -1; i ++){
                curr = curr->next;
            }
        }
        else{
            for(int i=sizeDLL(items); i<index +1; i --){
                curr = curr->prev;
            }
        }
        node->next = curr->next;
        node->prev = curr;
        curr->next = node;
        node->next->prev = node;

    }
    if(index == sizeDLL(items))
    {
        items->tail = node;
    }

   // displayDLLdebug(items,stdout);
    items->size++;
}

void *removeDLL(DLL *items,int index)            //returns a generic value
//ADD IF ABOUT IF IT IS GREATER THAN HALF THE INDEX, THEN START FROM THE END AND REVERSE INTO
//THE CORRECT POSITION
{
    if (items->size == 0)
    {
        fprintf(stderr,"out of memory");
        exit(-1);
    }
    NODE *curr = items->head;
    void * retValue;
    if(index == 0)
    {
        retValue = items->head->value;
        //printf("value is: %d\n\n", *(int*)ptr->value);
        if(sizeDLL(items) != 1)
        {
            items->head = curr->next;
            items->head->prev = 0;
        }
        else
        {
            items->head = 0;
            items->tail = 0;
        }
    }
    else if(index == sizeDLL(items) || index == sizeDLL(items) - 1)
    {
        //puts("\nim in index == sizeDLL(items");
        retValue = items->tail->value;

        if(sizeDLL(items) != 1)
        {
            items->tail = items->tail->prev;
            items->tail->next = 0;
        }
        else
        {
            items->head = 0;
            items->tail = 0;
        }
    }
    else
    {
        //puts("in for loop search");
        int i;
        for(i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        curr->next->prev= curr->prev;
        curr->prev->next = curr->next;

        retValue = curr->value;
    }
    items->size--;
    return retValue;
}

void unionDLL(DLL *recipient,DLL *donor){
    NODE *curr = recipient->tail;
    curr->next = donor->head;
    curr = donor->head;
    curr->prev = recipient->tail;
    recipient->tail = donor->tail;
}

void *getDLL(DLL *items,int index){
    NODE *curr = items->head;
    if (index<sizeDLL(items)/2){
        for(int i=0; i<index; i ++){
            curr = curr->next;
        }
    }
    else{
        for(int i=sizeDLL(items); i<index; i --){
            curr = curr->prev;
        }
    }
    return curr->value;
}

void *setDLL(DLL *items,int index,void *value){
    assert(index >= 0 && index <= sizeDLL(items));
    NODE *curr = items->head;
    if (index == sizeDLL(items)){
        insertDLL(items,index,value);
        return NULL;
    }
    else
    {
        if (index<sizeDLL(items)/2){
            for(int i=0; i<index; i ++){
                curr = curr->next;
            }
        }
        else{
            for(int i=sizeDLL(items); i<index; i --){
                curr = curr->prev;
            }
        }

        curr->value = value;
    }

    return curr->value;
}

int sizeDLL(DLL *items){
    return items->size;
}

void displayDLL(DLL *items,FILE *fp){
    //printf("Beginning Display\n");
    if(items->head == 0)
    {
        fprintf(fp,"[]");
        return;
    }
    NODE *curr = items->head;
    fprintf(fp,"[");
    for(int i = 0; i < items->size; i++)
    {
        if(i == items->size - 1 )
        {
            items->display( curr->value, fp);
        }
        else
        {
            items->display(curr->value, fp);
            fprintf(fp,",");
        }
        curr = curr->next;
    }
    fprintf(fp,"]");
}

void displayDLLdebug(DLL *items,FILE *fp){
    if (items->size == 0) {
        fprintf(fp, "head->{}, tail->{}");
    }
    else {
        NODE *curr = items->head;
        fprintf(fp, "head->{{");
        while (curr != 0) {
            items->display(curr->value, fp);
            if (curr->next != 0)
                fprintf(fp, ",");
            curr = curr->next;
        }
        fprintf(fp,"}}, tail->{{");
        curr = items->tail;
        while (curr != 0 ) {
            items->display(curr->value, fp);
            if (curr->prev != 0)
                fprintf(fp, ",");
            curr = curr->prev;
        }
        fprintf(fp, "}}");
    }
}
void freeDLL(DLL *items){
    NODE * curr = items->head;

    for (int i=0; i<sizeDLL(items); i++)
    {
        items->head = curr->next;
        free(curr);
        curr = items->head;
    }
}