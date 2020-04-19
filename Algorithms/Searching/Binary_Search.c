//Time Complexity:
//The time complexity of Binary Search is  log2(n) {log(n) with base 2}
//The time complexity of Binary Search can be written as
//T(n) = T(n/2) + c 
//The above recurrence can be solved either using Recurrence Tree method 
//or Master method. It falls in case II of Master Method and solution of the recurrence is Theta(Logn).

//Auxiliary Space: O(1) in case of iterative implementation. In case of recursive implementation, O(Logn) recursion call stack space.
#include<stdlib.h>
#include<stdio.h>

void Bsearch(int *a,int n,int key){
    int i,m,l,h;
    l=0;
    h=n-1;
    while(l<=h){
        m=(l+h)/2;
        if(key==a[m]){
            printf("FOUND\n");
            exit(0);
        }
        else if(key>a[m])
            l=m+1;
        else
            h=m-1;
    }
    printf("NOT FOUND\n");
}

void main(){
    int i,k,n,*a;
    printf("Enter the number of elements in array\n");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    printf("Enter the numbers in ascending order\n");
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    printf("Enter the number to be searched\n");
    scanf("%d",&k);
    Bsearch(a,n,k);
}

