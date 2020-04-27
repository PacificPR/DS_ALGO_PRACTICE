//Generalizing how to find nth digit of a number

#include<stdio.h>

void main(){
    int n,k;
    int ld,l2d,l3d,lkd;
    printf("Enter the number\n");
    scanf("%d",&n);

    ld=(n/1)%10; //GIves the last digit
    l2d=(n/10)%10; //Removes the last digit on division, then gives the last remainig digit i.e the 2nd last digit overall
    l3d=(n/100)%10; //Removes the last two digits on division, then gives the last remainig digit i.e the 3rd last digit overall
    printf("last digit in the number is %d\n",ld);
    printf("2nd last digit in the number is %d\n",l2d);
    printf("3rd last digit in the number is %d\n",l3d);
    printf("Enter the kth digit to find from that number\n");
    scanf("%d",&k);
    lkd=(n/(10^(k-1)))%10;
    printf("%dth digit in the number from last is %d\n",k,lkd);
}

