/* 
 * Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]

*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = nums[0];
        for(int i=1;i<nums.size();i++){
            xr = xr^nums[i];                    //Find XOR of all the numbers first, this is eventually the xor of the two unique numbers,
                                                //As A^A = 0, so all duplicate numbers are eliminated                                       
        }
        
        int rmsb = xr&(~(xr-1));                //Find right most set bit in that XOR value,this bit must be 1 in one of the unique numbers and 0 in another unique number 
                                                // Cause 1^0 = 0^1 = 1 , hence we need to find two groups which has 1 set at that position and 0 in another
        int x=0,y=0;
        for(int i=0;i<nums.size();i++){
            if(rmsb&nums[i])                    //Divide the numbers in two groups 
                x=x^nums[i];                    //x contains all number whose rmsb bit is 1
            else
                y=y^nums[i];                    //y contains all numbers whose rmsb bit is 0
        }
                                //Other than the unique numbers, all duplicate are removed as they are XORed 
        vector<int> res = {x,y};
        return res;
    }
};
