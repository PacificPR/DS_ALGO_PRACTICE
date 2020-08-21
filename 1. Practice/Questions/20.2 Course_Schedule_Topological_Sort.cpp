/*
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] . 
*/


#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) 
    {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> graph(numCourses,vector<int>());
        vector<int> ans;
        
        //Graph Creation and Indegree Calculation
        for(auto &it : pre)
        {
            graph[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        
        
        queue<int> q;
        
        // queueing up the courses with no pre-requisites
        for(int i=0;i<indegree.size();i++)
            if(indegree[i] == 0)
                q.push(i);
        
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);        // Taking this course whose pre-requisites are already full filled
            for(int i : graph[curr])
            {
                indegree[i]--;          // since we took curr course
                if(indegree[i] == 0)    // if all pre-requisites are full filled then queue it up
                    q.push(i);
            }
        }
        if(ans.size() == numCourses)    // if all the courses have been taken
            return ans;
        return vector<int>();           // else returning empty vector
    }
};
