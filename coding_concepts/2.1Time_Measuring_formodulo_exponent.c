#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*unsigned int aModM(string s, unsigned int mod) 
{ 
    unsigned int number = 0; 
    for (unsigned int i = 0; i < s.length(); i++) 
    { 
        // (s[i]-'0') gives the digit value and form 
        // the number 
        number = (number*10 + (s[i] - '0')); 
        number %= mod; 
    } 
    return number; 
} 
  
// Returns find (a^b) % m 
unsigned int ApowBmodM(string &a, unsigned int b, 
                                  unsigned int m) 
{ 
    // Find a%m 
    unsigned int ans = aModM(a, m); 
    unsigned int mul = ans; 
  
    // now multiply ans by b-1 times(as once it's done above,so total b times  ) and take 
    // mod with m 
    for (unsigned int i=1; i<b; i++) 
        ans = (ans*mul) % m; 
  
    return ans; 
} 
*/
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void main(){
    //String a;
    //unsigned int b,c;
    long long a,b,c;
    printf("Enter a b c\n");
    scanf("%lld%lld%llu",&a,&b,&c);

    long long int r = binpow(a,b,c);
    printf("Answer = %lu",r);
}


