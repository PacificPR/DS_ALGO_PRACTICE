#include<iostream>

using namespace std;

double myPow(double x, int n){
    if(n==0)                    //Base Condition, return 1 if power is 0
        return 1;

    double half = myPow(x,n/2);  //Get half exponent power 
    double base = n<0 ? 1/x : x; // If exponent is negative, number would be inversed else same

    return n%2==0 ? half*half : base*half*half; // If power is even half*half else we need base*half*half
}

int main(){
    double x;
    int n;
    cout<<"Enter base and exponent\n";
    cin>>x>>n;

    cout<<"Pow : "<<myPow(x,n)<<endl;

    return 0;
}

