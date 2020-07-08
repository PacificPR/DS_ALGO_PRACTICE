/* Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
   Find all unique triplets in the array which gives the sum of zero.
*/

    #include<bits/stdc++.h>
    
    using namespace std;

    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> sol;
        vector<vector<int>> fin;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            int j = i+1;
            int k = n-1; while(j<k){
                int csum = nums[i]+nums[j]+nums[k]; 
                if(csum==0){
                    vector<int>trip(3);
                    trip[0]=nums[i];
                    trip[1]=nums[j];
                    trip[2]=nums[k];
                    sol.insert(trip);
                    while(j<k && nums[j]==trip[1]){
                        j++;
                    }
                    while(k>j && nums[k]==trip[2]){
                        k--;
                    }
                    
                }
                else if(csum<0){
                    j++;
                }
                else
                    k--;
            }
        }
        for(auto x:sol)
            fin.push_back(x);
        return fin;
    }

    int main(){
        int n;
        vector<int> nums;
        cout<<"Enter the elements in array\n";
        cin>>n;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            nums.push_back(temp);
        }
        vector<vector<int>> triplets = threeSum(nums);
        cout<<"Unique Triplets with sum 0 : \n";
        for(int i=0;i<triplets.size();i++)
            cout<<triplets[i][0]<<","<<triplets[i][1]<<","<<triplets[i][2]<<" \n";
        return 0;
    }
