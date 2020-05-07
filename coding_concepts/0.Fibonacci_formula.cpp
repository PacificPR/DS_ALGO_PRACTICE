// C++ Program to find n'th fibonacci Number 
#include<iostream> 
#include<cmath> 

int fib(int n) { 
double phi = (1 + sqrt(5)) / 2; 
return round(pow(phi, n) / sqrt(5)); 
} 

// Driver Code 
int main () 
{ 
int n ; 
std::cin>>n;
std::cout << fib(n) << std::endl; 
return 0; 
} 

