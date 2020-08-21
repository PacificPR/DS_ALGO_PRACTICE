/**
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        
        TreeNode* left = invertTree(root->left);        //Get to the left most node
        TreeNode* right = invertTree(root->right);      //Get the right most node
        
        root->left = right;                             //Then swap them  
        root->right = left;
        
        return root;
    }
};



