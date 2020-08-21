/* TO DETECT CYCLE IN A DIRECTED GRAPH : 
 *      1. DFS
 *      2. TOPOLOGICAL SORT
 *      3. BFS
*/

#include<iostream>
#include<vector>


using namespace std;


bool isCyclicDFS_util(vector<int> adj[],vector<bool> visited,int curr){
    if(visited[curr])       //IF the node is already visited, it contains cycle
        return true;

    visited[curr] = true;   //Else set it to visited

    for(int u : adj[curr]){ //Explore neighbour and perform DFS
        if(isCyclicDFS_util(adj,visited,u))
            return true;
    }
    return false;
    
}

bool isCyclicDFS(vector<int> adj[],int V){
    
    vector<bool> visited(V,false);  //Make a visited vector to keep track of visited elements
    
    for(int i=0;i<V;i++){
        visited[i]=true;            //For each node first set it to visited
        //Explore all it's neighbour using isCuclicDFS_util( which performs dfs
        
        for(int d : adj[i]){
            if(isCyclicDFS_util(adj,visited,d))
                return true;
        }
        visited[i]=false;
        //While returning mark this node as not visited
    }
    return false;
}

int main(){
    int V,E;
    cout<<"Enter the no of Vertices in the directed Graph :\n";
    cin>>V;
    cout<<"Enter the no of Edges in the directed Graph :\n";
    cin>>E;
    
    vector<int> graph[V];
    int a,b;
    for(int i=0;i<E;i++){
        cin>>a>>b;
        graph[a].push_back(b);
    }

    if(isCyclicDFS(graph,V))
        cout<<"Cycle exists\n";
    else
        cout<<"Cycle doesn't exist\n";

}
/*
Complexity Analysis:
Time Complexity: O(V+E).
Time Complexity of this method is same as time complexity of DFS traversal which is O(V+E).
Space Complexity: O(V).
To store the visited and recursion stack O(V) space is needed.
*/
