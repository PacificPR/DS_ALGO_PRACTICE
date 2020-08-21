/*  Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n\n";
    cin>>n;

    int ugly[n];
    int indx2=0,indx3=0,indx5=0;
    int val2,val3,val5;
    int count=1;
    ugly[0]=1;
    int val=0;
    while(count<n){
        val2 = ugly[indx2]*2;
        val3 = ugly[indx3]*3;
        val5 = ugly[indx5]*5;

        val = min(val2,min(val3,val5));
        if(val==val2)
            indx2++;
        if(val==val3)
            indx3++;
        if(val==val5)
            indx5++;

        ugly[count++]=val;
    }

    for(int i=0;i<n;i++)
        cout<<ugly[i]<<"  ";
    //cout<<"Nth ugly number :  "<<ugly[n-1]<<endl;
    return 0;

}

/*
                                        1
                                      /  | \
                                    2    3   5
                                   /|\  /|\  .
                                  4 6 8 6 9 15
                                  .
                                  .
            So, starting with 1 as node, the list expands bu multiplying with either 2,3 or 5 depending on the smallest value,
            thus only the numbers in form of (2^p)(3^q)(5^r)  are selected
*/
