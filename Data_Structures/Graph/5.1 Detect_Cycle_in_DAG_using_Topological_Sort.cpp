#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> topological_sorting(int numVertex,vector<vector<int>> &graph) {
    vector <int> indegree(graph.size(), 0);
    queue<int> q;
    vector<int> solution;
    
    for(int i = 0; i < graph.size(); i++) {
        for(int j = 0; j < graph[i].size(); j++) { 
            //iterate over all edges
            indegree[ graph[i][j] ]++;
        }
    }
    
    //enqueue all nodes with indegree 0
    for(int i = 0; i < graph.size(); i++) 
    {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    //remove one node after the other
    while(q.size() > 0) {
        int currentNode = q.front();
        q.pop();
        solution.push_back(currentNode);
        for(int j = 0; j < graph[currentNode].size(); j++)
        { 
        //remove all edges
            int newNode = graph[currentNode][j];
            indegree[newNode]--;
            if(indegree[newNode] == 0) 
            { 
            //target node has now no more incoming edges
                q.push(newNode);
            }
        }
    }
    
    return solution;
}
int main() 
{ 
	
	int n,v1,v2;
    int edge;
    cout<<"Enter number of vertices\n";
	cin>>n;

	vector<vector<int>> graph(n,vector<int>()); //Adjacency list , vector of vectors which store vertex connected to a vertex
    cout<<"Enter number of edges \n";
    cin>>edge;
	for(int i=0;i<edge;i++){
        cin>>v1>>v2;
        graph[v1].push_back(v2);
    } 
	
	cout << " Topological Sort of the given graph \n"; 
	vector<int> ans = topological_sorting(n,graph); 
    if(ans.size()==n){
        cout<<"No Cycle Detected: ";
        cout<<"Topological Order : ";
        for(int i:ans)
            cout<<i<<" ";
    }
    else
        cout<<"Cycle Detected\n";

    cout<<endl;
	return 0; 
}

