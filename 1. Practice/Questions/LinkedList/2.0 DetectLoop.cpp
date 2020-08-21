/*
Floyd's cycle-finding algorithm is a pointer algorithm that uses only two pointers, which move through the sequence at different speeds.
It is also called the "tortoise and the hare algorithm", alluding to Aesop's fable of The Tortoise and the Hare. 

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return false;
        ListNode* p = head;
        ListNode* q = head;
        
        while( q!=NULL && q->next!=NULL) {  //Till fast pointer or fast pointer's next node is not NULL
            p = p->next;
            q = q->next->next;
          
            if(p == q)                      //If fast and slow pointer meet at a point, then there's a loop
                return true;
        }
        return false;
    }
};


// ************ THE POINT WHERE THEY MEET IS NOT NECESSARILY THE LOOP NODE  *******************
//
// TO FIND THE LOOP NODE WE HAVE TO START TRAVERSING FROM THE MEET POINT ONE BY ONE
// SIMULTANEOUSLY WITH A POINTER FROM THE HEAD NODE ONE BY ONE,
// THE POIN WHERE THEY MEET IS THE LOOP NODE


