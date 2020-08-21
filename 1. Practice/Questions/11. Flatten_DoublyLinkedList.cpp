/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev; Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return head;
        Node* temp = head;
        while(temp){
            if(temp->child){
                Node* next = temp->next;
                Node* child = flatten(temp->child);
                temp->child = NULL;
                temp->next = child;
                child->prev = temp;
                Node* last = child;
                while(last->next)
                    last = last->next;
                last->next = next;
                if(next)
                    next->prev = last;
            }
            temp = temp->next;
        }
        return head;
    }
};

/*
 
1. Iterate through the nodes
2. If node has child save the next node to a variable; call recursive function call on child (Will return child as head)
3. Set next of current node to child
4  Remove child ptr from current node
5. Iterate through the child node sequence to get last node
6. Set next of last child sequence node to the variable we saved in step 2
7. Set next of this node to the next we saved on step 2
8. If that next was not NULL then set its previous to this last node
9. Return head 

*/
