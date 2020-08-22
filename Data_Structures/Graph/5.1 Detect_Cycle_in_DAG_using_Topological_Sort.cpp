/*
#####   Kahn’s algorithm for Topological Sorting

Algorithm: Steps involved in finding the topological ordering of a DAG:
Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.

Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)

Step-3: Remove a vertex from the queue (Dequeue operation) and then.
        A. Increment count of visited nodes by 1.
        B. Decrease in-degree by 1 for all its neighboring nodes.
        C. If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.

Step 4: Repeat Step 3 until the queue is empty.

Step 5: If count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph.

#### Complexity Analysis:

$$$$$ Time Complexity: O(V+E).
The outer for loop will be executed V number of times and the inner for loop will be executed E number of times.

$$$$$ Auxillary Space: O(V).
The queue needs to store all the vertices of the graph. So the space required is O(V)

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int topological_sorting(int numVertex,vector<vector<int>> &graph) {
    vector <int> indegree(graph.size(), 0);
    queue<int> q;
    //vector<int> solution;
    int count = 0;   
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
        count++;
        //solution.push_back(currentNode);
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
    
    return count;
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
    if(count==n){
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

