//  Given an integral number N. The task is to find the count of digits present in this number.

//Let's say:
//N = 2019

//Number of digits in N here is 4

// etter Solution: A better solution is to use mathematics to solve this problem. The number of digits in a number say N can be easily obtained by using the formula:
//          ************ number of digits in N = log10(N) + 1. ********************

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout<<"ENTER A NUMBER TO FIND NUMBER OF DIGITS IN IT \n "<<endl;
    cin>>n;
    int dig=floor(log10(n)+1);
    cout<<dig<<endl;
}

// We can find no of digits in a^b by using this concept
//   D(a^b) = (log(a^b))+1
//          = (b*log(a))+1
