/* 
    ITERATIVE METHOD FOR REVERSING SINGLY LINKEDLIST  

We use sliding pointers to reverse the linked list

*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode *prev,*curr,*next;     //Use three pointer , which point at prev,current and next node
        prev = NULL;
        next = NULL;
        curr = head;
        
        while(curr!=NULL){          
            next = curr->next;          //The next node points to next node of curr
            curr->next = prev;          //The curr->next should point to previous node
            prev = curr;                //Now just move the last two pointers forward, prev to curr
            curr = next;                //And curr to next
        }
        head = prev;                    //At last the curr pointer will be null and prev would be the last node, which becomes head on reversing
        
        return head;
    }
};


