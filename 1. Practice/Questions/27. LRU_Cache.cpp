/*

A Least Recently Used (LRU) Cache organizes items in order of use, allowing you to quickly identify which item hasn't been used for the longest amount of time.

Under the hood, an LRU cache is often implemented by pairing a doubly linked list with a hash map.

## Strengths:
Super fast accesses. LRU caches store items in order from most-recently used to least-recently used. That means both can be accessed in O(1)O(1) time.
Super fast updates. Each time an item is accessed, updating the cache takes O(1)O(1) time.

## Weaknesses
Space heavy. An LRU cache tracking nn items requires a linked list of length nn, and a hash map holding nn items. That's O(n)O(n) space, but it's still two data structures (as opposed to one).

*/

class LRUCache {
private:
    list< pair<int,int> > us;       // list of {key,value} pair
    unordered_map<int,list< pair<int,int> >::iterator> hash;    //Hash table with key and pointer to a doubly linked list node storing its {key,value} pair
    int cap;
    
public:
   
    LRUCache(int capacity) {
        cap=capacity;    
    }
    
    int get(int key) {
        //2 conditions
        //1. if key do not exists
        if(hash.find(key)==hash.end()) {
            return -1;
        }
    //key exists in cache
        else{
            list< pair<int,int> >::iterator it = hash[key];
            int val = (*it).second;
            us.erase(it);
    //make the node to the top of the cache
            us.push_front( {key,val} );
            hash[key] = us.begin();
            return val;
        }
    }
    
    void put(int key, int value) {
        //if the key is already present in map then erase it and bring it to the front.
        if(hash.find(key)!=hash.end()){
            auto it = hash[key];
            us.erase(it);
        }  
        //after bringing to the front update the iterator in the map.
       //if list size exceeds capacity then delete from the back (least recently used) and remove this key from the map.
        
        us.push_front({key,value});
        hash[key] = us.begin();
        
        //2. updation case
        if(hash.size()>cap){
            int removk = us.back().first;
            us.pop_back();
            hash.erase(removk);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
