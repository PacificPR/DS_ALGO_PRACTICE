class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        if(h==0)
            return 0;
        if(h==1)
            return nums[0]>nums[1]?0:1;
        
        int mid = 0;
        while(l<=h){
            
            mid = l+(h-l)/2;
            if(mid==0)          //If mid comes to the first element, check if 1st is greater or 2nd
                return nums[0]>nums[1]?0:1;

            if(mid==nums.size()-1)  //If mid is last element, check if last or 2nd last element is greater
                return nums[nums.size()-1]>nums[nums.size()-2]?nums.size()-1:nums.size()-2;
            
            //If mid is greater than both it's neighbour then , mid is peak
            if( nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1] )
                return mid;

            //If mid-1 element is greater that means left side has a chance of getting peak, so change h position towards left side
            if( nums[mid-1]>nums[mid])
                h = mid-1;
            //Else mid+1 element is greater that means right side has a chance of getting peak value, so change l position towards right side
            else
                l = mid+1;
        }
        return mid;
    }
};
