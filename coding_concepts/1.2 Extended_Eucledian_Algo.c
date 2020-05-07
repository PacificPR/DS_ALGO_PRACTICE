// Bézout's identity — Let a and b be integers with greatest common divisor d. 
// Then, there exist integers x and y such that ax + by = d. More generally, the integers of the form ax + by are exactly the multiples of d.


// ************************ We can write a%b as a-(a/b)*b  *******************


#include<stdio.h>

int  gcdextended(int a,int b,int *x,int *y){
    if(a==0){ //BASE CASE
        *x=0;
        *y=1;
        return b;
    }

    int x1,y1;// To store results of recursive call
    int gcd = gcdextended(b%a,a,&x1,&y1);

    // Update x and y using results of  
    // recursive call 

    *x=y1-(b/a)*x1;  //like in gcd we did gcd(b%a,a) here b%a is in x;
    *y=x1;

    return gcd;
}

void main(){
    int a,b,x,y;
    printf("Enter two numbers to find their gcd and coefficients satisfying Bezout's Identity\n");
    scanf("%d%d",&a,&b);
    printf("GCD : %d\n",gcdextended(a,b,&x,&y));
}

// The extended Euclidean algorithm is particularly useful when a and b are coprime (or gcd is 1). 
// Since x is the modular multiplicative inverse of “a modulo b”, and y is the modular multiplicative inverse of “b modulo a”. 
// In particular, the computation of the modular multiplicative inverse is an essential step in RSA public-key encryption method.
