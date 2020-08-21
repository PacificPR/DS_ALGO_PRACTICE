/*
How to get the last bit of number?
Use bitwise & with 1.
n = 5 => 101 & 001 ==> 1 last bit

How to remove the last bit of number?
right shift by 1, n >> 1 => 5 >> 1 => 2 (101 >> 1 = 10)

How to add new bit in number?
First let shift and then take bitwise | with bit
(reverse << 1) | (bit)
ex. reverse = 10, bit 1 => (10 << 1) | (001) = (100) | (001) = 101

Idea:
Now using this set of operators run for 32 time loop as Integer represented.
append new bit from the last of n in resverse variable and remove the last bit from n. 
*/


#include<iostream>

using namespace std;

   uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i=0;i<32;i++){
            res = (res<<1) | (n&1);
            n=n>>1;
        }
        return res;
    }

    int main(){
        uint32_t num;
        cin>>num;
        uint32_t res = reverseBits(num);
        cout<<unsigned(res)<<endl;
    }

