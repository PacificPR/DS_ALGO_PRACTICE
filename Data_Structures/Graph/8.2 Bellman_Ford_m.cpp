/*

Why do we need to be careful with negative weights?
Negative weight edges can create negative weight cycles i.e. a cycle that will reduce the total path distance by coming back to the same point.

    ###  Notes
1) Negative weights are found in various applications of graphs.
   For example, instead of paying cost for a path, we may get some advantage if we follow the path.

2) Bellman-Ford works better (better than Dijksra’s) for distributed systems.
   Unlike Dijkstra’s where we need to find the minimum value of all vertices, in Bellman-Ford, edges are considered one by one.

#### APPLICATIONS :
    1. For calculating shortest paths in routing algorithms

    ####  Time Complexity: O(VE)
*/
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void Bellman_ford(vector<int> edge[],int s,int V,int E){
    int dist[V];    //Array to store shortest dist to each vertex from source
    fill(dist,dist+V,INT32_MAX);//Initialy set shortest dist as INFINITY FOR EVERY VERTEX
    dist[s] = 0;                //Minm dist from source to source is 0

    for(int i=1;i<=V-1;i++){  //Relax all edges V-1 times
        for(int j=1;j<=E;j++){  //Iterate over each edge and update dist of destintaion in each edge( edge[j][1]), if it's greater than dist[parent]+weight of edge
            if(dist[edge[j][1]]>dist[edge[j][0]]+edge[j][2]){   
                dist[edge[j][1]] = dist[edge[j][0]]+edge[j][2];
            }
        }
    }  

    //IF THERE'S NO NEGATIVE WEIGHT CYCLE,Relaxing the edges V-1 Times will give the shortest path for all vertex, i.e. the final answer

    
    //Vth time , Checking if any edge can be updated to shorter state, which means there's a negative weight cycle 
    for(int i=1;i<=E;i++){
        if(dist[edge[i][1]]>dist[edge[i][0]]+edge[i][2]){
            cout<<"Graph contains negative weight cycle \n";
            return;
        }
    }
    //If there's no negative weight cycle, print the shortest distances
    for(int i=0;i<V;i++)
        cout<<"Shortest Distance to "<<i<<"  FROM "<<s<<" is : "<<dist[i]<<"\n";
    
}

int main(){
    int V,E;
    cout<<"Enter number of vertices and edges in graph\n";
    cin>>V>>E;
    vector<int> edge[E+1]; //Array of Edges of vertices and weight,edges[i]->{u,v,w} for edge uv of weight w
    cout<<"Enter the vertices in edges with weight\n";
    int u,v,w;
    for(int i=1;i<=E;i++){
        cin>>u>>v>>w;
        edge[i].push_back(u);
        edge[i].push_back(v);
        edge[i].push_back(w);
    }
    int s;
    cout<<"Enter the source for which shortest dist to every other vertex is to be found : ";
    cin>>s;
    Bellman_ford(edge,s,V,E);
}