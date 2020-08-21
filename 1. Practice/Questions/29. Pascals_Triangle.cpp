#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    if(numRows==0)            
        return vector<vector<int>>();
        
    vector<vector<int>> Tri(numRows,{1}); //Create a vector of vectors, with each row initialized with 1, so that 1 is the starting
        
    for(int i=1;i<numRows;i++){
        for(int j=1;j<i;j++){
            Tri[i].push_back(Tri[i-1][j-1]+Tri[i-1][j]);  //Previous rows 1st and 2nd corresponding element added to the current row
        }
        Tri[i].push_back(1); //Every row Ended with 1
    }
    return Tri;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> res = generate(n);
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}
