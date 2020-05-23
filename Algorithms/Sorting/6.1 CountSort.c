//Overall complexity = O(max)+O(size)+O(max)+O(size) = O(max+size)
// where size->size of array , max-> max number in array

    //Worst Case Complexity: O(n+k)
    //Best Case Complexity: O(n+k)
    //Average Case Complexity: O(n+k)

//In all the above cases, the complexity is the same because no matter how the elements are placed in the array, the algorithm goes through n+k times.

//There is no comparison between any elements, so it is better than comparison based sorting techniques. 
//But, it is bad if the integers are very large because the array of that size should be made.

//Space Complexity:
//The space complexity of Counting Sort is O(max). Larger the range of elements, larger is the space complexity.

//Counting sort is used when:

    // 1. There are smaller integers with multiple counts.
    // 2. Linear complexity is the need.



#include<stdio.h>
#include<stdlib.h>

int Maxnum(int *a,int n){
    int max=a[0];
    for(int i=1;i<n;i++)
        if(a[i]>max)
            max=a[i];
    return max;

}

void CountSort(int *a,int n){ 
    int i,j,*c;
    int max = Maxnum(a,n);
    c=(int *)malloc((max+1)*sizeof(int)); //Creatign a count array of size of max number +1 
    for(i=0;i<=max;i++)  //Assigning the count array by 0;
        c[i]=0;
    for(i=0;i<n;i++)  //Store the count of each element at their respective index in count array
        c[a[i]]++;
    i=0;j=0;
    while(j<=max){  //Iterating count array to store the index(represents the element) in the main array
        if(c[j]>0){ // If the count is not 0, store that index in array 
            a[i++]=j;
            c[j]--;
        }
        else        //The count is 0 so move to next index in count array
            j++;

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
    CountSort(a,n);
    printf("SORTED ARRAY =  ");
    for(i=0;i<n;i++)
        printf("%d ",*(a+i));
}

