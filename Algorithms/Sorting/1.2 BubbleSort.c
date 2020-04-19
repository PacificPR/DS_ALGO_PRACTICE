//  ANALYSIS 
//Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.


//Best Case Time Complexity: O(n). Best case occurs when array is already sorted.

//Auxiliary Space: O(1)

//Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.

//Sorting In Place: Yes

//****We can use this to find the largest or second largest or third or so on
//largest number in very less time.
//As the first iteration gives us the largest number at the last position
//So the second iteration gives us the 2nd largest no at the 2nd last postition
//So the third iteration gives us the 3rd largest no at the 3rd last postition
// *****

//Stable: Yes  {If no. is part of key-value pair,their order won't be distrubed
//              even if value is same of 2 different keys}


#include<stdlib.h>
#include<stdio.h>

void swap(int *p,int *q){
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

void Bubblesort(int *a,int n){
    int i,j,m;
    int flag; 
    for(i=0;i<n-1;i++){
        flag=0;
        for(j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                swap((a+j),(a+j+1));
                flag=1;
            }
        }
        if(flag==0)
            break;
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
    Bubblesort(a,n);
    printf("SORTED ARRAY =  ");
    for(i=0;i<n;i++)
        printf("%d ",*(a+i));
}
