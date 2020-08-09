//FOR TWO NUMBRES a and  b  :

//a x b = LCM(a, b) * GCD (a, b)

//LCM(a, b) = (a x b) / GCD(a, b) 

#include<iostream>

using namespace std;

class LCM {
    public:
        int gcd(int a,int b){       
            if(b==0)                //b
                return a;           //a
            return gcd(b,a%b);      //ba
        }

        int lcm(long long a,long long b){
            long long l=(a*b)/(gcd(a,b));
            return l;
        }
};
        int main(){
            LCM l;
            long long a,b;
            cin>>a>>b;
            cout<<"LCM : "<<l.lcm(a,b)<<endl;
        }


