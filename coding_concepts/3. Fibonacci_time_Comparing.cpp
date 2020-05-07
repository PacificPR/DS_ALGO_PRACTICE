//  Look at the final digit in each Fibonacci number – the units digit:

//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, ...
//Is there a pattern in the final digits?

//0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, ...

//Yes!
//It takes a while before it is noticeable. In fact, the series is just 60 numbers long and then it repeats the same sequence again and again all the way through the Fibonacci series – for ever. 
//The series of final digits repeats with a cycle length of 60 (Refer this for explanations of this result).

//So, instead of calculating the Fibonacci number again and again, pre-compute the units digit of first 60 Fibonacci number and store it in an array and use that array values for further calculations.

//So 0 to 59 will have the last digit as a pattern which will repeat on 60th,hence n%60 will give index required for the last digit                           

#include<iostream>
#include<chrono>
#include<array>
#include<vector>

using namespace std;

int fibonacci(int n){
    if(n<=1)
    return n;
    else
    return fibonacci(n-1)+fibonacci(n-2);
}

int fibonacci_improve(int n){
   vector<int> v;
   v.reserve(n);
   v[0]=0;v[1]=1;
   for(int i=2;i<=n;i++)
        v[i]=v[i-1]+v[i-2];
    return v[n];

}

int main(){
    int n;
    cout<<"Enter n for fibonnaci series\n"<<endl;
    cin>>n;
    auto s1 = chrono::high_resolution_clock::now();
    cout<<fibonacci(n)<<endl;
    auto s2=(chrono::high_resolution_clock::now()) ;
    auto time = s2-s1;
    cout<<time/chrono::milliseconds(1)<<endl;
    cout<<"Improved Fibonacci"<<endl;
    s1=chrono::high_resolution_clock::now();
    cout<<fibonacci_improve(n)<<endl;
    s2=chrono::high_resolution_clock::now();
    time=s2-s1;
    cout<<time/chrono::milliseconds(1)<<endl;
}
