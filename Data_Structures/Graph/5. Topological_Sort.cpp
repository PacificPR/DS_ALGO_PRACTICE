/*  Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering.
    Topological Sorting for a graph is not possible if the graph is not a DAG.
For example, a topological sorting of the following graph is “5 4 2 3 1 0”. There can be more than one topological sorting for a graph.
For example, another topological sorting of the following graph is “4 5 2 3 1 0”.

$$$$$$ The first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges).

 For instance, the vertices of the graph may represent tasks to be performed, and the edges may represent constraints that one task must be performed before another;
 in this application, a topological ordering is just a valid sequence for the tasks.
 A topological ordering is possible if and only if the graph has no directed cycles, that is, if it is a directed acyclic graph (DAG). 

######### APPLICATION :

Build systems :

Consider a source code structure where you are building several libraries (DLLs) and they have dependencies on each other. For example, to build dll A, you must have built DLLs B, C an D (Maybe you have a reference of B,C and D in the project that builds A).
Let's mark a dependency edge from each of B, C and D to A implying that A depends on the other three and can only be built once each of the three are built. Technically speaking, (u,v) => An edge from u to v implies v.dll can be built only when u.dll is already built.
After constructing a graph of these dlls and dependency edges, you can conclude that a successful build is possible iff the resulting graph is acyclic (Ignoring advanced ways of resolving cyclic dependencies like asmmeta [1] files). How does the build system decide in which order to build these dlls? It sorts them topologically.
Therefore, in an order like X->Z->T->B->D->C->A, it can start building X (which may only depend on external assemblies already built), then follow the topologically sorted list of assemblies.

*/

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
            //iterate over all edges, and store their indegrees 
            indegree[ graph[i][j] ]++;
        }
    }
    
    //enqueue all nodes with indegree 0 , as topological order starts with 
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

