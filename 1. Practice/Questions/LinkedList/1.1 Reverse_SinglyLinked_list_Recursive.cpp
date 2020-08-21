/*
    RECURSIVE REVERSING LINKED LIST

We use two pointer in revHelp function to reverse the linked list then point
the global ListNode* HD which points to head after reversing the linked list


*/

class Solution {

    private:
        ListNode* HD;
    public:


    ListNode* reverseR(ListNode* head){
    
        if(!head)
            return head;

        ListNode* prev;
        revHelp(prev,head);
        return HD;
    }


    void revHelp(ListNode* prev, ListNode* curr){
    
        if(curr!=NULL){
            revHelp(curr,curr->next);   //Keep on calling this function till we reach last node
            curr->next = prev;          //While returning from function call , change the current next pointer to prev node
        }
        else{
            HD = prev;                  //When it's the last node point HD to last node, which is now the head node on reversing 
        }
    }
};
