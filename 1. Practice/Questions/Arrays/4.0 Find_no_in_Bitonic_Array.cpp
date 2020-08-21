/*
       FIRST FIND THE PEAK POINT
    
       THEN WE CAN DIVIDE THE ARRAY INTO TWO, ONE ASCENDING BEFORE THE PEAK AND THEN DESCENDING AFTER THE PEAK

       PERFORM THE ASCENDING AND DESCENDING BINARY SEARCH ON BOTH TO CHECK FOR KEY ELEMENT
*/
#include <bits/stdc++.h> 
using namespace std; 

int findMaximumIndex(int arr[], int low, int high) 
{ 
	while(low<=high){
      
      int mid = low + (high-low)/2;
      if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
        return mid;
      
      if(arr[mid]>arr[mid-1])
        low = mid+1;
      else
        high = mid-1;
      
    }
  return -1;
} 

int findElement(int arr[],int low,int high,int key){
    int idx = findMaximumIndex(arr,low,high);
    
    int l1=0;int h1=idx;
    int l2=idx+1;int h2=high;
    
    while(l1<=h1){
        int mid = (l1+h1)/2;
        if(arr[mid] == key)
            return 1;
        if(key>arr[mid])
            l1=mid+1;
        else
            h1=mid-1;
    }
    
    while(l2<=h2){
        int mid = (l2+h2)/2;
        if(arr[mid] == key)
            return 1;
        if(key>arr[mid])
            h2=mid-1;
        else
            l2=mid-1;
    }
    
    return -1;
}

/* Driver code */
int main() 
{ 
	int arr[] = {1, 3, 50, 10, 9, 7, 6}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	if(findElement(arr,0,n-1,7)==-1)
	    cout<<"NOT FOUND\n";
	else
	    cout<<"FOUND\n";
	return 0; 
} 


