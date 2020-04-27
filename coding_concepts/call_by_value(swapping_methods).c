//TWO WAYS TO SWAP WITHOUT USING A VARIABLE
//HENCE SAVING EXTRA MEMORY 


#include<stdio.h>
#include<stdlib.h>

void swap1(int a,int b) {
    a = a^b;
    b = a^b;
    a = a^b;
    printf("a = %d\nb = %d \n",a,b);
}

void swap2(int a,int b) {
    a = a+b;
    b = a-b;
    a = a-b;
    printf("a = %d\nb = %d \n",a,b);
}

void swap3(int a,int b) {
    a = a*b;
    b = a/b;
    a = a/b;
    printf("a = %d\nb = %d \n",a,b);
}


int main() {
    int a,b;
    printf("ENTER NUMBERS TO BE SWAPPED \n");
    scanf("%d%d",&a,&b);
    swap1(a,b);
    swap2(a,b);
    swap3(a,b);
    return 0;
    }   

