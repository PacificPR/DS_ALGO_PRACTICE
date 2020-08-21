/*
 
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        
        int final_max = nums[0];
        // iMax/iMin stores the Max/Min product of subarray that ends with the current number nums[i]
        int iMax = nums[0],iMin = nums[0];
        for(int i=1;i<nums.size();i++){
        // multiplied by a negative makes big number smaller, small number bigger so we redefine the extremums by swapping them
        // As now iMax will store Minm value if it won't be swapped
           if(nums[i]<0)
               swap(iMax,iMin);
        // max/min product for the current number is either the current number itself or the max/min by the previous number multiplied by the current one
            iMax = max(nums[i],iMax*nums[i]);
            iMin = min(nums[i],iMin*nums[i]);

        // the newly computed max value is a candidate for our global result
            final_max = max(iMax,final_max);
        }
        return final_max;
    }
};
