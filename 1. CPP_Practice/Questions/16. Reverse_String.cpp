 /* 

###### Reverse Words in a String
   Given an input string, reverse the string word by word.

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cout<<"Enter a string to reverse its words\n";
    getline(cin,s);

    stringstream str(s);

    string w,op="";

    while(str>>w)
        op = w+" "+op;
    cout<<"Reverse : "<<op.substr(0,op.length()-1)<<endl;
    //cout<<"Reverse : "<<op.pop_back()<<endl;
}

