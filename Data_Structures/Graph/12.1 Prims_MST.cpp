#include<iostream>
#include<vector>
#include<set>

using namespace std;

void Prims(vector<pair<int,int>> adj[],int V,int E){
    int *d = new int[V];        //Like dijkstra, it keeps track of smallest distance to V node but from any vertex in MST which doesn't form cycle
    int *parent = new int[V];   //Parent vertex , which leads to other vertex on end of its edge
    fill(d,d+V,INT32_MAX);      //Initially fill d as infinity for every vertex
    d[0] = 0;                   //d for starting point is 0
    vector<bool> selected(V, false); //Keep track of visited vertex
    set< pair<int,int> > s;   //{dist,vertex} pair, stores shortest dist to the vertex  from a vertex in MST
    s.insert({0,0});           // Enter starting point as 0 with distance 0

    while(!s.empty()){          //Till the set is not empty
        int src = s.begin() -> second;  //Top contains the pair of {dist,vertex} with smallest distance in the set, as we select the adjacent vertex with minimum weight  in the MST
        s.erase(s.begin());     

        selected[src] = true;    //Mark it as visited to avoid being included again leading to cycles
        for(auto p : adj[src]){  //Visit all adjacent vertex in the adjacency list 
            int v = p.first;    //  Contains the neighbouring vertex of src
            int w = p.second;   //  Weight of the edge from src to neighbour vertex

            if(selected[v]==false && d[v]>w){   //If it's not included in MST and its dist for mst(which is infinte at start)  is greater than current edge
                s.erase({d[v],v});  //Delete it's previous dist record
                d[v] = w;           //Update the newer, shorter distance in MST
                parent[v] = src;    //Set its parent as src
                s.insert({d[v],v}); //Include this edge by adding it's newer dist and dest vertex
            }
        }
    }
    
    int mst_cost = 0;
    for(int i=0;i<V;i++){
        cout<<" DIST OF "<<i<<" : "<<d[i]<<"\n";
        mst_cost += d[i];
    }

    for(int i=1;i<V;i++)
        cout<<parent[i]<<"-->"<<i<<"\n";
    cout<<"MINIMUM COST : "<<mst_cost<<"\n";

}

int main(){
    int V,E;
    cout<<"Enter number of vertex and edges\n";
    cin>>V>>E;
    cout<<"Enter the edges in order { source, destination, weight }\n";
    int u,v,w;

    vector<pair<int,int>> adj[V];
    for(int i=0;i<E;i++){
        cin>>w>>u>>v;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    Prims(adj,V,E);
}

