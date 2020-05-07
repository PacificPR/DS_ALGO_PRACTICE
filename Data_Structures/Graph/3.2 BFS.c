// Breadth-first search (BFS) is an algorithm for traversing or searching tree or graph data structures. 
// It starts at the tree root (or some arbitrary node of a graph, sometimes referred to as a 'search key'[1]), 
// and explores all of the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level.
// The time complexity can be expressed as O (|V|+|E| )
// since every vertex and every edge will be explored in the worst case. 
// |V| is the number of vertices and |E| is the number of edges in the graph. 
// Note that O(|E|) may vary between  O(1) and O (|V|^2 ) 
// depending on how sparse the input graph is.
// 
// ************** TIME COMPLEXITY ********************
// The time complexity can be expressed as O (|V|+|E| )
//
//****DATA STRUCTURRE USED ********
// Queue 
// 
// SIMILAR TO LEVEL ORDER TRAVERSAL IN TREE
//
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL){
        printf("Queue is full\n");
        exit(0);
    }
    t->data=x;
    t->next=NULL;

    if(front==NULL){
        rear=front=t;
    }
    else{
        rear->next=t;
        rear=t;
    }
}

int dequeue(){
    int x=-1;
    struct node* t; //For freeing the space of the deleted node
    if(front==NULL)
        printf("Queue is empty\n");
    else{
        t=front;
        x=front->data;
        front=front->next;
        free(t);
    }
    return x;
}

int isEmpty(){
    if(front==NULL)
        return 1;
    else
        return 0;
        //front==NULL is a condition and will give either true(non-zero value) or false(0)
}

void BFS(int u,int G[][5],int n){ //****For a multidimentsional array,first dimension does not have to be specified. The second (and any subsequent) dimensions must be given,so it would vary with nodes
   int visited[5]={0};
   int v,i;
   printf("BFS FOR THIS GRAPH :  ");
   printf("%d  ",u);
   visited[u]=1;
   enqueue(u);
   while(!isEmpty()){
        v=dequeue();
        for(i=1;i<=n;i++){
            if(G[v][i]==1&&visited[i]==0){
                printf("%d ",i);
                visited[i]=1;
                enqueue(i);
            }
        }
   }
}

void main(){
    int n,i,j;
    int node=4;
    int G[node+1][node+1];
   /* printf("Enter number of nodes\n");
    scanf("%d",&n);
    G=(int **)malloc((n+1)*sizeof(int *)); //Allocating space for array of pointers
    for(i=0;i<=n;i++)
        G[i]=(int *)malloc((n+1)*sizeof(int));Allocating space for each row 
*/
    printf("Enter the adjacency Matrix of node 4 \n");

    for(i=1;i<=node;i++)
        for(j=1;j<=node;j++)
                scanf("%d",&G[i][j]);

    printf("Enter the starting vertex\n");
    scanf("%d",&i);
    BFS(i,G,node);

}
//CHANGE THE NODES as per required and G in BFS formal parameter
