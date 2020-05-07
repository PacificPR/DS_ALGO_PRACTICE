// Pointer is declared by int *p; * is dereferencing operator, suppose int a=5;
// we can use pointer as (int *p=&a) OR (int *p; p=&a;)
// p=Address of a,*p=gives value of a
// We can indirectly change value of a using pointer
// Pointers are used to access heap memory, external resource, other than stack

// For array A,  A+2  gives address of 3rd array element
//  Whereas ,  *(A+2) gives value of 3rd array element
#include<stdlib.h>
#include<stdio.h>

void main() {
    int a=10;
    int *p; //Or we can use int *p=&a ; directly
    p=&a;
    printf("Value of a=%d,\tValue of a using pointer p,*p=%d\n",a,*p);
    printf("Address of a directyly,&a=%d,\nAddress of a using pointer p,p=%d\n",&a,p);
    
    //###Printing address in HexaDecimal Format USE FORMAT SPECIFIE %p ###
    printf("Address of a in HexaDeciman =%p",p); 

    //int *arr;
    int arr[9]={11,22,33,44,55,66,77,88,99};
    printf("\n****** %d",&arr);
    printf("\n****** %d",arr);

    printf("\n\nArray:\nValue of a[0]=%d\n",arr[0]);
    printf("Address of a[0]=%d\n",arr);
    printf("Value of a[1]=%d\n",*(arr+1));
    printf("Address of a[0]=%d\n",arr+1);
    
}

