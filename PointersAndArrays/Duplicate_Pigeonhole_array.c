//Given an array of n numbers, whose value can be from 1 to n-1
//There would always be a duplicate number , find that number

#include<stdio.h>
#include<stdlib.h>

void main(){
    int n,i;
    int t,h;
    int *a;
    int ptr1,ptr2;
    printf("Enter Size of array\n");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    printf("Enter the elements\n");
    for (i=0;i<n;i++)
        scanf("%d",a+i);
    t=a[0];
    h=a[0];
    //Now finding the intersection point of two pointers above
    do{
        t=a[t];
        h=a[a[h]];
    }
    while(t!=h);

    //Now finding the starting of the loop
    
    ptr1=a[0];
    ptr2=t;
    while(ptr1!=ptr2){
        ptr1=a[ptr1];
        ptr2=a[ptr2];
    }

    printf("\nDuplicate Number = %d \n",ptr1);
}
