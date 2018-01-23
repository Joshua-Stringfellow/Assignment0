//
// Created by josh on 1/21/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sll.h"


struct sll {
    void *head;
    void *tail;
    void *size;
    void *display;
    void *free;

};

struct node{
    void *value;
    void *next;
    int index;
};

SLL *newSLL(void (*d)(void *,FILE *),void (*f)(void *)) {
        SLL *items = malloc(sizeof(SLL));
        assert(items != 0);
        items->head = 0;
        items->tail = 0;
        items->size = 0;
        items->display = d;
        items->free = f;
        return items;
}
NODE *newnode(int index, void *value){
    NODE *m_node = malloc(sizeof(NODE));
    assert(m_node != 0);
    m_node->index = index;
    m_node->value = value;
    m_node->next = NULL;
    return m_node;
}
void insertSLL(SLL *items,int index,void *value){
    NODE *m_node = newnode(index, value);
    items->tail = value;
    items->size++;
}

void *removeSLL(SLL *items,int index){

}

void unionSLL(SLL *recipient,SLL *donor){

}

void *getSLL(SLL *items,int index){
    items->size;
}

void *setSLL(SLL *items,int index,void *value){

}

int sizeSLL(SLL *items){}

//void displaySLL(SLL *items,FILE *){}
//void displaySLLdebug(SLL *items,FILE *){}
void freeSLL(SLL *items){}
