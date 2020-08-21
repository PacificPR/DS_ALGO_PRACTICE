/*
In computer science and mathematics, the Josephus problem (or Josephus permutation) is a theoretical problem related to a certain counting-out game. 

People are standing in a circle waiting to be executed. Counting begins at a specified point in the circle and proceeds around the circle in a specified direction.
After a specified number of people are skipped, the next person is executed. 
The procedure is repeated with the remaining people, starting with the next person, going in the same direction and skipping the same number of people, until only one person remains, and is freed.

The problem — given the number of people, starting point, direction, and number to be skipped — is to choose the position in the initial circle to avoid execution.

*/

#include<iostream>

using namespace std;

int Josephus(int n,int k){
    if(n==1)                //Base Condition when only 1 person is remaining
        return 1;
    //As in next state, no of person would be 1 less, k will remain same, 
    //in 1-indexed, K-1 is taken and 
    return Josephus( (Josephus(n-1,k)+k-1)%n+1);        //1-indexed based
  

    /*  0 - indexed 
    return Josephus ( (Josephus(n-1,k)+k)%n) ;


    THE CORE CHANGE OF STATE IS SAME FOR BOTH 0&1-indexed 
    Josephus(n,k) will use Josephus(n-1,k) for the next state.
    For 0-indexed it's simple as similar to circular queue, J(n-1,k)+k means pass sword moves to kth person 
                                                            (J(n-1,k)+k)%n to make sword is within n persons

    For 1-indexed it's diff than 0-indexed,  as   ,         J(n-1,k)+k-1 means pass sword moves to k-1th person  as it is 1-indexed
                                                            (J(n-1,k)+k)%n+1 to make sword is within n-1 persons for 1-indexed

    */
    
}

int main(){
    int n,k;
    cout<<"Enter value of N and K \n";
    cin>>n>>k;

    cout<<"Last person alive at 1-indexed position is : "<<Josephus(n,k)<<endl;
}


/*  IN short
    
    J(n,k) = ((J(n-1,k)+k)%n)   //1 indexed
    J(n,k) = ((J(n-1,k)+k-1)%n+1)   //0 indexed

*/

