#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "integer.h"
#include "real.h"

extern void srandom(unsigned int);
extern long int random(void);

int
main(void)
{
    srandom(1);
    SLL *p = newSLL(displayINTEGER,freeINTEGER);
    insertSLL(p,0,newINTEGER(3));
    insertSLL(p,sizeSLL(p),newINTEGER(2));
    displaySLL(p,stdout);
    printf("\n");
    freeINTEGER(removeSLL(p,1));
    displaySLL(p,stdout);
    printf("\n");
    freeINTEGER(removeSLL(p,0));
    displaySLL(p,stdout);
    printf("\n");
    SLL *q = newSLL(displayINTEGER,freeINTEGER);
    insertSLL(p,0,newINTEGER(6));
    insertSLL(p,0,newINTEGER(7));
    insertSLL(q,0,newINTEGER(4));
    insertSLL(q,0,newINTEGER(5));
    displaySLL(p,stdout);
    printf("\n");
    displaySLL(q,stdout);
    printf("\n");
    unionSLL(p,q);
    displaySLL(p,stdout);
    displaySLL(q,stdout);
    printf("\n");
    displaySLLdebug(p,stdout);
    printf("\n");
    displaySLLdebug(q,stdout);
    printf("\n");
    freeSLL(p);
    freeSLL(q);
    return 0;
}
//#include <stdio.h>
//#include <stdlib.h>
//#include "sll.h"
//#include "integer.h"
//
//extern void srandom(unsigned int);
//extern long int random(void);
//
//int
//main(void)
//{
//    srandom(4);
//    SLL *p = newSLL(displayINTEGER,freeINTEGER);
//    int i;
//    for (i = 0; i < 11; ++i)
//    {
//        int j = random() % 100;
//        insertSLL(p,0,newINTEGER(j));
//    }
//    if (sizeSLL(p) < 100)
//    {
//        displaySLL(p,stdout);
//        printf("\n");
//    }
//    printf("size is %d\n",sizeSLL(p));
//    printf("value at 9 is %d\n",getINTEGER(getSLL(p,9)));
//    printf("setting value at 9 to 74\n");
//    freeINTEGER(setSLL(p,9,newINTEGER(74)));
//    printf("value at 9 now is %d\n",getINTEGER(getSLL(p,9)));
//    displaySLL(p,stdout);
//    freeSLL(p);
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include "sll.h"
//#include "real.h"
//
//extern void srandom(unsigned int);
//extern long int random(void);
//
//int
//main(void)
//{
//    srandom(1699);
//    SLL *p = newSLL(displayREAL,freeREAL);
//    int i;
//    for (i = 0; i < 38; ++i)
//    {
//        int j = random() % 100;
//        int k = random() % (sizeSLL(p) + 1);
//        j += (random() % 100) / 100.0;
//        insertSLL(p,k,newREAL(j));
//    }
//    freeREAL(removeSLL(p,20));
//    freeREAL(removeSLL(p,8));
//    freeREAL(removeSLL(p,13));
//    insertSLL(p,32,newREAL(33.33));
//    insertSLL(p,23,newREAL(58.58));
//    insertSLL(p,30,newREAL(93.93));
//    insertSLL(p,13,newREAL(16.16));
//    insertSLL(p,14,newREAL(62.62));
//    insertSLL(p,3,newREAL(59.59));
//    freeREAL(removeSLL(p,0));
//    freeREAL(removeSLL(p,24));
//    freeREAL(removeSLL(p,37));
//    freeREAL(removeSLL(p,21));
//    freeREAL(removeSLL(p,31));
//    insertSLL(p,20,newREAL(26.26));
//    insertSLL(p,23,newREAL(12.12));
//    insertSLL(p,8,newREAL(70.70));
//    freeREAL(removeSLL(p,8));
//    insertSLL(p,33,newREAL(25.25));
//    insertSLL(p,37,newREAL(39.39));
//    freeREAL(removeSLL(p,9));
//    freeREAL(removeSLL(p,29));
//    freeREAL(removeSLL(p,23));
//    insertSLL(p,37,newREAL(23.23));
//    freeREAL(removeSLL(p,20));
//    insertSLL(p,11,newREAL(81.81));
//    insertSLL(p,29,newREAL(8.8));
//    insertSLL(p,31,newREAL(20.20));
//    insertSLL(p,7,newREAL(90.90));
//    freeREAL(removeSLL(p,20));
//    insertSLL(p,5,newREAL(85.85));
//    freeREAL(removeSLL(p,27));
//    insertSLL(p,21,newREAL(50.50));
//    freeREAL(removeSLL(p,29));
//    freeREAL(removeSLL(p,19));
//    insertSLL(p,24,newREAL(94.94));
//    insertSLL(p,29,newREAL(78.78));
//    freeREAL(removeSLL(p,37));
//    if (sizeSLL(p) < 100)
//    {
//        displaySLL(p,stdout);
//        printf("\n");
//    }
//    if (sizeSLL(p) > 0)
//    {
//        i = random() % sizeSLL(p);
//        double value = (random() % 100) / 10.0;
//        printf("size is %d\n",sizeSLL(p));
//        printf("value at %d is %lf\n",i,getREAL(getSLL(p,i)));
//        printf("setting value at %d to %lf\n",i,value);
//        freeREAL(setSLL(p,i,newREAL(value)));
//        printf("value at %d now is %lf\n",i,getREAL(getSLL(p,i)));
//    }
//    freeSLL(p);
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include "sll.h"
//
//extern void srandom(unsigned int);
//extern long int random(void);
//
//void disp(void *i,FILE *fp) { fprintf(fp,"%d",*(int *)i); }
//
//int values[] = { 1, 2, 3, 4, 5 };
//
//int
//main(void)
//{
//    srandom(9);
//    SLL *p = newSLL(disp,0);
//    unsigned int i;
//    /* inserting pointers to int, not INTEGERS */
//    for (i = 0; i < sizeof(values)/sizeof(int); ++i)
//        insertSLL(p,0,values+i);
//    displaySLL(p,stdout);
//    printf("\n");
//    freeSLL(p);
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
//int
//main(void)
//{
//    srandom(6445);
//    SLL *p = newSLL(displayINTEGER,freeINTEGER);
//    /* do some inserts */
//    int i;
//    for (i = 0; i < 1000000; ++i)
//    {
//        int j = random() % 100;
//        insertSLL(p,0,newINTEGER(j));
//    }
//    /* now a bunch of gets and sets */
//    printf("starting 1000000 get and sets\n");
//    int size = sizeSLL(p);
//    for (i = 0; i < 1000000; ++i)
//    {
//        INTEGER *x = getSLL(p,size-1);
//        setINTEGER(x,random() % 100);
//        (void) setSLL(p,size-1,x);
//    }
//    if (sizeSLL(p) < 100)
//    {
//        printf("p: ");
//        displaySLL(p,stdout);
//        printf("\n");
//        printf("p (debug): ");
//        displaySLLdebug(p,stdout);
//        printf("\n");
//        printf("\n");
//    }
//    printf("size of p is %d\n",sizeSLL(p));
//    printf("the last value is %d\n",getINTEGER(getSLL(p,size-1)));
//    freeSLL(p);
//    return 0;
//}