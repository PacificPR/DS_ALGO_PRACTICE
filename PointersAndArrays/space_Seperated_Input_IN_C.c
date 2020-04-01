//We are passing the address of the actual parameters , in call by address, the
//value of actual parameter changes if formal parameter are changed.

#include<stdio.h>
#include<stdlib.h>


int main() {
    int i,n;
    printf("ENTER NO OF ELEMENTS IN ARRAY:\n");
    scanf(" %d",&n);
    int *a;
    a=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",(a+i));
    for(i=0;i<n;i++)
        printf("%d ",*(a+i));
    return 0;
    }   
