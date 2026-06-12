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
        //detecting cycle first
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        bool cyclefound = false;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                cyclefound = true;
                break;
            }
        }

        if(!cyclefound) return nullptr;

        //step 2 finding where it is the connection
        slow = head;
        if(slow==fast){ //handling edge case 
            while(fast->next != slow){
                fast= fast->next;
            }
            fast->next = nullptr;
            return slow;
        }else{
            while(slow!=fast){
                prev = slow;
                slow=slow->next;
                fast = fast->next;
                if(slow==fast) break;
            }
        }
        prev = nullptr;
        return slow;

    }
};