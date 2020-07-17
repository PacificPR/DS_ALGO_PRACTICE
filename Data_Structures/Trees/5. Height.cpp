#include<iostream>
#include<vector>

using namespace std;

class Tree{
    public:
        int data;
        Tree* left;
        Tree* right;
        Tree(int n): data(n), left(nullptr) ,right(nullptr) {};
};

    int height(Tree* root){  
        if(!root)
            return 1;
        int lheight = height(root->left);
        int rheight = height(root->right);
        return lheight>rheight?lheight+1:rheight+1;    
    }

    int getWidth(Tree* root,int level){
        if(root==nullptr)
            return 0;
        if(level==0)
            return 1;
        else if(level>0)
            return getWidth(root->left,level-1)+getWidth(root->right,level-1);
    }


    int maxWidth(Tree* root){
        int max = 0;
        int width;
        int h = height(root);  

        for(int i=0;i<h;i++){   //For h levels in the tree ,calculate width of each level to find max
            width = getWidth(root,i);
            max = max>width?max:width;
        }
        return max;
    }
    Tree* insertNode(vector<int> ar,Tree* root,int i){

       if(i<ar.size()){
           Tree* temp = new Tree(ar[i]);
           root = temp;
           //For 0-indexed array, left child of ith index : 2i+1 and right child of ith index : 2i+2

           root->left = insertNode(ar,root->left,2*i+1); //Insert Left Child 
           root->right = insertNode(ar,root->right,2*i+2);//Insert Right Child
       } 
       return root;
        
    }
    void PrintInOrder(Tree* root){
        if(root!=nullptr){
            PrintInOrder(root->left);
            cout<<root->data<<" ";
            PrintInOrder(root->right);
        }
    }

    int main(){
        int n,t;
        vector<int> ar;
        //vector<int> nw = {1,2,3,4,5,6};
        cout<<"Enter total number in the binary tree\n";
        cin>>n;
        cout<<"Enter the numbers\n";
        for(int i=0;i<n;i++){
            cin>>t;
            ar.push_back(t);
        }
        Tree* root = insertNode(ar,root,0);
        PrintInOrder(root);
        //Consider height of only root : 1
        cout<<"\nHeight of Tree : "<<height(root);
        cout<<"\nMax width of Tree : "<<maxWidth(root);
        cout<<endl;
        return 0;
    }

