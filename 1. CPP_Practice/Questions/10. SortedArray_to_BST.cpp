
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

#include<iostream>
#include<vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0),left(nullptr),right(nullptr) {}
    TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x),left(left),right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums,0,nums.size()-1);
    }
    TreeNode* BST(vector<int>& nums,int l,int h){
        if(l<=h){
            int mid = (l+h)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = BST(nums,l,mid-1);
            root->right = BST(nums,mid+1,h);
            return root;
        }
        return NULL;
    }
    void PreOrder(TreeNode* root){
        if(root){
            cout<<root->val<<" ";
            PreOrder(root->left);
            PreOrder(root->right);
        }
    }
};


int main(){
    //ios_base::sync_with_stdio(false);  
    //cin.tie(NULL);
    int n,temp;
    vector<int> v;
    cout<<"Enter no of elements in  sorted array \n";
    cin>>n;
    cout<<"Enter a sorted array to convert to BST\n";
    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(temp);
    }
    Solution s;
    TreeNode* root = s.sortedArrayToBST(v);
    s.PreOrder(root);
    cout<<endl;
}

        
