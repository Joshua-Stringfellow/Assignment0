//
// Created by jrstringfellow on 2/5/18.
//
#include <stdio.h>
#include <stdlib.h>
#include "dll.h"
#include "integer.h"

static void showItems(DLL *items)
{
    printf("The items are ");
    displayDLL(items,stdout);
    printf(".\n");
    printf("The items (debugged) are ");
    displayDLLdebug(items,stdout);
    printf(".\n");
}

int test()
{
    DLL *items = newDLL(displayINTEGER,freeINTEGER);
    showItems(items);
    insertDLL(items,0,newINTEGER(3));                   //insert at front
    insertDLL(items,sizeDLL(items),newINTEGER(2));      //insert at back
    insertDLL(items,1,newINTEGER(1));                   //insert at middle
    showItems(items);

    printf("Update index 1\n");
    setDLL(items,1,newINTEGER(4));
    showItems(items);

    printf("Update non index\n");
    setDLL(items,3,newINTEGER(5));

    printf("The value ");
    INTEGER *i = removeDLL(items,2);                   //remove from front
    displayINTEGER(i,stdout);
    printf(" was removed.\n");
    freeINTEGER(i);
    showItems(items);
    int x = getINTEGER((INTEGER *) getDLL(items,0));    //get the first item
    printf("The first item is %d.\n",x);
    printf("Freeing the list.\n\n");
    freeDLL(items);

    printf("Building union DLLs\n");
    DLL *newitems = newDLL(displayINTEGER,freeINTEGER);
    showItems(newitems);
    insertDLL(newitems,0,newINTEGER(1));                   //insert at front
    insertDLL(newitems,1,newINTEGER(2));      //insert at back
    insertDLL(newitems,2,newINTEGER(3));
    DLL *donor = newDLL(displayINTEGER,freeINTEGER);
    insertDLL(donor,0,newINTEGER(4));                   //insert at front
    insertDLL(donor,1,newINTEGER(6));      //insert at back
    insertDLL(donor,2,newINTEGER(5));
    showItems(newitems);
    showItems(donor);
    unionDLL(newitems, donor);
    showItems(newitems);
    return 0;
}