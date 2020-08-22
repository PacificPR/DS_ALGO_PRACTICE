#include <iostream>
#include <queue>

using namespace std;

int BFS(int G[8][8],int s,int d){
    int visited[8] = {0};
    queue<int> q;
    visited[s] = 1;
    q.push(s);
    int dist[8] = {0};
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 1;v <=7;v++){
            if(G[u][v]==1&&visited[v]==0){
                visited[v] = 1;
                dist[v] = dist[u]+1;
                if(v==d)
                    return dist[v];
                q.push(v);
            }
        }
    }
    return -1;
}

int main(){         
                                                         // The Graph : 

    int Graph[8][8]={{0,0,0,0,0,0,0,0},                  // 1----2
                     {0,0,1,1,1,0,0,0},                  // |\   |
                     {0,1,0,1,0,0,0,0},                  // | \  |
                     {0,1,1,0,1,1,0,0},                  // |  \ |
                     {0,1,0,1,0,1,0,0},                  // |   \|
                     {0,0,0,1,1,0,1,1},                  // 4----3  
                     {0,0,0,0,0,1,0,0},                  //  \  /
                     {0,0,0,0,0,1,0,0}};                 //    5 
                                                         //   / \
                                                         // 6     7
                                                         //   
    int s,d;
    cout<<"Enter the source and destination to find shortest distance between them\n";
    cin>>s>>d;                                                      
                                                        
    cout<<"SHORTEST DISTANCE BETWEEN THEM IS : "<<BFS(Graph,s,d)<<endl;
}

/*
    BFS IS BETTER THAN DIJKSTRA OR BELLMAN-FORD FOR UNWEIGHTED GRAPH

    BFS ONLY TAKES O(V+E) TIME

   Whereas, Bellman-Ford algorithm in O(VE) time, Dijkstra’s algorithm in O(E+VlogV).


    THIS IS UNWEIGHTED GRAPH, SO EACH EDGE IS 1 UNIT WEIGHTED

    (IGNORE) ******* TEST GRAPH****
                                                        // The Graph : 

    int Graph[8][8]={{0,0,0,0,0,0,0,0},                  // 1----2
                     {0,1,1,1,0,0,0,0},                  // |\   |
                     {0,1,0,1,0,0,0,0},                  // | \  |
                     {0,1,1,0,1,0,0,0},                  // |  \ |
                     {0,1,0,1,0,1,0,0},                  // |   \|
                     {0,0,0,1,1,0,1,1},                  // 4----3  
                     {0,0,0,0,0,1,0,0},                  //  \  /
                     {0,0,0,0,0,1,0,0}};                 //    5 
                                                         //   / \
                                                         // 6     7
 
*/
