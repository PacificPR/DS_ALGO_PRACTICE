/* You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.
*/

#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n;
    cout<<"Enter number of coins\n";
    cin>>n;

    int st = (sqrt(8*(long)n+1)-1)/2;

    cout<<"Total Complete Stairs : "<<st<<endl;
}
    
/*          EXPLANATION
 
If we look deeper into the formula of the problem, we could actually solve it with the help of mathematics, without using any iteration.
Observe the pattern and find the number of coins needed to complete kth stair
As a reminder, the constraint of the problem can be expressed as follows:

(k(k + 1))/2 <= N
k(k+1)≤2N

This could be solved by completing the square technique,

(k+1/2)^2 - 1/4 <= 2N

So, k = sqrt(2N+1/4) - 1/2;
    k = (sqrt(8*(long)n+1)-1)/2;

