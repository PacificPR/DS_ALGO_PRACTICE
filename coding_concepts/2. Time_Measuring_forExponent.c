/* Program to demonstrate time taken by function fun() */
#include <stdio.h> 
#include <time.h> 


long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

//******************** BEST WAY ********************
long long exponent(long long a, long long b) { // BEST WAY 
    long long y;
    if(b==0)
        return 1;
    else if(b%2==0){
        y=exponent(a,b/2);
        return y*y;
        }
    else
        return a*exponent(a,b-1);

}
//********************* BEST WAY **************


// The main program calls fun() and measures time taken by fun() 
int main() 
{ 
	// Calculate the time taken by fun() 
    int i;
    long long a,b,c; 
    printf("Enter a and b\n");
    scanf("%lld%lld",&a,&b);
    long long res1,res2,res3;
    res3=1;
	clock_t t; 
    double time_taken;
	t = clock(); 
	res1 = binpow(a,b); 
	t = clock() - t; 
	time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf("Ans = %lld\n",res1);
	printf("binpow() took %f seconds to execute \n\n", time_taken); 

    t = clock(); 
	res2 = exponent(a,b); 
	t = clock() - t; 
	time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf("Ans = %lld\n",res2);
	printf("exponent() took %f seconds to execute \n\n", time_taken); 

    t=clock();
    for(i=1;i<=b;i++)
        res3=res3*a;
    t=clock()-t;
	time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf("Ans = %lld\n",res3);
    printf("\nNormally it would take = %f,time_taken");
	return 0; 
} 

