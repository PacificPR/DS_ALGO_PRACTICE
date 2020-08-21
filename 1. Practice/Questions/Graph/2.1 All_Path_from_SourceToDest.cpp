#include<iostream>
#include<vector>

using namespace std;

vector<int> Paths(vector<vector<int>> graph,int s,int d){
    
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
    cout<<" Paths from Source to Destination is " <<dfs_total_path(graph,s,d,visited)<<endl;
}  



