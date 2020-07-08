class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        auto i = digits.end()-1;
        *i = *i+1;
        
        int carry = *it/10;
        *i = *i%10;
        
            for(auto it=digits.end()-2;it>=digits.begin();i--){
                if(carry==1){
                    *it = *it + 1;
                    carry = *it/10;
                    *it = *it%10;
                }
                else
                    break;
            }
            if(carry==1)
                digits.insert(digits.begin(),1);
        return digits;
    }
     
        
    
};
