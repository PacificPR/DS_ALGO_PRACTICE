//Vectors are sequence containers representing arrays that can change in size.

//Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements can also be accessed using offsets on regular pointers to its elements, 
//and just as efficiently as in arrays. But unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.

//Internally, vectors use a dynamically allocated array to store their elements. This array may need to be reallocated in order to grow in size when new elements are inserted, 
//which implies allocating a new array and moving all elements to it. This is a relatively expensive task in terms of processing time, and thus, vectors do not reallocate each time an element is added to the container.

//Instead, vector containers may allocate some extra storage to accommodate for possible growth, 
//and thus the container may have an actual capacity greater than the storage strictly needed to contain its elements (i.e., its size).

//sort is present in <algorithm>


#include<iostream>
#include<vector>    
#include<algorithm>
using namespace std;

int main(){
    vector<int> A = {12,43,56,122,42};
    //cout<<A[2]<<endl;
    //sort(A.begin(),A.end());
    //for(int i=0;i<5;i++)
     //   cout<<A[i]<<endl;
     //
    vector<vector<int>> num = {{1,2,3},{4,5},{6}};

    for(int i: num[1])
        cout<<i<<" ";
    return 0;
}
