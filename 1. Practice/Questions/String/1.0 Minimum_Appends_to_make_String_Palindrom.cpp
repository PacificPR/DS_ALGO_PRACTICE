/*
Minimum number of Appends needed to make a string palindrome

Given a string s we need to tell minimum characters to be appended (insertion at end) to make a string palindrome.

Examples:

Input : s = "abede"
Output : 2
We can make string palindrome as "abedeba"
by adding ba at the end of the string.

Input : s = "aabb"
Output : 2
We can make string palindrome as"aabbaa"
by adding aa at the end of the string.
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
The solution can be achieved by removing characters from the beginning of the string one by one and checking if the string is palindrome or not.

For Example, consider the above string, s = “abede”.



We check if the string is palindrome or not.
The result is false, then we remove the character from the beginning of string and now string becomes “bede”.

We check if the string is palindrome or not. The result is again false, then we remove the character from the beginning of string and now string becomes “ede”.
We check if the string is palindrome or not. The result is true, so the output becomes 2 which is the number of characters removed from the string. 
*/
 
#include<iostream>
#include<string>

using namespace std;

int pos=0;
bool checkPal(string s){
    if(s.length()==1)
        return true;
    
    int l = 0;
    int h = s.length()-1;

    while(l<h){
        if(s[l]!=s[h])
            return false;
        l++;
        h--;
    }
    return true;
}

int total_appends(string s){
    
    if(checkPal(s))
        return 0;
    else{
        cout<<1+total_appends(s.erase(s.begin()))<<endl;
        return 0;
    }
}

int main(){
    string s;
    cout<<"Enter a String\n";
    cin>>s;
    //cout<<"No of appends = "<<total_appends(s)<<endl;
}
