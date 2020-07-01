#include<iostream>

using namespace std;
//This is the Class for storing Nodes in the linkedList
class SinglyLinkedListNode{  
    public:
        int data;
        SinglyLinkedListNode* next;
        SinglyLinkedListNode(int node_data){
            this->data=node_data;
            this->next=nullptr;
        }
    
};

//This is the class for controlling the linked list

class SinglyLinkedList {
    public:
        
        SinglyLinkedListNode* head;
        SinglyLinkedListNode* tail;

        SinglyLinkedList(){
            this->head=nullptr;
            this->tail=nullptr;
        }
        void insert(int node_data){
            SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);//Creating a node by using the first class and its constructor
            if(!this->head)
                this->head = node;
            else
                this->tail->next = node;

            this->tail = node;
        }
      
        SinglyLinkedListNode* reverse_Linked_List(SinglyLinkedListNode* h){
            SinglyLinkedListNode* prev=nullptr;
            SinglyLinkedListNode* current=nullptr;
            SinglyLinkedListNode* nxt=h;
            while(nxt){
                prev = current;
                current = nxt;
                nxt = nxt->next;
                current->next = prev;
            }
            h = current;
            return h;
        }
        void print_LinkedList(SinglyLinkedListNode* h){  //Taking the head node and printing the elements in the linked list
            SinglyLinkedListNode* temp = h;
            while(temp!=nullptr){
                cout<<temp->data<<"\n";
                temp=temp->next;
            }
            free(temp);
        }
        void free_linked_list_nodes(SinglyLinkedListNode* h){
            while(h){
                SinglyLinkedListNode* temp = h;
                h=h->next;
                free(temp);
            }
        }
};

        int main(){
            cout<<"LinkedList Implementation \n";
            SinglyLinkedList ll;
            //SinglyLinkedList* ll = new SinglyLinkedList();  it can be used also, instead of ll.insert , ll->insert would be used as ll would be a pointer 
            ll.insert(10);
            ll.insert(20);
            ll.insert(30);
            ll.insert(40);
            ll.insert(50);
            ll.print_LinkedList(ll.head);
            //cout<<"\n"<<typeid(ll).name()<<endl;
            cout<<"\nReversing the LinkedList \n";
            ll.print_LinkedList(ll.reverse_Linked_List(ll.head));
            //ll.print_LinkedList(ll.head);
            cout<<"\nDeallocating memory of nodes\n";
            ll.free_linked_list_nodes(ll.head);
            return 0;
        }

