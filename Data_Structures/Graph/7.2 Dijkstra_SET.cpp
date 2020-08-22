/*
    INSTEAD OF PRIORITY QUEUE WE CAN USE SET.
        REASONS:
            * WE DON'T NEED VISITED ARRAY TO MARK IF VERTEX IS VISITED OR NOT BEFORE ADDING IT TO THE SET , AS SET WON'T ALLOW DUPLICATE ENTRY 
            * SHORTER AND CLEANER CODE AS COMPARED TO MIN_HEAP OR PRIORITY_QUEUE
    What is the best for Dijkstra's algorithm: 
    Set with erasing of the vertices adjacent to the current one and the subsequent insertion of them with the new values 
                OR
    a priority_queue with a lot of irrelevant vertices? Or maybe some other approach using std?         

    NOT MUCH DIFFERENCE AS PER CODEFORECES DISCUSSION : https://codeforces.com/blog/entry/47233

    TIME COMPLEXITY : O(ElogV)   as priority_Q implementation
*/
#include<iostream>
#include<vector>
#include<limits>
#include<set>

using namespace std;

void dijkstra(vector< pair< int,int> > adj[],int s,int V){
    int dist[V];  // dist[i] WILL STORE MINm DIST FROM s to i
    fill(dist,dist+V,INT32_MAX);    //FILL EVERY DIST WITH INFINITY BY DEFAULT
    dist[s] = 0;  //Set dist for source as 0
    set<pair<int,int>> djk; //Set will store pair of {dist,vertex}, by default set stores minm as first element in case of nos, and for pairs, 1st element is considered
    djk.insert({dist[s],s});//Insert the source dist and source node as pair in the set
    
    while(!djk.empty()){    //While the set is not empty
        int u = djk.begin() -> second;  //Get the current vertex from the first pair, which has minm dist and is in the beginning
        djk.erase(djk.begin());    //Remove this pair from the set

        for(auto v : adj[u]){   //Traverse all the neighbouring vertices , which are in pairs in adjacency list
            if(dist[v.first] > dist[u]+v.second){   //If curr dist to adj vert is greater than the dist to parent u + weight of edge from u to adj vert
            //UPDATE THE ARRAY WITH SHORTER DISTANCE AND THE SET WITH DIST AND VERTEX 
                djk.erase({dist[v.first],v.first}); //ERASING OLD DIST PAIR
                dist[v.first] = dist[u] + v.second; //UPDATING DIST ARRAY
                djk.insert({dist[v.first],v.first});//UPDATING SET WITH DIST AND VERT PAIR
            }
        }
    }

    for(int i=0;i<V;i++)
        cout<<"Shortest Distance of "<<i <<" from  "<<s<<"  is : "<<dist[i]<<"\n";
}

int main(){
    int V,E;
    cout<<"Enter number of vertices and edges in graph\n";
    cin>>V>>E;
    vector< pair<int,int> > adj[V]; //Array of Pair of vertex and weight,corresponging vertex in the edge i.e. adj[u]->{v,w} for edge uv of weight w
    cout<<"Enter the vertices in edges with weight\n";
    int u,v,w;
    for(int i=1;i<=E;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int s;
    cout<<"Enter the source for which shortest dist to every other vertex is to be found : ";
    cin>>s;
    dijkstra(adj,s,V);
}

/* DETAILED EXPLAINATION :  

void dijkstra(int v){
    fill(d,d + n, inf);//fill entries with some big value
    d[v] = 0;//distance from starting vertex to starting vertex is zero
    int u;
    set<pair<int,int> > s;//a set of pairs(read the tutorial to understand this part)

     priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;
     by default the priority queue is a max-heap.since we need a min-heap we use the inbuilt-function "greater" 

    s.insert({d[v], v});// insert the starting vertex in the set 
    // set maintains the elements in increasing order
    // That's why we did s.insert({d[v],v}); and not s.insert({v,d[v]});
    // by default the pairs are sorted by the first value (if the first values are equal then by the second value)
    / In the priority_queue we'll do Q.push({d[v],v});
    // FYI "{}" notation is the same as make_pair notation you would have read about .
    // so s.insert(make_pair(a,b)) is equivalent to s.insert({a,b});
    while(!s.empty()){//terminate when the set is empty 
    /same for the queue while(!Q.empty())/
        u = s.begin() -> second;// s.begin() basically is a pointer to the first entry in the set(one with the minimum d[v] value) 
        // Oh and you can access the pair elements like this 
        // pair<int,int> p = {a,b};
        // int x = p.first //first entry of the pair
        //int y = p.second; //second entry of the pair
        // so u basically is the second entry of the pair (vertex with minimum d[] value )
        /u = Q.top().second for the priority_queue/
        s.erase(s.begin());//remove this entry from the set
        /for priority_queue Q.pop();/
        for(auto p : adj[u]) //adj[v][i] = pair(vertex, weight)
        // adj[u] is a vector of pairs
        // so to iterate a vector of pairs the iterator should be a pair (p is a pair here )
        // this is equivalent to for(pair<int,int>::iterator it = adj[u].begin();it!=adj[u].end();it++)
        // see how much shorter the code becomes if you use auto keyword :D
        // It's very useful if you have something complex to iterate like pair<string,pair<int,pair<int,int>>> :P
            if(d[p.first] > d[u] + p.second){// p.first is the distance (remember we pushed {d[v],v}) ?!, p.second is the vertex
                s.erase({d[p.first], p.first});// we found a shorter distance to the vertex p.first
                // we need to update it 
                // for updating in set , remove the old entry , insert the new entry 
                d[p.first] = d[u] + p.second;//update the distance to this node 
                s.insert({d[p.first], p.first});//insert new entry (new distance to the vertex)
                /for priority_queue we would have just pushed the new entry Q.push({d[p.first], p.first})/
            }
    }
}
P.S : for priority_queue we would need to additionally maintain an array visited[] to keep track of nodes we have already pushed to the queue.

We don't need this in set as set inserts a new entry only if it doesn't exist already */
