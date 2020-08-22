/* This one is more effecient in terms of memory and speed
   But the original grid is changed for this
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
     int numIslands(vector<vector<char>> grid) {
        
        int ans = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    ans++;
                    callDFS(grid, i, j);
                }
                
            }
        }
        
        return ans;
}
    
    
    void callDFS(vector<vector<char>>& grid, int i, int j){
        
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == '0'){
            return;
        }
        
        grid[i][j] = '0';
        callDFS(grid,i+1,j);  // down
        callDFS(grid,i-1,j);  // up
        callDFS(grid,i,j+1);  // right
        callDFS(grid,i,j-1);  // left
        
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
