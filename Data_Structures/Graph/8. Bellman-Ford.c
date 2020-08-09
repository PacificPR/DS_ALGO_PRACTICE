// Algorithm
// Following are the detailed steps.

// Input: Graph and a source vertex src
// Output: Shortest distance to all vertices from src.
// If there is a negative weight cycle, then shortest distances are not calculated, negative weight cycle is reported.


// 1) This step initializes distances from the source to all vertices as infinite and distance to the source itself as 0.
// Create an array dist[] of size |V| with all values as infinite except dist[src] where src is source vertex.

// 2) This step calculates shortest distances.
// Do following |V|-1 times where |V| is the number of vertices in given graph.
// …..a) Do following for each edge u-v
// ………………If dist[v] > dist[u] + weight of edge uv, then update dist[v]
// ………………….dist[v] = dist[u] + weight of edge uv

// 3) This step reports if there is a negative weight cycle in graph.
// Do following for each edge u-v
// ……If dist[v] > dist[u] + weight of edge uv, then “Graph contains negative weight cycle”
// The idea of step 3 is, step 2 guarantees the shortest distances if the graph doesn’t contain a negative weight cycle. If we iterate through all edges one more time and get a shorter path for any vertex, then there is a negative weight cycle
 
// 1) Negative weights are found in various applications of graphs.
// For example, instead of paying cost for a path, we may get some advantage if we follow the path.

// 2) Bellman-Ford works better (better than Dijksra’s) for distributed systems.
// Unlike Dijkstra’s where we need to find the minimum value of all vertices, in Bellman-Ford, edges are considered one by one.
//
