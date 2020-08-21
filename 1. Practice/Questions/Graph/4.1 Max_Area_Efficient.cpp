/* Here we make changes to the original grid, 
   once we visit a node 1, turn it to 0 so that it is not included in another path
 
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0 || grid[0].size()==0) return 0;
        int island = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    int current = 0;
                    dfs(grid,i,j,current);
                    island = max(island,current);
                }
            }
        }
            return island;
    }
    
    void dfs(vector<vector<int>>& grid,int i,int j,int& current){
       if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1) return;
        current+=1;
        grid[i][j]=0;
        dfs(grid,i+1,j,current);
        dfs(grid,i-1,j,current);
        dfs(grid,i,j+1,current);
        dfs(grid,i,j-1,current);
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
