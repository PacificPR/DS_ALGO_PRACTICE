/*
    SEARCH IN A ROTATED SORTED ARRAY : 

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

Your algorithm's runtime complexity must be in the order of O(log n).

*/


#include<iostream>
#include<vector>

using namespace std;

int search(vector<int>& nums,int target){
    int l = 0;
    int h = nums.size();
    int mid; 
    while ( l<=h ){
       mid = (l+h)/2;

                                                    //Two possiblity if left half is sorted or right half
       if(nums[mid] == target)
           return mid;

       if( nums[l] <= nums[mid] ){                 //This means left half is sorted
           //So perform binary search in left half
            if( target >= nums[l] && target<nums[mid])  //No equality for mid in target checking
                h = mid-1;
            else
                l = mid+1;
       }
        
       else{                                      //This means right half is sorted

           //Perform binary search in right half
           if( target>nums[mid] && target<nums[h])   //No equality for mid in target checking 
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


