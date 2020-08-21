/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island. 
 
 
Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

 */
#include<iostream>
#include<vector>

using namespace std;


 int islandPerimeter(vector<vector<int>>& grid) {
        //ios_base::sync_with_stdio(nullptr);
        //cin.tie(nullptr);
        //cout.tie(nullptr);
        int p = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    p=p+4;
                    if(j-1>-1&&grid[i][j-1]==1)
                        p=p-2;
                    if(i-1>-1&&grid[i-1][j]==1)
                        p=p-2;
                }
            }
        }
        return p;
  }

 int main(){
     int c,r;
     cout<<"Enter number of rows and columns \n";
     cin>>r>>c;
     cout<<"Enter the grid \n";
     
     vector<vector<int>> grid (r,vector<int>(c) );  //Declaring 2D vector, with r rows having c column each

     //vector<vector<int>> grid (r,vector<int>(c,0) );  To initialize each element with 0

    for(int i = 0; i<r;i++)
        for(int j=0;j<c;j++)
            cin>>grid[i][j];

    cout<<"Perimeter of the island : "<<islandPerimeter(grid)<<endl;

    return 0;

 }
