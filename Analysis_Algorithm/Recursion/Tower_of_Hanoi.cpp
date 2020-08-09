#include<iostream>

using namespace std;


void TOH(int n, char A,char B,char C){      //TOH(no.of_disks,Source,intermediate,dest)

    if(n>0){
        TOH(n-1,A,C,B);         //Imagine the procedure for 2 disks, first we send the smaller disk from A to B,(Using C)
                                //Then the larger disk is send to C
        cout<<"Disk "<<n<<"FROM "<<A<<"TO "<<C<<endl;
        TOH(n-1,B,A,C);         //Then we send the smaller disk from B to C,
    }
}

int main(){
    int n;
    cout<<"Enter number of Disks : ";
    cin>>n;
    TOH(n,'A','B','C');
    return 0;
}

/*
 
        Recursive Equation : T(n) = 2T(n-1) + 1  
    
        T(n)= O( 2^{(n+1)} - 1), or you can say O(2^n) which is exponentioal

*/
