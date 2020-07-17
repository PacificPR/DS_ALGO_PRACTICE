class Solution {

public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;          //Map containing frequency of occurence of each number in array
        priority_queue<pair<int,int>> pq;   //Priority Queue to store the frequency of number in decreasing order
        vector<int> res;                    //Vecotr for result
        
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;                  //Creating the frequency map of each number
        
        for(auto i:mp)
            pq.push({i.second,i.first});    //Inserting the pair into priorityqueue , so it gets arranged in non increasing order(decreasing) 
        
        for(int i=1;i<=k;i++){
            res.push_back(pq.top().second); //Returing the top most pair in queue(max frequency) , then it's value (the original number)
            pq.pop();                       //Removing the top most pair after getting the number with max occurence
        }
        return res;
    }
};
