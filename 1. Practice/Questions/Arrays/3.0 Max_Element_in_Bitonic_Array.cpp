/*
    A bitonic array is a array in which elements are first increasing and then decreasing. 
    A strictly increasing or strictly decreasing array is also considered as bitonic array.
*/

#include <bits/stdc++.h> 
using namespace std; 

int findMaximum(int arr[], int low, int high) 
{ 
	while(low<=high){
      
      int mid = low + (high-low)/2;

      if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
        return arr[mid];
      
      if(arr[mid]>arr[mid-1])
        low = mid+1;
      else
        high = mid-1;
      
    }
  return 0;
} 

int main() 
{ 
	int arr[] = {1, 3, 50, 10, 9, 7, 6}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "The maximum element is " << findMaximum(arr, 0, n-1); 
	return 0; 
} 


/*
 This problem is similar to finding peak element
*/
