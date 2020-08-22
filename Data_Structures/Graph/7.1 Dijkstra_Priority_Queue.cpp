/*
1) Initialize distances of all vertices as infinite.
2) Create an empty priority_queue pq.  Every item of pq is a pair (weight, vertex). Weight (or distance) is used used as first item  of pair as first item is by default used to compare two pairs
3) Insert source vertex into pq and make its
   distance as 0.
4) While either pq doesn't become empty
    a) Extract minimum distance vertex from pq. 
       Let the extracted vertex be u.
    b) Loop through all adjacent of u and do 
       following for every vertex v.

           // If there is a shorter path to vthrough u. 
           //
           If dist[v] > dist[u] + weight(u, v)
               (i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (ii) Insert v into the pq (Even if v is
                    already there)
               
5) Print distance array dist[] to print all shortest
   paths.
*/
// Program to find Dijkstra's shortest path using priority_queue in STL 
#include<bits/stdc++.h> 

using namespace std; 

// iPair ==> Integer Pair 
typedef pair<int, int> iPair; 

// To add an edge 
void addEdge(vector <pair<int, int> > adj[], int u, 
									int v, int wt) 
{ 
	adj[u].push_back(make_pair(v, wt)); 
	adj[v].push_back(make_pair(u, wt)); 
} 


// Prints shortest paths from src to all other vertices 
void shortestPath(vector<pair<int,int> > adj[], int V, int src) 
{ 
	// Create a priority queue to store vertices that are being preprocessed.  
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 

	// Create a vector for distances and initialize all distances as infinite (INF) 
	vector<int> dist(V, INT_MAX); 

	// Insert source itself in priority queue and initialize its distance as 0. 
	pq.push(make_pair(0, src)); 
	dist[src] = 0; 

	/* Looping till priority queue becomes empty (or all 
	distances are not finalized) */
	while (!pq.empty()) 
	{ 
		// The first vertex in pair is the minimum distance vertex, extract it from priority queue. vertex is stored in 2nd of pair 
        // (it has to be done this way to keep the vertices sorted distance (distance must be first item in pair) 
		int u = pq.top().second; 
		pq.pop(); 

		// Get all adjacent of u. 
		for (auto x : adj[u]) 
		{ 
			// Get vertex label and weight of current adjacent of u. 
			int v = x.first; 
			int weight = x.second; 

			// If there is shorted path to v through u. 
			if (dist[v] > dist[u] + weight) 
			{ 
				// Updating distance of v 
				dist[v] = dist[u] + weight; 
				pq.push(make_pair(dist[v], v)); 
			} 
		} 
	} 

	// Print shortest distances stored in dist[] 
	printf("Vertex Distance from Source\n"); 
	for (int i = 0; i < V; ++i) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

// Driver program to test methods of graph class 
int main() 
{ 
	int V = 9; 
	vector<iPair > adj[V]; 

	// making above shown graph 
	addEdge(adj, 0, 1, 4); 
	addEdge(adj, 0, 7, 8); 
	addEdge(adj, 1, 2, 8); 
	addEdge(adj, 1, 7, 11); 
	addEdge(adj, 2, 3, 7); 
	addEdge(adj, 2, 8, 2); 
	addEdge(adj, 2, 5, 4); 
	addEdge(adj, 3, 4, 9); 
	addEdge(adj, 3, 5, 14); 
	addEdge(adj, 4, 5, 10); 
	addEdge(adj, 5, 6, 2); 
	addEdge(adj, 6, 7, 1); 
	addEdge(adj, 6, 8, 6); 
	addEdge(adj, 7, 8, 7); 

	shortestPath(adj, V, 0); 

	return 0; 
} 

/*  GRAPH :
        (8)  (7)
       1----2----3
  (4) /  (2)|\    \(9) 
     0     8  \(4)  4
   (8)\ (7)/   \   /(10) 
        7----6----5
          (1)  (2)
*/
