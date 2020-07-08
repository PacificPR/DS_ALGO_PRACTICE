/* Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

*/

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<1)
            return "";
        
        int start=0;int end=0;
        for(int i=0;i<s.length();i++){
            int l1=splitfromMid(s,i,i);
            int l2=splitfromMid(s,i,i+1);
            l1=l1>l2?l1:l2;
            if(l1>end-start){
                start = i-((l1-1)/2);
                end = i+(l1/2);
            }
            
        }
        return s.substr(start,end-start+1);
    }
    
    int splitfromMid(string s,int left,int right){
        if(s==""||left>right)
            return 0;
        while(left>=0&&right<s.length()&&s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
            
    }
};

//"racecar"
//"aabccbaa"
