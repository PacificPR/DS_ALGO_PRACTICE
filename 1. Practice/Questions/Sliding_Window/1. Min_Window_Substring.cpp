/*
            #############   Minimum Window Substring  ##############

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n) .

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"

*/

#include<iostream>
#include<string>
#include<limits.h>

using namespace std;

    string minWindow(string s, string t) {
        if(s.size()==0 || t.size()==0)
            return 0;
        
        int tar_map[128]={0};
   
        for(char c : t)
            ++tar_map[c];
        
        int count=0;  //Counts the lenght of current window having char in t string
        int left=0,right=0;
        int window_len = INT_MAX;
        string res = "";
        for(right=0;right<s.size();right++){
            if(--tar_map[s[right]]>=0)  //Means this char was present in t string at least once
                count++;
            cout<<"A value : " <<tar_map['A']<<endl;
            while(count==t.size()){
                if(window_len>right-left+1){
                    window_len = right-left+1;
                    res = s.substr(left,window_len);
                }
                if(++tar_map[s[left]]>0)    //first time left will only have char which is in t
                    --count;
                left++;
            }    
        }
            cout<<"A value : " <<tar_map['A']<<endl;
        return res;
    }

    int main(){
        string s,t;
        cout<<"ENTER THE MAIN STRING AND TARGET STRING \n";
        cin>>s>>t;

        cout<<"Min Window containing Target string :  "<<minWindow(s,t)<<endl;

    }

