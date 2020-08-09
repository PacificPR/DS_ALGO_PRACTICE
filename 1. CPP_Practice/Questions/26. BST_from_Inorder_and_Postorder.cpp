/*
The Idea is As They Given us Inorder and Postorder

We Know Inorder Fallow --> **Left_subtree => Root_Node => Right_subtree ** Traverse
   ans   Postorder Fallow --> **Left_subtree => Right_subtree =>Root_Node **`traverse
using Postorder_array We can Find Root_Node Which always lay in Postorder_array last Possition
After Finding That Root_Node ,First are going to devide Inorder_array Into Two Part and Postorder Array
into Two part .

Then We are going to use Both of the arrays left part to Figur Out Left_subtree
                     and Both of the arraysRigth Part to Figur out Right_subtree

We are going to recoursive do so until One Of the arry dose not got empty
Let's take an Example

    inorder   = [4 2 5 1 6 3 7]
    postorder = [4 5 2 6 7 3 1]

    So root would be 1 here and Left array which lay left of 1 is [4 2 5] and Right of 1 is [6 3 7]
    so left_inorder_array =  [4 2 5] and right_inorder_arry = [6 3 7]

    using 6 [ which is just rigth of 1] we are going to devide Postorder_array into two part
    [4 5 2] and [6 7 3]


    1st Phase=>        1

                   /        \

                [4 2 5]   [6 3 7]
                [4 5 2]   [6 7 3]

    2nd Phase =>
                           1

                      /        \
                     2          3
                [4]    [5]   [6]   [7]
                [4]    [5]   [6]   [7]

    3rd Phase =>  1

               /    \
              2      3
 
            /  \    /  \             <==== Answer
 
           4    5  6    7
		   
		  
*/

class Solution {
public:
    TreeNode *Tree(vector<int>& in, int x, int y,vector<int>& po,int a,int b){
        if(x > y || a > b)return nullptr;
        TreeNode *node = new TreeNode(po[b]);
        int SI = x;  
        while(node->val != in[SI])SI++;
        node->left  = Tree(in,x,SI-1,po,a,a+SI-x-1);
        node->right = Tree(in,SI+1,y,po,a+SI-x,b-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& po){
        return Tree(in,0,in.size()-1,po,0,po.size()-1);
    }
};
