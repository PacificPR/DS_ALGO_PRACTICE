//The time complexity of above algorithm is O(n).
//Linear search is rarely used practically because other search algorithms 
//such as the binary search algorithm and hash tables allow significantly faster searching compared to Linear search.

#include<stdlib.h>
#include<stdio.h>

void search(int *a,int n,int key){
    int i;
    for(i=0;i<n;i++)
        if(key==a[i]){
            printf("FOUND\n");
            exit(0);
        }
    printf("NOT FOUND\n");

}

void main(){
    int i,k,n,*a;
    printf("Enter the number of elements in array\n");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    printf("Enter the numbers in array\n");
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    printf("Enter the number to be searched\n");
    scanf("%d",&k);
    search(a,n,k);
}


