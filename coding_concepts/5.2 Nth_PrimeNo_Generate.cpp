/* For the nth prime, it has been proven that the nth prime must be greater than

nln(n)+n(ln(ln(n))−1) 

and less than

nln(n)+nln(ln(n))  // So it's upper limit for nth prime number 

When  n≥6 . So if you're searching for the nth prime, I'd look in this gap.

*/

#include<bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    for(int i=2;i<n/2;i++)
        if(n%i==0)
            return 0;
    return 1;

}
int main(){
    int num;
    cout<<"Enter Nth value for finding the Nth Prime number"<<endl;
    cin>>num;
    int *prime = new int(num+1); //Array which will store prime number index wise 
    //  i.e. prime[1]->2, prime[2]->3, prime[3]->5, prime[4]->7 and so on
    
    prime[1]=2;

    //Using Sieve of eratosthenes, maintain an array of isPrime till the upper limit
    int upper_limit = (num*log(num))+(num*log(log(num)));
    cout<<"UPPER LIMIT :  "<<upper_limit<<endl;
    int *isPrime  = new int(upper_limit); // Make every number as prime by default

    for(int i=3;i<upper_limit;i+=2)  //First step, mark every number as Prime
        isPrime[i]=1;

    int count = 2; //Maintaining index for prime number array
    for(int i=3;i<=upper_limit&&count<=num;i+=2){
        if(isPrime[i]==1){
            prime[count++]=i;
            for(int j=i*i;j<=upper_limit;j+=i)
                isPrime[j]=0;
                
            }
        }

    for(int i = 0;i<=num;i++)    
    cout<<"\n"<<i<<"th Prime Number :  "<<prime[i]<<endl;
    //cout<<"\n"<<num<<"th Prime Number :  "<<prime[num]<<endl;
    return 0;
}
