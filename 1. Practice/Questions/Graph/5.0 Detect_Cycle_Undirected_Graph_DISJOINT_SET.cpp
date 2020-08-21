/* TO DETECT CYCLE IN A UNDIRECTED GRAPH : 
 *      1. DISJOINT SET
 *      2. DFS
 *      3. BFS
*/

#include<bits/stdc++.h>

using namespace std;

class DisjointSet{

unordered_map<int,int> rank;
unordered_map<int,int> parent;

public:
    
    void make_set(int a){
        parent[a] = a;
        rank[a] = 0;
    }

    int find(int a){
        if(parent[a]!=a)
            parent[a] = find(parent[a]);         //Path Compression
        return parent[a];
    }

    void Union_set(int a , int b){                          //Union By Rank
        int xRoot = find(a);
        int yRoot = find(b);

        if(xRoot == yRoot)
            return;

        if(rank[xRoot] > rank[yRoot])
            parent[yRoot] = xRoot;
        else if (rank[yRoot] > rank[xRoot])
            parent[xRoot] = yRoot;
        else{
            parent[xRoot] = yRoot;
            rank[yRoot]++;
        }
    }
    
    bool isCycle(set<pair<int,int>> &edges){
        for(auto &i : edges){
            int x = find(i.first);
            int y = find(i.second);
            
            if(x==y){
                cout<<"FOR EDGE : "<< i.first <<" and " << i.second<<" ";
                return true;

            }
            Union_set(x,y);
        }
        return false;
    }
};


int main(){
    int V,E;
    cout<<"Enter number of Vertices\n";
    cin>>V;
    DisjointSet ds;
    for(int i=0;i<V;i++)
        ds.make_set(i);
    cout<<"Enter the number of Edges\n";
    cin>>E;
    set<pair<int,int>> edges;
    cout<<"Enter the edges\n";
    int a,b;
    for(int i=0;i<E;i++){
        cin>>a>>b;
        edges.insert({a,b});
    }
    //ds.make_set(edges);

    if(ds.isCycle(edges))
       cout<<"Cycle exists\n"; 
    else
       cout<<"Cycle doesn't exist\n"; 
}


