#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class DisjointSet{

    unordered_map<int,int> rank;
    unordered_map<int,int> parent;

    public:    
    void makeSet(int a){
        rank[a] = 0;
        parent[a] = a;
    }

    int find(int a){
        if(parent[a]==a)
            return a;
        return parent[a] = find(parent[a]);
    }
    
    void Union_set(int a,int b){
        int par_a = find(a);
        int par_b = find(b);
    
        if(par_a==par_b){   //If parents are equal, then they belong to same set
            cout<<"Same set "<< a <<" and " <<b<<"\n";
            return;
        }
    
        //Attach the lower rank to the higher rank, i.e. set parent of lower ranked to parent of higher rank
        if(rank[par_a]>rank[par_b])     
            parent[par_b] = par_a;
        else if(rank[par_b]>rank[par_a])
            parent[par_a] = par_b;
        else{
            parent[par_a] = par_b;
            rank[par_b]++;
        }
    }
};

void print_uni(vector<int>& uni,DisjointSet& ds){
    for(int i:uni)
        cout<<"Num : "<<i<<"  Parent: "<<ds.find(i)<<"  \n";
}

int main(){
    int N;
    DisjointSet ds;
    cout<<"Enter Number of elements in Universe\n";
    cin>>N;
    vector<int> universe;
    cout<<"Enter the Numbers \n";
    int temp;
    for(int i=0;i<N;i++){
       cin>>temp;
       universe.push_back(temp);
       ds.makeSet(temp);
    }
    
    print_uni(universe,ds);

    ds.Union_set(1,3); 
    print_uni(universe,ds);
    ds.Union_set(2,4); 
    print_uni(universe,ds);
    ds.Union_set(4,1); 
    print_uni(universe,ds);
    ds.Union_set(2,3); 
    print_uni(universe,ds);
}   



