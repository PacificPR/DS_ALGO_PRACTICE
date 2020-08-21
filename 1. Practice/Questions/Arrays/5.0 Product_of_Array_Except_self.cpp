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
        
        vector<int> res(nums.size());
        
        vector<int> left_prod(nums.size());     
        vector<int> right_prod(nums.size());   
        left_prod[0] = 1;
        right_prod[nums.size()-1] = 1;
        
        for(int i=1;i<nums.size();i++)//Store left products of each element in one array
            left_prod[i] = nums[i-1]*left_prod[i-1];
        
        for(int i=nums.size()-2;i>=0;i--)//Store right products of each element
            right_prod[i] = nums[i+1]*right_prod[i+1];
        
        for(int i=0;i<nums.size();i++)  //Multiply left and right products
            res[i] = left_prod[i]*right_prod[i];
        
        return res;
    }
};

/*
 Not effecient SPACE COMPLEXITY WISE, as we require 2 extra arrays
*/
