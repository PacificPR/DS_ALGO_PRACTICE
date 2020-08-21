#include <iostream>
#include <vector>

using namespace std;

void make_set(int n,vector<int> &par){
    par[n] = n;
}

int find_set(int a,vector<int> &par){
    if(par[a]==a)
        return a;
    return find_set(par[a],par);    //Basic Without Path Compression
}

void union_set(int a,int b,vector<int> &par){
    int par_a = find_set(a,par);
    int par_b = find_set(b,par);

    if(par_a==par_b)
        return;
    else
        par[par_b] = par_a;         //NAIVE UNION , may make the tree O(n), skewed
}

int main(){
    int N;
    cout<<"Enter Number of Nodes\n";
    cin>>N;
    vector<int> par(N+1);
    for(int i=1;i<=N;i++)
        make_set(i,par);    //Initially make every node it's own parent

    union_set(1,2,par);for(int i=1;i<=N;i++)
        cout<<"Parent of "<<i<<"  is  : "<<par[i]<<"\n"; 
    union_set(3,4,par);for(int i=1;i<=N;i++)
        cout<<"Parent of "<<i<<"  is  : "<<par[i]<<"\n"; 
    union_set(1,4,par); for(int i=1;i<=N;i++)
        cout<<"Parent of "<<i<<"  is  : "<<par[i]<<"\n"; 
    union_set(3,5,par); for(int i=1;i<=N;i++)
        cout<<"Parent of "<<i<<"  is  : "<<par[i]<<"\n"; 
    union_set(2,4,par); for(int i=1;i<=N;i++)
        cout<<"Parent of "<<i<<"  is  : "<<par[i]<<"\n"; 

//    for(int i=1;i<=N;i++)
//       cout<<"Parent of "<<i<<"  is  : "<<par[i]<<"\n";    
    return 0;
}
