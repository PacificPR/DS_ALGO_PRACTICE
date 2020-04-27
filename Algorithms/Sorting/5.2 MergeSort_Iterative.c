//Like QuickSort, Merge Sort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. 
//The merge() function is used for merging two halves. 
//The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one
//Merge Sort is useful for sorting linked lists in O(nLogn) time.In the case of linked lists, the case is different mainly due to the difference in memory allocation of arrays and linked lists. Unlike arrays, linked list nodes may not be adjacent in memory. Unlike an array, in the linked list, we can insert items in the middle in O(1) extra space and O(1) time.#include<stdlib.h>
//
#include<stdio.h>

void merge(int *a,int l,int mid,int h){
    int i,j,k;
    int b[100];
    i=l;
    j=mid+1;
    k=l;
    while(i<=mid && j<=h){  //Filling array in ascending order

        if(a[i]<a[j]) //If first half element is less than second halfs element in corresponding pos
            b[k++]=a[i++];
        else
            b[k++]=a[j++];

    }
    while(i<=mid) //If first part of the array a hasn't reached its end
        b[k++]=a[i++];
    
    while(j<=h) //If the second part has not reached its end
        b[k++]=a[j++];
    
    for(i=l;i<=h;i++) //Copying sorted arrya b into a
        a[i]=b[i];
}

void MergeSort(int *a,int n){ 
    int p,l,h,mid,i;

    for(p=2;p<=n;p=p*2){  // p decides the no of passes or the numbers in which the array is split to merge seperately
        for(i=0;i+p-1<=n;i=i+p){ //After sorting one set, moving to another , as each set has p elements, jumping to second set add p
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(a,l,mid,h);
        }
    }
    if(p/2<n)       //If the total number of elements are odd or not in power of 2 
        merge(a,0,p/2,n);
    
}

void main(){
    int i,n,*a;
    printf("Enter the number of elements in array\n");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    printf("Enter the numbers to be Sorted\n");
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    MergeSort(a,n);
    printf("SORTED ARRAY =  ");
    for(i=0;i<n;i++)
    printf("%d ",*(a+i));
}

