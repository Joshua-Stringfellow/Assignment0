//
// Created by josh on 1/21/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sll.h"


SLL *newSLL(void (*d)(void *,FILE *fp),void (*f)(void *items)) {
        SLL *items = malloc(sizeof(SLL));
        assert(items != 0);
        items->head = 0;
        items->tail = 0;
        items->size = 0;
        items->display = d;
        items->free = f;
        return items;
}
NODE *newnode(void *value){
    NODE *m_node = malloc(sizeof(NODE));
    assert(m_node != 0);
    m_node->value = value;
    m_node->next = 0;
    //printf("Created new node");
    return m_node;
}
void insertSLL(SLL *items,int index,void *value){
    assert(index >= 0 && index <= sizeSLL(items));
    NODE *node = newnode(value);
    //printf("Inserting At Index %d\n", index);
    if (index == 0)
    {
//		puts("Im in insertSLL index == 0");
       // printf("Debug 1 index = %d\n", index);
        if(sizeSLL(items) != 0)
        {
//			puts("Im in if sizeSLL(items) != 0");
            node->next = items->head;
            items->head = node;
        }
        else
        {
//			puts("in insert else statement");
//			printf("value =%d\n",(int *) value);
            items->head = node;
        }
    }
    else if(index == sizeSLL(items))
    {
        NODE * temp = items->tail;
        temp-> next = node;
    }
    else
    {
        int i = 0;
        NODE *current = items->head;
        for(i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
    if(index == sizeSLL(items))
    {
        items->tail = node;
    }
    items->size++;
}

void *removeSLL(SLL *items,int index){
    assert(sizeSLL(items) > 0 && index >= 0);
    NODE *curr = items->head;
    void *returnValue = 0;

    if (index == 0)
    {
        returnValue = curr->value;
//        printf("index equals head\n");
        if (sizeSLL(items) > 1)
        {
            curr = curr->next;
            items->head = curr;
        }
        else
        {
            items->head = 0;
            items-> tail = 0;
            items->size = 0;
            return returnValue;
        }

    }
    else
    {
//        printf("\nIndex equals %d\n", index);
        for (int i=0; i < index - 1; i++){
            curr = curr->next;
        }
        returnValue = getSLL(items, index);
//        printf("The return value is %d\n", (int) returnValue);
        if(index == sizeSLL(items) - 1)
        {
            items->tail = curr;
            curr->next = 0;
        }
        else
        {
            NODE *removedNode = curr->next;
            curr->next = removedNode->next;
        }

    }

    items->size--;
    return returnValue;
}

void unionSLL(SLL *recipient,SLL *donor){
    NODE *curr = recipient->tail;
    curr->next = donor->head;
    recipient->tail = donor->tail;
}

void *getSLL(SLL *items,int index){
    assert(index >= 0);
    NODE *node = items->head;
    for(int i = 0; i<index;i++)
    {
        node = node->next;
    }
    return node->value;
}

void *setSLL(SLL *items,int index,void *value){
    assert(index >= 0 && index <= sizeSLL(items));
    NODE *curr = items->head;
    if (index == sizeSLL(items)){
        insertSLL(items,index,value);
        return NULL;
    }
    else
    {
        for(int i=0; i<index; i ++){
            curr = curr->next;
        }
        curr->value = value;
    }

    return curr->value;
}

int sizeSLL(SLL *items){
    return items->size;
}

void displaySLL(SLL *items,FILE *fp){
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


void displaySLLdebug(SLL *items,FILE *fp){
    if (items->size == 0) {
        fprintf(fp, "head->{}, tail->{}");
    }
    else {
        NODE *curr = items->head;
        fprintf(fp, "head->{");
        while (curr != 0) {
            items->display(curr->value, fp);
                if (curr->next != 0)
                    fprintf(fp, ",");
            curr = curr->next;
    }
        fprintf(fp,"}, tail->{");
        curr = items->tail;
        items->display(curr->value, fp);
        fprintf(fp, "}");
    }

}
void freeSLL(SLL *items){
    NODE * curr = items->head;

    for (int i=0; i<sizeSLL(items); i++)
    {
        items->head = curr->next;
        free(curr);
        curr = items->head;
    }
}
