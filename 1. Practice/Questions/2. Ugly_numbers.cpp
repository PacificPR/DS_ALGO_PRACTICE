/*  
In number system, ugly numbers are positive numbers whose only prime factors are 2, 3 or 5.
First 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12. By convention, 1 is included.
*/

#include <iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter a number to check if it's ugly or not\n";
    cin>>n;
    int t = n;
    int f=0;
    while(t!=1){
        if(t%5==0)
            t/=5;
        else if(t%3==0)
            t/=3;
        else if(t%2==0)
            t/=2;
        else{
            f=1;
            cout<<n<<" is not an ugly number \n";
            break;
        }
    }

    if(f==0)
        cout<<n<<" is an ugly number\n";

    return 0;
}

