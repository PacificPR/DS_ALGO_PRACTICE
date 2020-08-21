/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        
        vector<vector<bool>> visited((int)grid.size(),vector<bool>(grid[0].size(),false));  //Keep track of visited nodes, so that we don't visit it again in some other island
        int count = 0;
     
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1' && visited[i][j]==false){    //Check every node if it is land and it wasn't visited befor
                    count++;                        
                    DFS(grid,visited,i,j);                      //Perform DFS on it, and mark all it's connected neighbours
                }   
            }   
        }
        return count;
    }
    
    void DFS(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || visited[i][j]==true || grid[i][j]=='0') //Check if it's withing boundary, it's not visited and it's not 0
            return;
        visited[i][j]=true;     //Mark it as visited
            
        // Perfrom DFS in all 4 direction to count all connected component as 1
        DFS(grid,visited,i+1,j);
        DFS(grid,visited,i-1,j);
        DFS(grid,visited,i,j+1);
        DFS(grid,visited,i,j-1);
    }
};

    int main(){
        vector<vector<char>> grid = {{'1','1','1','1','0'},
                                     {'1','1','0','1','0'},
                                     {'0','0','1','0','0'},
                                     {'0','0','0','1','1'}};
        Solution s;
        cout<<"Count : "<<s.numIslands(grid)<<endl;
        
    }
