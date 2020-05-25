//Input 123
//Output = 1+2+3 =6
//
//Input 1923
//Output = 1+9+2+3
//       = 15 = 1+5
//       = 6
//So recursive sum of the digits until it's a single digit
#include<iostream>

using namespace std;
int main(){
    int n;
    cout<<"Enter the number "<<"\n";
    cin >> n;
    int d = n%9;
    if(n<=9)
        cout<<n;
    else{
        d=(d==0)?9:d;
        cout<<" Single digit sum : "<<d<<"\n";
    }
    return 1;
}


