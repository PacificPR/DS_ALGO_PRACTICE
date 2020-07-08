/*  
Q. The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
   Given two integers x and y, calculate the Hamming distance.

In information theory, the Hamming distance between two strings of equal length is the number of positions at which the corresponding symbols are different.
  In other words, it measures the minimum number of substitutions required to change one string into the other, 
  or the minimum number of errors that could have transformed one string into the other.
  In a more general context, the Hamming distance is one of several string metrics for measuring the edit distance between two sequences. 


*/


#include<iostream>

using namespace std;

int main(){
    int x,y;
    cout<<"Enter 2 numbers to find their hamming distance\n";
    cin>>x>>y;

    int z = x^y;  //Xor gives 1 when bits are different, so we have to count the no of 1s in the formed number
    
    int count=0;

    while(z){    //Couning number of 1s in the XOR of two numbers
        z = z&(z-1);
        count++;
    }

    cout<<"Hamming distance : "<<count<<"\n";

}

