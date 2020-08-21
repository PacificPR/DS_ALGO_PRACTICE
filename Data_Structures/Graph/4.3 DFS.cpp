#include <iostream>

using namespace std;

void DFS(int G[8][8],int start){
    static int Visited[8] = {0};

    if(Visited[start]==0){
        Visited[start] = 1;
        cout<<" "<<start<<" ";
        for(int v = 1;v<=7;v++){
            if(Visited[v]==0&&G[start][v]==1){
                DFS(G,v);
            }
        }
        
    }
    
}

int main(){
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
                                                         //   
    cout<<"DFS : ";
    DFS(Graph,1);
}
