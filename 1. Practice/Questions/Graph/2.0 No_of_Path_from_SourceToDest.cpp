#include<iostream>
#include<vector>

using namespace std;

    int dfs_total_path(vector<vector<int>> graph,int s,int d,vector<bool>& visited){
        if(s == d)
            return 1;
        visited[s]=true;
        int num_path = 0;
        
        for(int i : graph[s]){
            if(visited[i]==false)
                num_path = num_path + dfs_total_path(graph,i,d,visited);
        }
        visited[s]=false;
        return num_path;
    }

    int main(){
        int n,v1,v2;
        int s,d;
        int edge;
        cout<<"Enter number of vertices\n";
        cin>>n;
        vector<bool> visited(n,false);
        vector<vector<int>> graph(n,vector<int>()); //Adjacency list , vector of vectors which store vertex connected to a vertex
        cout<<"Enter number of edges \n";
        cin>>edge;
        cout<<"Enter the pairs \n";
        for(int i=0;i<edge;i++){
            cin>>v1>>v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }   
        cout<<"Enter Source and Destination\n";
        cin>>s>>d;
        cout<<"Number of Path from Source to Destination is " <<dfs_total_path(graph,s,d,visited)<<endl;
    }

