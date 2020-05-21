//                                       ******************* SIEVE OF ERATOSTHENES ************************
//
// In mathematics, the sieve of Eratosthenes is an ancient algorithm for finding all prime numbers up to any given limit.

//It does so by iteratively marking as composite (i.e., not prime) the multiples of each prime, starting with the first prime number, 2. 
//The multiples of a given prime are generated as a sequence of numbers starting from that prime, with constant difference between them that is equal to that prime.
//This is the sieve's key distinction from using trial division to sequentially test each candidate number for divisibility by each prime.
#include<iostream>
#include<cmath>
#include<vector>
#include<array>

using namespace std;
    
int main(){
    int i,n,j;
    cout<<"Enter till what number Prime numbers to find\n"<<endl;
    cin>>n;
    int  *pr = new int[n+1];
    vector<int> prime;
    for(i=2;i<=(n);i++){
        if(pr[i]==0){
            prime.push_back(i);
            for(j=2;i*j<=n;j++)
                pr[i*j]=1;
        }
    }
    for(i=0;i<prime.size();i++)
        cout<<prime[i]<<"  ";
}

// As can be seen from the above by removing all constant offsets and constant factors and ignoring terms that tend to zero 
// as n approaches infinity, the time complexity of calculating all primes below n in the random access machine model is O(n log log n) operations, 
// a direct consequence of the fact that the prime harmonic series asymptotically approaches log log n. 
// It has an exponential time complexity with regard to input size, though, which makes it a pseudo-polynomial algorithm. The basic algorithm requires O(n) of memory.
