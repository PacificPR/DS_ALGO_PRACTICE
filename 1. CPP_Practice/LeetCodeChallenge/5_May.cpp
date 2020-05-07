// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
class Solution {
    
public:
    int firstUniqChar(string s) {
        map<char,int> m;
        int l=s.size();
        int i;
        for(i=0;i<l;i++)
            m[s[i]]++;
        
        for(i=0;i<l;i++){
            if(m[s[i]]==1){
                return i;
                
            }
        }
         return -1;
    }
      
};
