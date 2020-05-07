// Depth-first search (DFS) is an algorithm for traversing or searching tree or graph data structures. 
// The algorithm starts at the root node (selecting some arbitrary node as the root node in the case of a graph) 
// and explores as far as possible along each branch before backtracking. 
//
//
// Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph
// Data Structure can be used : STACK
//
// SIMILAR TO PREORDER TRAVERSAL IN TRESS
//


#include<stdio.h>
#include<stdlib.h>

void DFS(int i,int G[][7],int n){
    int j;
    static int visited[7]={0};
    if(visited[i]==0){
        printf("%d ",i);
        visited[i]=1;
        for(j=1;j<=n;j++){
           if(G[i][j]==1&&visited[j]==0)
               DFS(j,G,n);
        }
    }
}

void main(){
    int n,i,j;
    int node=6;
    int G[node+1][node+1];

    printf("Enter the adjacency Matrix of node 4 \n");

    for(i=1;i<=node;i++)
        for(j=1;j<=node;j++)
                scanf("%d",&G[i][j]);

    printf("Enter the starting vertex\n");
    scanf("%d",&i);
    DFS(i,G,node);

}
//CHANGE THE NODES as per required and G in DFS formal parameter
