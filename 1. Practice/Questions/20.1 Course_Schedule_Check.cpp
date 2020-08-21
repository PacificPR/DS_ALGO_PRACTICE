/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses,vector<int>());
        int ans=0;
        vector<int> indegree(numCourses,0);
        
        for(auto i:prerequisites){          //Creating a graph uv, v depends on u, so u has to be completed before v
            graph[i[1]].push_back(i[0]);    
            indegree[i[0]]++;               //Storing the indegree of each vertices, so we can start the topological sort with verix of indegree 0
        }
        
        queue<int> q;                       //
        
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans++;
            
            for(int i:graph[curr]){
                indegree[i]--;
                if(indegree[i]==0)
                    q.push(i);
            }
        }
        if(ans==numCourses)
            return true;
        return false;
    }
};

/* USING KAHN'S ALGORITHM HERE  : ******************************
Kahn's algorithm</h2>
Let's see how we can find a topological sorting in a graph.
The algorithm is as follows :

Step1: Create an adjacency list called graph   

Step2: Call the topological_sorting() function  
    Step2.1: Create a queue and an array called indegree[]
    Step2.2: Calculate the indegree of all vertices by traversing over graph
    Step2.3: Enqueue all vertices with degree 0 

Step3: While the queue is not empty repeat the below steps  
    Step3.1: Dequeue the element at front from the queue and push it into the solution vector
    Step3.2: Decrease the indegree of all the neighbouring vertex of currently dequed element ,if indegree of any neigbouring vertex becomes 0 enqueue it.
    Step3.3: Enqueue all vertices with degree 0.

Step4: If the queue becomes empty return the solution vector.

Step5: Atlast after return from the topological_sorting() function, print contents of returned vector.
*/
