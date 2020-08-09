//Time Complexity: Sorting arrays on different machines. Merge Sort is a recursive algorithm and time complexity can be expressed as following recurrence relation.
//T(n) = 2T(n/2) + Theta(n)
//The above recurrence can be solved either using Recurrence Tree method or Master method. It falls in case II of Master Method and solution of the recurrence is Theta(nLogn).
//Time complexity of Merge Sort is Theta(nLogn) in all 3 cases (worst, average and best) as merge sort always divides the array into two halves and take linear time to merge two halves.

//Auxiliary Space: O(n)

//Algorithmic Paradigm: Divide and Conquer

//Sorting In Place: No in a typical implementation

//Stable: Yes

//Requires stack space 

//Merging is done in postorder

#include<stdio.h>
#include<stdlib.h>

void merge(int *a,int l,int mid,int h){ 
    int i,j,k;
    int b[100];
    i=l;
    j=mid+1;
    k=l;
    while(i<=mid && j<=h){  //Filling array in ascending order

        if(a[i]<a[j]) //If first half element is less than second halfs element in corresponding po
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

void MergeSort(int *a,int l,int h){ 

    if(l<h){ //POST ORDER MERGING
        int mid = (l+h)/2;
        MergeSort(a,l,mid);
        MergeSort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}

void main(){
    int i,n,*a;
    printf("Enter the number of elements in array\n");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    printf("Enter the numbers to be Sorted\n");
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    MergeSort(a,0,n-1);
    printf("SORTED ARRAY =  ");
    for(i=0;i<n;i++)
    printf("%d ",*(a+i));
}
