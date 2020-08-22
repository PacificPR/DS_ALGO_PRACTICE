#include <iostream>
#include <queue>

using namespace std;

void BFS(int G[8][8],int k){
    int visited[8] = {0};
    queue<int> q;
    visited[k] = 1;
    q.push(k);
    while(!q.empty()){
        int u = q.front();
        //cout<<u<<" ";
        q.pop();
        for(int v = 1;v <=7;v++){
            if(G[u][v]==1&&visited[v]==0){
                visited[v] = 1;
                cout<<u<< " PUSHING "<<v<<" \n";
                q.push(v);
            }
        }

    }

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
    cout<<"BFS : "<<endl;
    BFS(Graph,1);
}
