//The selection sort algorithm sorts an array by repeatedly finding the
//minimum element (considering ascending order) from unsorted part and putting
//it at the beginning. The algorithm maintains two subarrays in a given array.
//
//1) The subarray which is already sorted.
//2) Remaining subarray which is unsorted.
//
//In every iteration of selection sort, the minimum element (considering
//ascending order) from the unsorted subarray is picked and moved to the sorted
//subarray. 

//Time Complexity: O(n2) as there are two nested loops.

//Auxiliary Space: O(1)
//The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation. 

//**** We can use this to find the smallest or second smallest or third or so on
//smallest number in very less time.
//As the first iteration gives us the smallest number at the first position
//So the second iteration gives us the 2nd smallest no at the 2nd  postition
//So the third iteration gives us the 3rd smallest no at the 3rd   postition
// *****

#include<stdlib.h>
#include<stdio.h>

void swap(int *p,int *q){
    int tmp = *p; 
    *p = *q; 
    *q = tmp;
}

void Selectionsort(int *a,int n){ 
    int i,k,j;
    
    for(i=0;i<n;i++){

        for(j=k=i;j<n;j++){
            if(a[j]<a[k])
                k=j;
        }
        swap(&a[i],&a[k]);
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
    Selectionsort(a,n);
    printf("SORTED ARRAY =  ");
    for(i=0;i<n;i++)
        printf("%d ",*(a+i));
}

