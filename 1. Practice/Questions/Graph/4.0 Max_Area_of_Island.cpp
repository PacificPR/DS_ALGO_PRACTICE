/*
 
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.
) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]

Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.

*/
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
               
                if(grid[i][j]==1 && visited[i][j]==false){
                   int curr = dfs(grid,visited,i,j); 
                   if(curr>count)
                       count = curr; 
                }    
            }
        }
        return count;
    }
    
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || visited[i][j] || grid[i][j]==0)
            return 0;
        int sum = 1;
        visited[i][j]=true;
        sum = sum + dfs(grid,visited,i+1,j);
        sum = sum + dfs(grid,visited,i-1,j);
        sum = sum + dfs(grid,visited,i,j+1);
        sum = sum + dfs(grid,visited,i,j-1);
        
        return sum;
    }
};
  
    
    int main(){
        vector<vector<int>> grid = {{1,1,1,1,0},
                                     {1,1,0,1,0},
                                     {0,0,1,0,0},
                                     {0,0,0,1,1}};
        Solution s;              
        cout<<"Count : "<<s.maxAreaOfIsland(grid)<<endl;
    }
