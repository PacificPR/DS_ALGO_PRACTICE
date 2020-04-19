//Time Complexity: O(n*2)

//Auxiliary Space: O(1)

//Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order. 
//                And it takes minimum time (Order of n) when elements are already sorted.

//Algorithmic Paradigm: Incremental Approach

//Sorting In Place: Yes

//Stable: Yes

//Online: Yes

//Uses: Insertion sort is used when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.

#include<stdlib.h>
#include<stdio.h>


void Insertionsort(int *a,int n){ 
    int i,key,j;
    
    for(i=1;i<n;i++){
        key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void main(){
    int i,k,n,*a;
    printf("Enter the number of elements in array\n");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    printf("Enter the numbers to be Sorted\n");
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    Insertionsort(a,n);
    printf("SORTED ARRAY =  ");
    for(i=0;i<n;i++)
        printf("%d ",*(a+i));
}

