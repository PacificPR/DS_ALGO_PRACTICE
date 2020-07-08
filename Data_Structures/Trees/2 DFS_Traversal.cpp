/*
PRE  =  -->

        ^
IN   =  | 
        

POST =  <--

*/

#include <iostream>

using namespace std;

class Node{
        public:
                int data;
                Node* left;
                Node* right;
                Node(int x) : data(x), left(nullptr), right(nullptr) {} //Node Constructor initializing it's data members
};

void Preorder(Node* s){
        if(s!=nullptr){
                cout<<s->data<<" ";
                Preorder(s->left);
                Preorder(s->right);
        }
}


void Inorder(Node* s){
        if(s!=nullptr){
                Inorder(s->left);
                cout<<s->data<<" ";
                Inorder(s->right);
        }
}


void Postorder(Node* s){
        if(s!=nullptr){
                Postorder(s->left);
                Postorder(s->right);
                cout<<s->data<<" ";
        }
}

Node* addNode(int value){
        Node* t = new Node(value);
        return t;
}

int main(){
        int n;
        Node * root = addNode(1);
        root->left = addNode(2); 
        root->right = addNode(3); 
        root->left->left = addNode(4); 
        root->left->right = addNode(5); 
        root->right->left = addNode(6); 
        root->right->right= addNode(7); 
        cout<<"PREORDER TRAVERSAL  : ";
        Preorder(root);cout<<"\n";
        cout<<"INORDER TRAVERSAL  : ";
        Inorder(root);cout<<"\n";
        cout<<"POSTORDER TRAVERSAL  : ";
        Postorder(root);cout<<"\n";
}

/*                  1
                   / \
                  2   3
                 / \ /  \
                4  5 6   7
*/  



