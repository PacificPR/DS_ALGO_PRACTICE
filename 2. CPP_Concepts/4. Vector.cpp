#include<iostream>
#include<vector>

using namespace std;
int main(){
    vector<int> v ;
    cout<<"SIZE CAPACITY MAX_SIZE\n"<<endl;
    for(int i=0;i<33;i++){
        v.push_back(i);
        cout<<v.size()<<"\t"<<v.capacity()<<"\t"<<v.max_size()<<endl;
    }
    return 0;
    
}

//TO AVOID VECTOR CHANGING SIZE AFTER MORE THAN 2N elements are enterd, 
//We can reserve a large space in the beginning itself.
//OR elese after every time size is increased, the vector elements are copied to other location
//Which is expensive task
//v.reserve(n)
