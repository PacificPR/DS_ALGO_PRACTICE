
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void Insert(struct node* s,int n){
    struct node* t;
    t=(struct node*)malloc(sizeof(struct node));
    

int Maxnum(int *a,int n){ 
    int max=a[0];
    for(int i=1;i<n;i++)
        if(a[i]>max)
            max=a[i];
    return max;

}

void BucketSort(int *a,int n){ 
    int max;
    struct node** bucket;
    bucket=(struct node**)malloc(max*sizeof(struct node*));
    //struct node *(count[10]); //Count is the array of Pointers of struct
    for(int i=0;i<=max;i++)
        bucket[i]=null;

    max=Maxnum(a,n);
}

void main(){
    int i,n,*a;
    printf("Enter the number of elements in array\n");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    printf("Enter the numbers to be Sorted\n");
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    BucketSort(a,n);
    printf("SORTED ARRAY =  ");
    for(i=0;i<n;i++)
        printf("%d ",*(a+i));
}

