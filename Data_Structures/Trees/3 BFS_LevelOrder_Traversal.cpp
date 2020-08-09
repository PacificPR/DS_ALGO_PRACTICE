#include <iostream>
#include <queue>

using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;
        Node(int v): val(v), left(nullptr), right(nullptr) {}
};

void Level_Order(Node* n){
    queue<Node*> q;
    q.push(n);

    while(!q.empty()){
        Node* t = q.front();
        q.pop();
        cout<<t->val<<" ";
        if(t->left!=nullptr)
        q.push(t->left);
        if(t->right!=nullptr)
        q.push(t->right);
    }

}

Node* addNode(int v){
    Node* t = new Node(v);
    return t;
}

int main(){
    Node* root = addNode(1);
    root->left = addNode(2);
    root->right = addNode(3);
    root->left->left = addNode(4);
    root->left->right = addNode(5);
    root->right->left = addNode(6);
    root->right->right = addNode(7);
    cout<<"BFS_Level_Order : ";
    Level_Order(root);cout<<endl;
}


/*                  1
                   / \
                  2   3
                 / \ /  \
                4  5 6   7
*/  
