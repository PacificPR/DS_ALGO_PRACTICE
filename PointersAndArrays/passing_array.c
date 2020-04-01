//Arrays are only passed by address(Using pointers)

#include<stdio.h>

void array(int a[],int n){      //Or we can use int *a as a[] is also denoting a pointer for array
    for(int i=0;i<n;i++)
        printf("%d   ",i[a]);   // Or we can write *(a+i)  as a is the address of first num in  array 
}

//#### FOR ARRAY A , A[1] can we written as 1[A] as well #####

void main(){
    int ar[] = {4,2,55,23,11};
    //printf("%d",ar);  //ar contains the address of first number in array
    array(ar,5);
}

