//Use two pointers
//One slow and fast
//slow moves one node at a time
//fast moves two node at a time
//Traverse the linked list simultaneously using these two
//When fast or fast->next points to null , 
//the current position of slow is in middle of linked list

#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};

class LinkedList{
    public:
        Node* head;
        Node* tail;

        LinkedList(){
            this->head=nullptr;
            this->tail=nullptr;
        }

        void insert(int data){
            Node* temp = new Node(data);
            if(!this->head)
                head=temp;
            else
                this->tail->next = temp;

            this->tail = temp;
        }

        void print_Mid(Node* h){
            Node *slow = h;
            Node *fast = h;
            while(fast&&fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }
            cout<<"\n"<<slow->data<<endl;
        }

        void printlist(Node* h){
            Node* temp = h;
            while(temp){
                cout<<temp->data<<"\n";
                temp=temp->next;
            }
        }

};

int main(){
    cout<<"Linked List Mid element\n";
    int n,v;
    cout<<"Enter number of elements to be in linked list\n";
    cin>>n;
    LinkedList ll;
    for(int i=0;i<n;i++){
        cin>>v;
        ll.insert(v);
    }
    //ll.printlist(ll.head);
    cout<<"Middle element = \n";
    ll.print_Mid(ll.head);


}

