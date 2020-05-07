//TWO WAYS TO SWAP WITHOUT USING A VARIABLE
//HENCE SAVING EXTRA MEMORY 


#include<stdio.h>
#include<stdlib.h>

// The bitwise XOR operator can be used to swap two variables. 
// The XOR of two numbers x and y returns a number which has all the bits as 1 wherever bits of x and y differ
// a^a=0;
// a^0=a;
// Because xor is fully associative and commutative:
// IT works, in 2nd step b=a^b=(a^b)^b= a^(b^b){associative property} = a
// in last step a=a^b=(a^b)^a =(a^a)^b {Associative property} a = b
void swap1(int a,int b) {
    a = a^b;
    b = a^b;
    a = a^b;
    printf("a = %d\nb = %d \n",a,b);
}

void swap2(int a,int b) {
    a = a+b;
    b = a-b;
    a = a-b;
    printf("a = %d\nb = %d \n",a,b);
}

void swap3(int a,int b) {
    a = a*b;
    b = a/b;
    a = a/b;
    printf("a = %d\nb = %d \n",a,b);
}


int main() {
    int a,b;
    printf("ENTER NUMBERS TO BE SWAPPED \n");
    scanf("%d%d",&a,&b);
    swap1(a,b);
    swap2(a,b);
    swap3(a,b);
    return 0;
    }   
//************  Problems with above methods  ****************
//1) The multiplication and division based approach doesn’t work if one of the numbers is 0 as the product becomes 0 irrespective of the other number.

//2) Both Arithmetic solutions may cause arithmetic overflow. If x and y are too large, addition and multiplication may go out of integer range.

//3) When we use pointers to variable and make a function swap, all of the above methods fail when both pointers point to the same variable. 

//Let’s take a look what will happen in this case if both are pointing to the same variable.

// Bitwise XOR based method
//      x = x ^ x; // x becomes 0
//      x = x ^ x; // x remains 0
//      x = x ^ x; // x remains 0

// Arithmetic based method
//      x = x + x; // x becomes 2x
//      x = x – x; // x becomes 0
//      x = x – x; // x remains 0
