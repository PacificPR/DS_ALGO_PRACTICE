#include<stdio.h>
#include<stdlib.h>

typedef struct rect {   //after using typedef we can create structure variable by srect r only instead of struc rect r
    int length;
    int breadth;
}srect;

void main() {
    srect r;
    r.length=5;
    r.breadth=9;
    srect *p;   //Creating a structure pointer . We cann allocate it dynamically by p=(srect*)malloc(sizeof(srect));
    p=&r;
    int ar=(p->length)*(p->breadth);    //we can use (*p).length instead of p->length
    printf("Area = %d\n",ar);
}

