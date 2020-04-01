//We are passing the address of the actual parameters , in call by address, the
//value of actual parameter changes if formal parameter are changed.

#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a =10;
    int b=20;
    swap(&a,&b);
    printf("%d,%d",a,b);
    return 8;
    }   
