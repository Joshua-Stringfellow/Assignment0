//
// Created by jrstringfellow on 2/5/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "integer.h"

static void showItems(SLL *items)
{
    printf("The items are ");
    displaySLL(items,stdout);
    printf(".\n");
    printf("The items (debugged) are ");
    displaySLLdebug(items,stdout);
    printf(".\n");
}

int testsll()
{
    SLL *items = newSLL(displayINTEGER,freeINTEGER);
    showItems(items);
    insertSLL(items,0,newINTEGER(3));                   //insert at front
    insertSLL(items,sizeSLL(items),newINTEGER(2));      //insert at back
    insertSLL(items,1,newINTEGER(1));                   //insert at middle
    showItems(items);

    printf("Update index 1\n");
    setSLL(items,1,newINTEGER(4));
    showItems(items);

    printf("Update non index\n");
    setSLL(items,3,newINTEGER(5));

    printf("The value ");
    INTEGER *i = removeSLL(items,2);                   //remove from front
    displayINTEGER(i,stdout);
    printf(" was removed.\n");
    freeINTEGER(i);
    showItems(items);
    int x = getINTEGER((INTEGER *) getSLL(items,0));    //get the first item
    printf("The first item is %d.\n",x);
    printf("Freeing the list.\n\n");
    freeSLL(items);

    printf("Building union SLLs\n");
    SLL *newitems = newSLL(displayINTEGER,freeINTEGER);
    showItems(newitems);
    insertSLL(newitems,0,newINTEGER(1));                   //insert at front
    insertSLL(newitems,1,newINTEGER(2));      //insert at back
    insertSLL(newitems,2,newINTEGER(3));
    SLL *donor = newSLL(displayINTEGER,freeINTEGER);
    insertSLL(donor,0,newINTEGER(4));                   //insert at front
    insertSLL(donor,1,newINTEGER(6));      //insert at back
    insertSLL(donor,2,newINTEGER(5));
    showItems(newitems);
    showItems(donor);
    unionSLL(newitems, donor);
    showItems(newitems);
    return 0;
}