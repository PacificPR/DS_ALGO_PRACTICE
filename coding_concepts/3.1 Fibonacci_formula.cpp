// C++ Program to find n'th fibonacci Number 
#include<iostream> 
#include<cmath> 

int fib(int n) { 
double phi = (1 + sqrt(5)) / 2;         //Golden Ration, i.e 1.618....
return round(pow(phi, n) / sqrt(5));    //For nth fibonacci number
} 

// Driver Code 
int main () 
{ 
int n ; 
std::cin>>n;
std::cout << fib(n) << std::endl; 
return 0; 
} 

