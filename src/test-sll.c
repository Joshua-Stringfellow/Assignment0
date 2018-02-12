#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "integer1.h"

extern void srandom(unsigned int);
extern long int random(void);

//int
//main(void)
//{
//    srandom(1);
//    SLL *p = newSLL(displayINTEGER,freeINTEGER);
//    insertSLL(p,0,newINTEGER(3));
//    insertSLL(p,sizeSLL(p),newINTEGER(2));
//    displaySLL(p,stdout);
//    printf("\n");
//    freeINTEGER(removeSLL(p,1));
//    displaySLL(p,stdout);
//    printf("\n");
//    freeINTEGER(removeSLL(p,0));
//    displaySLL(p,stdout);
//    printf("\n");
//    SLL *q = newSLL(displayINTEGER,freeINTEGER);
//    insertSLL(p,0,newINTEGER(6));
//    insertSLL(p,0,newINTEGER(7));
//    insertSLL(q,0,newINTEGER(4));
//    insertSLL(q,0,newINTEGER(5));
//    displaySLL(p,stdout);
//    printf("\n");
//    displaySLL(q,stdout);
//    printf("\n");
//    unionSLL(p,q);
//    displaySLL(p,stdout);
//    displaySLL(q,stdout);
//    printf("\n");
//    displaySLLdebug(p,stdout);
//    printf("\n");
//    displaySLLdebug(q,stdout);
//    printf("\n");
//    freeSLL(p);
//    freeSLL(q);
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include "sll.h"
//#include "integer.h"
//
//extern void srandom(unsigned int);
//extern long int random(void);
//
int
main(void)
{
    srandom(4);
    SLL *p = newSLL(displayINTEGER,freeINTEGER);
    int i;
    for (i = 0; i < 11; ++i)
    {
        int j = random() % 100;
        insertSLL(p,0,newINTEGER(j));
    }
    if (sizeSLL(p) < 100)
    {
        displaySLL(p,stdout);
        printf("\n");
    }
    printf("size is %d\n",sizeSLL(p));
    printf("value at 9 is %d\n",getINTEGER(getSLL(p,9)));
    printf("setting value at 9 to 74\n");
    freeINTEGER(setSLL(p,9,newINTEGER(74)));
    printf("value at 9 now is %d\n",getINTEGER(getSLL(p,9)));
    displaySLL(p,stdout);
    freeSLL(p);
    return 0;
}