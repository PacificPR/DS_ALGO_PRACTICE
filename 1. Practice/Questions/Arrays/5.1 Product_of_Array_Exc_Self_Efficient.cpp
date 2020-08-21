/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]

*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()==0)
            return vector<int>();
        
        vector<int> res(nums.size(),1);
        
        res[0] = 1;
        for(int i=1;i<nums.size();i++)      //Computing left product in the res array
            res[i] = nums[i-1]*res[i-1];
        
        int x = nums[nums.size()-1];        //For computing right product , this variable is updated with right products

        for(int i=nums.size()-2;i>=0;i--){  //Computing right_product
            res[i] = x*res[i];
            x = x*nums[i];                  //Multiplying right numbers , so later on we can multiply it with left_product in res
        }
        
        return res;
    }
};

// DOESN'T REQUIRE EXTRA SPACE 
