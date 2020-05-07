#include<iostream>
#include<array>

using namespace std;

int main(){
    array<int,5> ar;
    for(int i=0;i<5;i++)
        ar.at(i)=i;

    for(int i=0;i<5;i++)
        cout<<ar[i]<<endl;
    cout<<"size of array = "<<ar.size()<<endl;
    cout<<" array front = "<<ar.front()<<endl;
    cout<<" array back = "<<ar.back()<<endl;
    return 1;
}

