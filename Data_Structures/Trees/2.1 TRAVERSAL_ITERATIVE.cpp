/*Just imitating what happens behind the scenes, in CPU while using Traversal recursions. As it is so simple to code preorder,indorer and postorder recursively

        So iteratively , we perform the same flow, while keeping in track the steps on which the node is ,

                FOR PREORDER
        i.e         cout<<root->val             //Step 0
                    Preorder(root->left)        //Step 1
                    Preorder(root->right)       //Step 2

            Similarly for Inorder, Step 0 would be going to left child node
                                   Step 1 would be printing/using the node data
                                   Step 2 would be going to right child node

           Similarly for Postorder,Step 0 would be going to left child node
                                   Step 1 would be going to right child node
                                   Step 2 would be printing/using the node data
       
            This step is counted using unordered_map<node*,int>, where node* is the current node and int is its current step
*/
#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
    node(int x) {
        val = x;
        left = right = NULL;
    }
};

unordered_map<node*, int> cnt;  //For every key node the default value would be 0 at begining


void traversal_trick(node *root) {
    //inorder
    stack<node*> S;             //
    
    S.push(root);
    while(!S.empty()){
        node* cur = S.top();
        if(cur == NULL) { S.pop(); continue; }
        if (cnt[cur] == 0) S.push(cur->left);
        else if (cnt[cur] == 1) cout << cur->val << " " ;
        else if (cnt[cur] == 2) S.push(cur->right);
        else S.pop();
        cnt[cur]++;
    }
}

int main()
{
    node *root = new node(7); 
    node *t = root;
    root->left = new node(3); root->right = new node(10);
    root->left->left = new node(2); root->left->right = new node(5);
    root->left->left->left = new node(1);
    root->right->left = new node(8); 
    root->right->right = new node(12);
    
    traversal_trick(root);
}
