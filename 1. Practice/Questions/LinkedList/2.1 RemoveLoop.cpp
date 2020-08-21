/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        
        ListNode* p = head;
        ListNode* q = head;
        
        while( q && q->next) {
            p = p->next;
            q = q->next->next;
            
            if(p==q){           //IF FAST AND SLOW POINTER MEET THEN THERE'S A CYCLE
                q = head;
                while(p!=q){
                    p=p->next;
                    q=q->next;
                    /* TO GET THE START OF THE LOOP WHICH WILL POINT TO LOOP (SO THAT WE CAN POINT IT TO NULL TO REMOVE LOOP )
                        if(p->next==q->next) then p->next = NULL, will make it linear 
                    */
                }
                return p;  //This is the tail of the loop
                *
            }
        }
      return NULL;
        
    }
};
