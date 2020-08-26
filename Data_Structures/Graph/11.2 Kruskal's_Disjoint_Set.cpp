/* 
    Keep in mind in what form edges has to be inputed to help in sorting later on,  spoiler alert : vector<pair<int,pair<int,int>>> i.e. <w,{u,v}>

Kruskal's algorithm initially places all the nodes of the original graph isolated from each other, to form a forest of single node trees.
Then gradually merges these trees, combining at each iteration any two of all the trees with some edge of the original graph. 
Before the execution of the algorithm, all edges are sorted by weight (in non-decreasing order). 
Then begins the process of unification: pick all edges from the first to the last (in sorted order), 
and IFF the ends of the currently picked edge belong to different subtrees(TO AVOID CYCLES), these subtrees are combined, and the edge is added to the answer. 

After iterating through all the edges, all the vertices will belong to the same sub-tree, and we will get the answer.

SPACE : O(N) for makeSet
TIME : O(ElogV)
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct DisjointSet{
    int *rank;
    int *parent;

    void makeSet(int n){    //Initialize n vertices,with rank and parent, starting from 0
        rank = new int[n];
        parent = new int[n];
        for(int i=0;i<n;i++){
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int find(int n){
        if(parent[n]==n)
            return n;
        return parent[n] = find(parent[n]); //Path Compression
    }

    void union_set(int a,int b){
        int x = find(a);
        int y = find(b);

        if(x==y)
            return;
        
        if(rank[x]>rank[y]) //Attach smaller tree to larger tree
            parent[y] = x;
        else if(rank[x]<rank[y])
            parent[x] = y;
        else{
            parent[y] = x;
            rank[x]++;
        }
    }
};

void Kruskal(vector<pair<int,pair<int,int>>> Edges,int V,int E){
    DisjointSet ds;
    ds.makeSet(V);
    
    vector<pair<int,int>> res(V-1);  //V-1 edges in MST , {source,dest} in the minimum spanning tree;
    int mst_cost = 0;
    int e = 0;      //Make sure MST has V-1 edges covering V verices
    sort(Edges.begin(),Edges.end());

    for(int i=0;i<E && e<V-1;i++){    //Iterate over all edes until e<V-1 i.e. all vertices are included in result
        int w = Edges[i].first;
        int u = Edges[i].second.first;
        int v = Edges[i].second.second;

        int x = ds.find(u);
        int y = ds.find(v);
        if(x==y)
            continue;
        ds.union_set(x,y);
        res[e++] = {u,v};
        mst_cost += w;
    }

    cout<<" MINIMUM SPANNING TREE EDGES : \n";
    for(auto i:res)
        cout<<i.first<<"-->"<<i.second<<" \n";
    cout<<"COST OF THIS MST IS : "<<mst_cost<<"\n";
    
}

int main(){
    int V,E; 
    vector<pair<int,pair<int,int>>> Edges;      //Stores {weight,{source,dest}}, so we can sort on basis of weight later on
    cout<<"Enter number of Vertices and edges\n";
    cin>>V>>E;

    cout<<"Enter the edges in order { source destination weight }\n";
    int w,u,v;
    for(int i=0;i<E;i++){
        //cin>>u>>v>>w;
        cin>>w>>u>>v;
        //Edges[i].push_back({{w,{u,v}}});
        Edges.push_back(make_pair(w,make_pair(u,v)));
    }
    Kruskal(Edges,V,E);
}
