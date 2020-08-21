

void recurse(vector<vector<int>>& graph, vector<int>& curr, vector<vector<int>>& result, int node) {
    if(node == graph.size() - 1) {      // First check if this is the destination node, if it is then
        curr.push_back(node);           // Add this node to the currentPath
        result.push_back(curr);         // Add currentPath to the result , which has all the correct Paths
        curr.pop_back();                // Now remove this node from currentPath, as we can discover another path from this node that leads to destination 
        return;
    }
                                        // So, this node isn't the destination 
    curr.push_back(node);               // Add this node to current Path 
    
    for(auto it : graph[node]) {        //Explore this node and traverse all its neighbours 
        recurse(graph, curr, result, it);
    }
    
    curr.pop_back();                    //Remove this node from current path as both the possiblity is checked above, so discover new path
}

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> curr;
        vector<vector<int>> result;
        
        recurse(graph, curr, result, 0);
        return result;
    }
};
