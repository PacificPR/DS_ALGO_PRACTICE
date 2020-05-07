#include<iostream>
#include<vector>
#include<typeinfo>
#include<algorithm>

using namespace std;

bool f(int a,int b){
    return a>b;
}

int main(){
    vector<int> v;
    vector<int> v2;
    int i;
    v.push_back(10);
    v.push_back(13);
    v.push_back(15);
    v.push_back(15);
    v.push_back(15);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(70);
    vector<int>::iterator t1,t2;
    sort(v.begin(),v.end(),greater<>());
    for(auto q:v)
    cout<<q<<"  ";

    t1=lower_bound(v.begin(),v.end(),25,greater<>());
    t2=upper_bound(v.begin(),v.end(),15,greater<>());
    //cout<<v.at(v.begin())<<" ";
    cout<<*t1<<" ";
    cout<<*t2<<" ";
    //cout<<distance(v.begin(),t1)<<"\n";
    //cout<<distance(v.begin(),t2);
    //vector<int>::reverse_iterator it;
    //for(it=v.rbegin();it!=v.rend();it++)
    //    cout<<*it<<" ";     

    return 1;
}



