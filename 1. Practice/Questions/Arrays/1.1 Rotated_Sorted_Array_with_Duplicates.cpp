/* 
            Search in Rotated Sorted Array II

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

*/

#include<iostream>
#include<vector>

using namespace std;

int search(vector<int>& nums,int target){
    int l = 0;
    int h = nums.size();
    int mid; 
    while ( l<=h ){
        while(l<h && nums[l]==nums[l+1])        //Skip duplicates from Left
            l++;
        while(h>l && nums[h]==nums[h-1])        //Skip duplicates from Right
            h--;

        if( nums[mid]==target )
            return true;

        if( nums[l]<=nums[mid] ){ //Means the left side is sorted
            
            if(target>=nums[l] && target<nums[mid]))    //No equality for mid in target checking 
                h = mid-1;
            else
                l = mid+1;
        }

        else{                    //Means the right side is sorted
            
            if(target>nums[mid] && target<=nums[h])     //No equality for mid in target checking 
                l = mid+1;
            else
                h = mid-1;
        }
    }

}

int main(){
    int N;int target;
    vector<int> num;
    cout<<"Enter number of elements in rotated sorted array \n";
    cin>>N;
    cout<<"Enter the numbers  in rotated sorted array \n";
    int tm; 
    for(int i=0;i<N;i++){
        cin>>tm;
        num.push_back(tm);
    }   
    cout<<"Enter the number to find \n";
    cin>>target;
    int r = search(num,target);

    if(r==-1)
        cout<<"Number not found\n";
    else
        cout<<"Number found at index : "<<r<<endl;  // 0-indexed
}




