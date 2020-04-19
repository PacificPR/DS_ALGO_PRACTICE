//REFERENCE IS USED ONLY IN C++ , IT'S DENOTED BY &. IT Basically Gives a
//variable name another name. Eg int &a=b means a can represent b as well.

#include<stdio.h>
#include<stdlib.h>

void swap(int &a,int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main() {
    int a =10;
    int b=20;
    swap(a,b);
    printf("%d,%d",a,b);
    return 0;
    }
