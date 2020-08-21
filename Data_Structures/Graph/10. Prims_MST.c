//********************** Algorithm
//1) Create a set mstSet that keeps track of vertices already included in MST.
//2) Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE. Assign key value as 0 for the first vertex so that it is picked first.
//3) While mstSet doesn’t include all vertices
//….a) Pick a vertex u which is not there in mstSet and has minimum key value.
//….b) Include u to mstSet.
//….c) Update key value of all adjacent vertices of u. To update the key values, iterate through all adjacent vertices. 
//For every adjacent vertex v, if weight of edge u-v is less than the previous key value of v, update the key value as weight of u-v

//********************** PRIMS *************************
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

#define V 5

int minkeyindex(int k[V],bool mset[V]){
    int min=INT_MAX;
    int mindex;
    int i;
    for(i=0;i<V;i++){
        if(mset[i]==false&&k[i]<min){
            min=k[i];
            mindex=i;
        }
    }
    return mindex;
}

void printMST(int parent[],int graph[V][V],int key[]){
    int i,cost=0;
    printf("Edge\tWeight\n");
    for(i=1;i<V;i++){
        printf("%d -> %d\t%d\n",parent[i],i,graph[parent[i]][i]);
        cost=cost+key[i];
    }
    printf("\nMINIMUM COST = %d\n",cost);
}

void primMST(int G[V][V]){
    int parent[V];
    int key[V];
    bool mstset[V];
    int u,i,j;

    for(i=0;i<V;i++){
        key[i]=INT_MAX;
        mstset[i]=false;
    }

    key[0]=0;
    parent[0]=-1;
    
    for(i=0;i<V;i++){
        u=minkeyindex(key,mstset);
        mstset[u]=true;
        
        for(j=0;j<V;j++)
            if(G[u][j] && mstset[j]==false && G[u][j]<key[j]){
                key[j]=G[u][j];
                parent[j]=u;
            }
        }
    printMST(parent,G,key);
}


void main(){
 int graph[V][V] =      { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };  
 primMST(graph);
} 
//**********************
//Time Complexity of the above program is O(V^2). 
//If the input graph is represented using adjacency list, 
//then the time complexity of Prim’s algorithm can be reduced to O(E log V) with the help of binary heap.
//**********************

