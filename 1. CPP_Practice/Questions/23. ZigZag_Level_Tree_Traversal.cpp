/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
] 
 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)   return vector<vector<int>>();
        
        queue<TreeNode* > q;    
        q.push(root);
        bool f = false;
        
        while(!q.empty() ){
            int levelSize = q.size();   //The number of nodes in that level
            vector<int> level;
            while(levelSize--){     // Access each node,store it in vector, then push it's left and right child node in queue
                TreeNode* current = q.front();
                q.pop();
                level.push_back(current->val);
                if (current->left)  q.push(current->left);
                if (current->right) q.push(current->right);
            }
            if(f)                   //Alternatively reverse the order of nodes value
                reverse(level.begin(),level.end());
            res.push_back(level);
            f=!f;
        }
        return res;
    }
};
