#include<iostream>

using namespace std;

void f (int n)
{
    if (n/2)  {
        f(n/2);
    }
    printf ("%d", n%2);
}

int main(){
    int n;
    cout<<"Enter number to find it's binary form\n";
    cin>>n;
    f(n);
    return 0;
}
