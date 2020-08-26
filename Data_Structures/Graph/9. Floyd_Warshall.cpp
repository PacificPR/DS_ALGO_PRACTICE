/*
                            #############  Floyd Warshall Algorithm #########

The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem.
The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph. 

This algorithm works for both the directed and undirected weighted graphs.
But, it does not work for the graphs with negative cycles (where the sum of the edges in a cycle is negative).

####### Floyd Warshall Algorithm Complexity

##### Time Complexity
There are three loops. Each loop has constant complexities. So, the time complexity of the Floyd-Warshall algorithm is O(n3).

##### Space Complexity
The space complexity of the Floyd-Warshall algorithm is O(n2).

##### Floyd Warshall Algorithm Applications
    To find the shortest path is a directed graph
    To find the transitive closure of directed graphs
    To find the Inversion of real matrices
    For testing whether an undirected graph is bipartite

        ##########  ALGORITHM : #################

Floyd-Warshal()
	d[v][u] = inf for each pair (v,u)
    d[v][u] = set weight for the ege vu

	d[v][v] = 0 for each vertex v

	for k = 1 to n
		for i = 1 to n
			for j = 1 to n
				d[i][j] = min(d[i][j], d[i][k] + d[k][j])   //ij, ik+kj

Time complexity : O(n 3).
*/

#include <iostream>
using namespace std;

// defining the number of vertices
#define nV 4

#define INF 9999

void printMatrix(int matrix[][nV]);

// Implementing floyd warshall algorithm
void floydWarshall(int graph[][nV]) {
  int matrix[nV][nV], i, j, k;

  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      matrix[i][j] = graph[i][j];

  // Adding vertices individually
  for (k = 0; k < nV; k++) {
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix);
}

void printMatrix(int matrix[][nV]) {
  for (int i = 0; i < nV; i++) {
    for (int j = 0; j < nV; j++) {
      if (matrix[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int graph[nV][nV] = {{0, 3, INF, 5},
             {2, 0, INF, 4},
             {INF, 1, 0, INF},
             {INF, INF, 2, 0}};
  floydWarshall(graph);
}
