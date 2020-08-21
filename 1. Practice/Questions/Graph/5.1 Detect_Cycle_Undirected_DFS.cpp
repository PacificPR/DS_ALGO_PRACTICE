#include<iostream>
#include<vector>

using namespace std;


bool dfs_util(vector<int> graph[],vector<bool> &visited,int curr, int parent){

    visited[curr] = true;
    for(auto nbr:graph[curr]){
        //TWO CASES :
        
        //IF NEIGHBOUR NODE ISN'T VISITED, RECURSIVELY VISIT IT AND RETURN IF IT's TRUE
        if(!visited[nbr]){

            if(dfs_util(graph,visited,nbr,curr))
                return true;
        }
        //IT'S VISITED AND IF IT ISN'T THE PARENT NODE OR nbr is same as current node, RETURN TRUE
        else if(nbr!=parent || nbr==curr)
            return true;
    }

    return false;

}

bool dfs(vector<int> graph[],int V){

    vector<bool> visited(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i] && dfs_util(graph,visited,i,-1))
            return true;
    }
    return false;
}

int main(){
    int V,E;
    cout<<"Enter the no of Vertices in the Undirected Graph :\n";
    cin>>V;
    cout<<"Enter the no of Edges in the Undirected Graph :\n";
    cin>>E;
    
    vector<int> graph[V];
    int a,b;
    for(int i=0;i<E;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }   

    if(dfs(graph,V))
        cout<<"Cycle exists\n";
    else
        cout<<"Cycle doesn't exist\n";
}

