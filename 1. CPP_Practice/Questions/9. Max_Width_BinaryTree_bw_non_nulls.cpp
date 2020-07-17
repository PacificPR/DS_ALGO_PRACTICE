/*
  Given a binary tree, write a function to get the maximum width of the given tree.
  The width of a tree is the maximum width among all levels.
  The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level,
where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input: 
                                                                    In Solution,it would be converted to :
           1                                                                        0 
         /   \ .                                                                   / \.     
        3     2                                                                   0   1
       / \     \.                                                                / \   \
      5   3     9                                                               0   1   3            (3-0+1 = 4)

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).

Example 2:

Input: 

          1
         / \
        3   2
       /     \  .
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).
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
    int widthOfBinaryTree(TreeNode* root) {
       int ans = 0;
       //BFS or levelOrder Traversal to count width of each level 
        queue<pair<TreeNode*, unsigned long long>> q;    // A queue of pairs of node and index based on 2*index,2*inex+1 rule
        if (root)
            q.push({root, 0});   //Will work for 1 as well, in fact faster for some reason idk xD
        
        while (!q.empty()) {
            int cnt = q.size(); //Size of queue of current level
            unsigned long long left = q.front().second;  //The leftmost node for the level
            unsigned long long right;
            for (int i = 0; i < cnt; i++) {
                TreeNode* n = q.front().first;  //first element of pair
                right = q.front().second;       //Rightmost node for the level
                q.pop();
                if (n->left != nullptr) {
                    q.push({n->left, 2*right});
                }
                if (n->right != nullptr) {
                    q.push({n->right, 2*right+1});
                }
            }
            ans = max(ans, (int)(right - left + 1));
        }
        
        return ans;
    }
};
