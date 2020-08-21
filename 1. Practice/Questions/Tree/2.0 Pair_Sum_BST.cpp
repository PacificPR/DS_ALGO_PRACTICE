/*
653. Two Sum IV - Input is a BST
Easy

1512

141

Add to List

Share
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:

Input:                  
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9      Output: True
 
Example 2:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28     Output: False
*/

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
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        unordered_set<int> num;
        Inorder(root,num);
        int p=0,q=1;
        for(auto i=num.begin();i!=num.end();i++){
            auto idx = num.find(k-*i);              //Index of element with value k-(current_element), but it shouldn't be the same element
            if( idx != num.end() && idx != i)       //for 1,2,5,7 it will return true as 2+2=4, so we have to check if it's not the same element
                return true;
        }
        
        return false;
        
    }

    
    void Inorder(TreeNode* root,unordered_set<int>& num){   //Traverse the bst and push the elements in a set/map
        if(!root)
            return;
        Inorder(root->left,num);
        num.insert(root->val);
        Inorder(root->right,num);
    }
};
