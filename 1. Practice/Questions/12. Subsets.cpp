//  Given a set of distinct integers, nums, return all possible subsets (the power set).


#include<iostream>
#include<vector>

using namespace std;


vector<vector<int>> subset(vector<int>& nums){
    int N = nums.size();
    vector<vector<int>> result;
    if(N==0)
        return result;
    
    for(int i=0; i<(1<<N);i++){ //To form 2^N subsets
        vector<int> temp;       //temp vector for each new subset
        for(int j=0;j<N;j++){
            if(i&(1<<j))        //Checking if jth bit is on,then correspoding number is pushed in the subset
                temp.push_back(nums[j]);
        }
        result.push_back(move(temp));//std::move is used to transfer data from one object to another
        //Here, we are moving subset from temp to final result
    }
    return result;
}

int main(){
    int n;
    vector<int> nums;
    cout<<"Enter the size of Set\n";
    cin>>n;
    cout<<"Enter the numbers in Set\n";
    int input;
    while((n--)&&cin>>input)
        nums.push_back(input);
    cout<<"The subsets are : \n";
    vector<vector<int>> sub = subset(nums);
    for(int i=0;i<sub.size();i++){
        cout<<"{";
        for(int j=0;j<sub[i].size();j++){
            cout<<sub[i][j]<<",";
        }
        cout<<" }\n";
    }
}
