// Basic Euclidean Algorithm for GCD
//The algorithm is based on below facts.



//If we subtract smaller number from larger (we reduce larger number), GCD doesn’t change. So if we keep subtracting repeatedly the larger of two, we end up with GCD.
//Now instead of subtraction, if we divide smaller number, the algorithm stops when we find remainder 0.

// Time Complexity: O(Log min(a, b))

#include<stdio.h>

int gcd(int a,int b){
    if(a==0)
        return b;
    gcd(b%a,a);
}

int gcd2(int a,int b){ //ba ba b
    if(b==0)
        return a;
    gcd2(b,a%b);
}

int gcd3(int a,int b){
    if(b==0)
        return a;
    gcd2(a%b,b);
}


void main(){
    int a,b;
    printf("Enter two numbers to find their GCD\n");
    scanf("%d%d",&a,&b);
    printf("GCD   : %d\n",gcd(a,b));
    printf("GCD 1 : %d\n",gcd2(a,b));
    printf("GCD 2 : %d\n",gcd3(a,b));
}

// FIND GCD OF MULTIPLE NUMBERS
//  gcd(a, b, c) = gcd(a, gcd(b, c)) 
//  = gcd(gcd(a, b), c) 
//  = gcd(gcd(a, c), b)
