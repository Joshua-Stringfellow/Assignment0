#include <stdio.h>
#include <stdlib.h>
#include "dll.h"
#include "integer.h"

extern void srandom(unsigned int);
extern long int random(void);

int
main(void)
{
    srandom(1);
    DLL *p = newDLL(displayINTEGER,freeINTEGER);
    insertDLL(p,0,newINTEGER(3));
    insertDLL(p,sizeDLL(p),newINTEGER(2));
    displayDLL(p,stdout);
    printf("\n");
    freeINTEGER(removeDLL(p,1));
    displayDLL(p,stdout);
    printf("\n");
    freeINTEGER(removeDLL(p,0));
    displayDLL(p,stdout);
    printf("\n");
    DLL *q = newDLL(displayINTEGER,freeINTEGER);
    insertDLL(p,0,newINTEGER(6));
    insertDLL(p,0,newINTEGER(7));
    insertDLL(q,0,newINTEGER(4));
    insertDLL(q,0,newINTEGER(5));
    displayDLL(p,stdout);
    printf("\n");
    displayDLL(q,stdout);
    printf("\n");
    unionDLL(p,q);
    displayDLL(p,stdout);
    displayDLL(q,stdout);
    printf("\n");
    displayDLLdebug(p,stdout);
    printf("\n");
    displayDLLdebug(q,stdout);
    printf("\n");
    freeDLL(p);
    freeDLL(q);
    return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include "dll.h"
//#include "integer.h"
//
//extern void srandom(unsigned int);
//extern long int random(void);
//
//int
//main(void)
//{
//    srandom(5911);
//    DLL *p = newDLL(displayINTEGER,freeINTEGER);
//    int i;
//    for (i = 0; i < 14; ++i)
//    {
//        int j = random() % 100;
//        insertDLL(p,0,newINTEGER(j));
//    }
//    if (sizeDLL(p) < 100)
//    {
//        displayDLL(p,stdout);
//        printf("\n");
//    }
//    if (sizeDLL(p) > 0)
//    {
//        i = random() % sizeDLL(p);
//        int value = random() % 100;
//        printf("size is %d\n",sizeDLL(p));
//        printf("value at %d is %d\n",i,getINTEGER(getDLL(p,i)));
//        printf("setting value at %d to %d\n",i,value);
//        freeINTEGER(setDLL(p,i,newINTEGER(value)));
//        printf("value at %d now is %d\n",i,getINTEGER(getDLL(p,i)));
//    }
//    freeDLL(p);
//    return 0;
//}
//
//#include <stdio.h>
//#include <stdlib.h>
//#include "dll.h"
//#include "integer.h"
//
//extern void srandom(unsigned int);
//extern long int random(void);
//
//int
//main(void)
//{
//    srandom(7684);
//    DLL *p = newDLL(displayINTEGER,freeINTEGER);
//    int i;
//    for (i = 0; i < 15; ++i)
//    {
//        int j = random() % 100;
//        insertDLL(p,0,newINTEGER(j));
//    }
//    if (sizeDLL(p) < 100)
//    {
//        displayDLL(p,stdout);
//        printf("\n");
//    }
//    if (sizeDLL(p) > 0)
//    {
//        i = random() % sizeDLL(p);
//        int value = random() % 100;
//        printf("size is %d\n",sizeDLL(p));
//        printf("value at %d is %d\n",i,getINTEGER(getDLL(p,i)));
//        printf("setting value at %d to %d\n",i,value);
//        freeINTEGER(setDLL(p,i,newINTEGER(value)));
//        printf("value at %d now is %d\n",i,getINTEGER(getDLL(p,i)));
//    }
//    freeDLL(p);
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include "dll.h"
//#include "real.h"
//
//extern void srandom(unsigned int);
//extern long int random(void);
//
//int
//main(void)
//{
//    srandom(1699);
//    DLL *p = newDLL(displayREAL,freeREAL);
//    int i;
//    for (i = 0; i < 18; ++i)
//    {
//        int j = random() % 100;
//        int k = random() % (sizeDLL(p) + 1);
//        j += (random() % 100) / 100.0;
//        printf("Inserting %d at index %d \n",j,k);
//        insertDLL(p,k,newREAL(j));
//        displayDLL(p,stdout);
//        printf("\n \n");
//    }
//    if (sizeDLL(p) < 100)
//    {
//        displayDLL(p,stdout);
//        printf("\n");
//    }
//    if (sizeDLL(p) > 0)
//    {
//        i = random() % sizeDLL(p);
//        double value = (random() % 100) / 10.0;
//        printf("size is %d\n",sizeDLL(p));
//        printf("value at %d is %lf\n",i,getREAL(getDLL(p,i)));
//        printf("setting value at %d to %lf\n",i,value);
//        freeREAL(setDLL(p,i,newREAL(value)));
//        printf("value at %d now is %lf\n",i,getREAL(getDLL(p,i)));
//    }
//    freeDLL(p);
//    return 0;
//}

//1-6
//#include <stdio.h>
//#include <stdlib.h>
//#include "dll.h"
//#include "real.h"
//
//extern void srandom(unsigned int);
//extern long int random(void);
//
//int
//main(void)
//{
//    srandom(5696);
//    DLL *p = newDLL(displayREAL,freeREAL);
//    /* do some inserts */
//    int i;
//    for (i = 0; i < 36; ++i)
//    {
//        int j = random() % 100;
//        int k = random() % (sizeDLL(p) + 1);
//        j += (random() % 100) / 100.0;
//        printf("Inserting %d at Index %d \n",j, k);
//        insertDLL(p,k,newREAL(j));
//        displayDLL(p,stdout);
//        printf("\n \n") ;
//    }
//    /* now random inserts and removes */
//    for (i = 0; i < 36; ++i)
//    {
//        if (random() % 2 == 0)
//        {
//            int x = random() % (sizeDLL(p) + 1);
//            double j = random() % 1000 / 10.0;
//            printf("Inserting %f at Index %d \n",j, x);
//            insertDLL(p,x,newREAL(j));
//            displayDLL(p,stdout);
//            printf("\n \n");
//        }
//        else if (sizeDLL(p) > 0)
//        {
//            int x = random() % sizeDLL(p);
//            printf("Removing Index %d \n", x);
//            freeREAL(removeDLL(p,x));
//            displayDLL(p,stdout);
//            printf("\n \n");
//        }
//    }
//    if (sizeDLL(p) < 100)
//    {
//        displayDLL(p,stdout);
//        printf("\n");
//    }
//    if (sizeDLL(p) > 0)
//    {
//        i = random() % sizeDLL(p);
//        double value = (random() % 100) / 10.0;
//        printf("size is %d\n",sizeDLL(p));
//        printf("value at %d is %lf\n",i,getREAL(getDLL(p,i)));
//        printf("setting value at %d to %lf\n",i,value);
//        freeREAL(setDLL(p,i,newREAL(value)));
//        printf("value at %d now is %lf\n",i,getREAL(getDLL(p,i)));
//    }
//    freeDLL(p);
//    return 0;
//}

//1-7
//#include <stdio.h>
//#include <stdlib.h>
//#include "dll.h"
//#include "integer.h"
//
//extern void srandom(unsigned int);
//extern long int random(void);
//
//int
//main(void)
//{
//    srandom(3879);
//    DLL *p = newDLL(displayINTEGER,freeINTEGER);
//    DLL *q = newDLL(displayINTEGER,freeINTEGER);
//    unionDLL(p,q);
//    /* do some inserts */
//    int i;
//    for (i = 0; i < 25; ++i)
//    {
//        int x = random() % (sizeDLL(p) + 1);
//        int j = random() % 100;
//        insertDLL(p,x,newINTEGER(j));
//    }
//    /* do some inserts */
//    for (i = 0; i < 25; ++i)
//    {
//        int x = random() % (sizeDLL(q) + 1);
//        int j = random() % 100;
//        insertDLL(q,x,newINTEGER(j));
//    }
//    /* now a bunch of unions */
//    printf("starting 1000000 unions\n");
//    for (i = 0; i < 1000000; ++i)
//    {
//        unionDLL(q,p);
//        unionDLL(p,q);
//    }
//    /* do some more inserts */
//    for (i = 0; i < 25; ++i)
//    {
//        int x = random() % (sizeDLL(q) + 1);
//        int j = random() % 100;
//        insertDLL(q,x,newINTEGER(j));
//    }
//    if (sizeDLL(p) < 100)
//    {
//        printf("p: ");
//        displayDLL(p,stdout);
//        printf("\n");
//        printf("p (debug): ");
//        displayDLLdebug(p,stdout);
//        printf("\n");
//        printf("\n");
//    }
//    if (sizeDLL(q) < 100)
//    {
//        printf("q: ");
//        displayDLL(q,stdout);
//        printf("\n");
//        printf("q (debug): ");
//        displayDLLdebug(q,stdout);
//        printf("\n");
//        printf("\n");
//    }
//    if (sizeDLL(p) > 0)
//    {
//        i = random() % sizeDLL(p);
//        int value = random() % 100;
//        printf("size is %d\n",sizeDLL(p));
//        printf("value at %d is %d\n",i,getINTEGER(getDLL(p,i)));
//        printf("setting value at %d to %d\n",i,value);
//        freeINTEGER(setDLL(p,i,newINTEGER(value)));
//        printf("value at %d now is %d\n",i,getINTEGER(getDLL(p,i)));
//    }
//    if (sizeDLL(q) > 0)
//    {
//        i = random() % sizeDLL(q);
//        int value = random() % 100;
//        printf("size is %d\n",sizeDLL(q));
//        printf("value at %d is %d\n",i,getINTEGER(getDLL(q,i)));
//        printf("setting value at %d to %d\n",i,value);
//        freeINTEGER(setDLL(q,i,newINTEGER(value)));
//        printf("value at %d now is %d\n",i,getINTEGER(getDLL(q,i)));
//    }
//    freeDLL(p);
//    freeDLL(q);
//    return 0;
//}

//1-8
//#include <stdio.h>
//#include <stdlib.h>
//#include "dll.h"
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
//    srandom(1009);
//    DLL *p = newDLL(disp,0);
//    unsigned int i;
//    /* inserting pointers to int, not INTEGERS */
//    for (i = 0; i < sizeof(values)/sizeof(int); ++i)
//        insertDLL(p,0,values+i);
//    displayDLL(p,stdout);
//    printf("\n");
//    freeDLL(p);
//    return 0;
//}

//1-9
//#include <stdio.h>
//#include <stdlib.h>
//#include "dll.h"
//#include "integer.h"
//
//extern void srandom(unsigned int);
//extern long int random(void);
//
//int
//main(void)
//{
//    srandom(9551);
//    DLL *p = newDLL(displayINTEGER,freeINTEGER);
//    int i;
//    for (i = 0; i < 1000000; ++i)
//    {
//        int j = random() % 100;
//        insertDLL(p,0,newINTEGER(j));
//    }
//    if (sizeDLL(p) < 100)
//    {
//        displayDLL(p,stdout);
//        printf("\n");
//    }
//    if (sizeDLL(p) > 0)
//    {
//        i = random() % sizeDLL(p);
//        int value = random() % 100;
//        printf("size is %d\n",sizeDLL(p));
//        printf("value at %d is %d\n",i,getINTEGER(getDLL(p,i)));
//        printf("setting value at %d to %d\n",i,value);
//        freeINTEGER(setDLL(p,i,newINTEGER(value)));
//        printf("value at %d now is %d\n",i,getINTEGER(getDLL(p,i)));
//    }
//    freeDLL(p);
//    return 0;
//}

//1-10
//#include <stdio.h>
//#include <stdlib.h>
//#include "dll.h"
//#include "integer.h"
//
//extern void srandom(unsigned int);
//extern long int random(void);
//
//int
//main(void)
//{
//    srandom(2838);
//    DLL *p = newDLL(displayINTEGER,freeINTEGER);
//    int i;
//    for (i = 0; i < 1000000; ++i)
//    {
//        int j = random() % 100;
//        insertDLL(p,0,newINTEGER(j));
//    }
//    if (sizeDLL(p) < 100)
//    {
//        displayDLL(p,stdout);
//        printf("\n");
//    }
//    if (sizeDLL(p) > 0)
//    {
//        i = random() % sizeDLL(p);
//        int value = random() % 100;
//        printf("size is %d\n",sizeDLL(p));
//        printf("value at %d is %d\n",i,getINTEGER(getDLL(p,i)));
//        printf("setting value at %d to %d\n",i,value);
//        freeINTEGER(setDLL(p,i,newINTEGER(value)));
//        printf("value at %d now is %d\n",i,getINTEGER(getDLL(p,i)));
//    }
//    freeDLL(p);
//    return 0;
//}

//1-11
//#include <stdio.h>
//#include <stdlib.h>
//#include "dll.h"
//#include "real.h"
//
//extern void srandom(unsigned int);
//extern long int random(void);
//
//int
//main(void)
//{
//    srandom(3793);
//    DLL *p = newDLL(displayREAL,freeREAL);
//    int i;
//    for (i = 0; i < 10000; ++i)
//    {
//        int j = random() % 100;
//        int k = random() % (sizeDLL(p) + 1);
//        j += (random() % 100) / 100.0;
//        insertDLL(p,k,newREAL(j));
//    }
//    if (sizeDLL(p) < 100)
//    {
//        displayDLL(p,stdout);
//        printf("\n");
//    }
//    if (sizeDLL(p) > 0)
//    {
//        i = random() % sizeDLL(p);
//        double value = (random() % 100) / 10.0;
//        printf("size is %d\n",sizeDLL(p));
//        printf("value at %d is %lf\n",i,getREAL(getDLL(p,i)));
//        printf("setting value at %d to %lf\n",i,value);
//        freeREAL(setDLL(p,i,newREAL(value)));
//        printf("value at %d now is %lf\n",i,getREAL(getDLL(p,i)));
//    }
//    freeDLL(p);
//    return 0;
//}

//1-12
//
//#include <stdio.h>
//#include <stdlib.h>
//#include "dll.h"
//#include "real.h"
//
//extern void srandom(unsigned int);
//extern long int random(void);
//
//int
//main(void)
//{
//    srandom(8596);
//    DLL *p = newDLL(displayREAL,freeREAL);
//    /* do some inserts */
//    int i;
//    for (i = 0; i < 10000; ++i)
//    {
//        int j = random() % 100;
//        int k = random() % (sizeDLL(p) + 1);
//        j += (random() % 100) / 100.0;
//        insertDLL(p,k,newREAL(j));
//    }
//    /* now random inserts and removes */
//    for (i = 0; i < 10000; ++i)
//    {
//        if (random() % 2 == 0)
//        {
//            int x = random() % (sizeDLL(p) + 1);
//            double j = random() % 1000 / 10.0;
//            insertDLL(p,x,newREAL(j));
//        }
//        else if (sizeDLL(p) > 0)
//        {
//            int x = random() % sizeDLL(p);
//            freeREAL(removeDLL(p,x));
//        }
//    }
//    if (sizeDLL(p) < 100)
//    {
//        displayDLL(p,stdout);
//        printf("\n");
//    }
//    if (sizeDLL(p) > 0)
//    {
//        i = random() % sizeDLL(p);
//        double value = (random() % 100) / 10.0;
//        printf("size is %d\n",sizeDLL(p));
//        printf("value at %d is %lf\n",i,getREAL(getDLL(p,i)));
//        printf("setting value at %d to %lf\n",i,value);
//        freeREAL(setDLL(p,i,newREAL(value)));
//        printf("value at %d now is %lf\n",i,getREAL(getDLL(p,i)));
//    }
//    freeDLL(p);
//    return 0;
//}

//1-13
//#include <stdio.h>
//#include <stdlib.h>
//#include "dll.h"
//#include "integer.h"
//
//extern void srandom(unsigned int);
//extern long int random(void);
//
//int
//main(void)
//{
//    srandom(6445);
//    DLL *p = newDLL(displayINTEGER,freeINTEGER);
//    DLL *q = newDLL(displayINTEGER,freeINTEGER);
//    unionDLL(p,q);
//    /* do some inserts */
//    int i;
//    for (i = 0; i < 10000; ++i)
//    {
//        int x = random() % (sizeDLL(p) + 1);
//        int j = random() % 100;
//        insertDLL(p,x,newINTEGER(j));
//    }
//    /* do some inserts */
//    for (i = 0; i < 10000; ++i)
//    {
//        int x = random() % (sizeDLL(q) + 1);
//        int j = random() % 100;
//        insertDLL(q,x,newINTEGER(j));
//    }
//    /* now a bunch of unions */
//    printf("starting 1000000 unions\n");
//    for (i = 0; i < 1000000; ++i)
//    {
//        unionDLL(q,p);
//        unionDLL(p,q);
//    }
//    /* do some more inserts */
//    for (i = 0; i < 10000; ++i)
//    {
//        int x = random() % (sizeDLL(q) + 1);
//        int j = random() % 100;
//        insertDLL(q,x,newINTEGER(j));
//    }
//    if (sizeDLL(p) < 100)
//    {
//        printf("p: ");
//        displayDLL(p,stdout);
//        printf("\n");
//        printf("p (debug): ");
//        displayDLLdebug(p,stdout);
//        printf("\n");
//        printf("\n");
//    }
//    if (sizeDLL(q) < 100)
//    {
//        printf("q: ");
//        displayDLL(q,stdout);
//        printf("\n");
//        printf("q (debug): ");
//        displayDLLdebug(q,stdout);
//        printf("\n");
//        printf("\n");
//    }
//    if (sizeDLL(p) > 0)
//    {
//        i = random() % sizeDLL(p);
//        int value = random() % 100;
//        printf("size is %d\n",sizeDLL(p));
//        printf("value at %d is %d\n",i,getINTEGER(getDLL(p,i)));
//        printf("setting value at %d to %d\n",i,value);
//        freeINTEGER(setDLL(p,i,newINTEGER(value)));
//        printf("value at %d now is %d\n",i,getINTEGER(getDLL(p,i)));
//    }
//    if (sizeDLL(q) > 0)
//    {
//        i = random() % sizeDLL(q);
//        int value = random() % 100;
//        printf("size is %d\n",sizeDLL(q));
//        printf("value at %d is %d\n",i,getINTEGER(getDLL(q,i)));
//        printf("setting value at %d to %d\n",i,value);
//        freeINTEGER(setDLL(q,i,newINTEGER(value)));
//        printf("value at %d now is %d\n",i,getINTEGER(getDLL(q,i)));
//    }
//    freeDLL(p);
//    freeDLL(q);
//    return 0;
//}

//1-14
//#include <stdio.h>
//#include <stdlib.h>
//#include "dll.h"
//#include "integer.h"
//
//extern void srandom(unsigned int);
//extern long int random(void);
//
//int
//main(void)
//{
//    srandom(9504);
//    DLL *p = newDLL(displayINTEGER,freeINTEGER);
//    int i;
//    for (i = 0; i < 1000000; ++i)
//    {
//        int j = random() % 100;
//        int k = random() % 5 + 1;
//        if (i < k) k = i;
//        insertDLL(p,i - k,newINTEGER(j));
//    }
//    printf("done inserting\n");
//    for (i = 0; i < 999980; ++i)
//    {
//        int j = sizeDLL(p);
//        int k = random() % 5 + 1;
//        if (j < k) k = j;
//        INTEGER *x = getDLL(p,j - k);
//        int value = getINTEGER(x);
//        freeINTEGER(setDLL(p,j - k,newINTEGER(value+1)));
//    }
//    printf("done getting and setting\n");
//    for (i = 0; i < 999980; ++i)
//    {
//        int j = sizeDLL(p);
//        int k = random() % 5 + 1;
//        if (j < k) k = j;
//        //printf("removing index %d \n", j-k);
//        freeINTEGER(removeDLL(p,j - k));
//    }
//    printf("done removing\n");
//    if (sizeDLL(p) < 100)
//    {
//        displayDLL(p,stdout);
//        printf("\n");
//    }
//    if (sizeDLL(p) > 0)
//    {
//        i = random() % sizeDLL(p);
//        int value = random() % 100;
//        printf("size is %d\n",sizeDLL(p));
//        printf("value at %d is %d\n",i,getINTEGER(getDLL(p,i)));
//        printf("setting value at %d to %d\n",i,value);
//        freeINTEGER(setDLL(p,i,newINTEGER(value)));
//        printf("value at %d now is %d\n",i,getINTEGER(getDLL(p,i)));
//    }
//    freeDLL(p);
//    return 0;
//}