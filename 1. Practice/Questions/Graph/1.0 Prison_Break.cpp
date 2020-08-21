/*
Alfie was a prisoner in mythland. Though Alfie was a witty and intelligent guy.He was confident of escaping prison.
After few days of observation,He figured out that the prison consists of (N*N) cells.i.e The shape of prison was (N*N) matrix.
Few of the cells of the prison contained motion detectors.So Alfie planned that while escaping the prison he will avoid those cells containing motion detectors.
Yet before executing his plan,Alfie wants to know the total number of unique possible paths which he can take to escape the prison.Initially Alfie is in cell
(1,1) while the exit of the cell (N*N).

note:->Alfie can move in all four direction{ if his current location is (X,Y), he can move to either
(X+1,Y), (X-1,Y), (X,Y+1), (X,Y-1) }. If the first cell (1,1) and the last cell(N*N) contain motion detectors,then Alfie can't break out of the prison.

INPUT:

The first line contain number of test cases "T".T test cases follow.The first line of each test case contains an integer "N",(i.e the size of the (N*N) matrix).The next n lines contain N space separated values either 0 or 1."1" represents a cell containing motion detectors.

OUTPUT:

output total number of unique possible paths which he can take to escape the prison.

SAMPLE INPUT            SAMPLE OUTPUT
3                           2
4                           4
0 1 1 0                     4
0 0 1 0 
0 0 0 0 
0 1 1 0 
4
0 0 0 1 
0 0 0 0 
1 1 1 0 
1 0 0 0 
4
0 1 1 0 
0 0 1 1 
0 0 0 0 
0 1 0 0 

*/
#include<iostream>
#include<vector>

using namespace std;
int N,count_path;
int cell[20][20];
int mark[20][20];

void dfs_path(int i,int j){
    if(i==N-1 && j==N-1){   //The Base condition
        count_path++;
        return;
    }
    	mark[i][j] = 1;     //Mark this as visited node
        //For all possible 4 directions, check if it's within the boundary,
        //there's no sensor and it's not visited before in the same path
    if( (i+1)<N && mark[i+1][j] == 0 && cell[i+1][j] == 0 )     
		dfs_path(i+1,j);
	if( (j-1)>=0 && mark[i][j-1] == 0 && cell[i][j-1] == 0 )
		dfs_path(i,j-1);
	if( (j+1)<N && mark[i][j+1] == 0 && cell[i][j+1] == 0 )
		dfs_path(i,j+1);
	if( (i-1)>=0 && mark[i-1][j] == 0 && cell[i-1][j] == 0 )
		dfs_path(i-1,j);
	mark[i][j] = 0;         //Unmark it , as it can be used in another path 
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>cell[i][j];
                mark[i][j]=0;
            }
        }
            count_path = 0;
            dfs_path(0,0);
            cout<<count_path<<"\n";
        
    }
}
