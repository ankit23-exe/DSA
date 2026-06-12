/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        while(cur!=nullptr){
            nxt = cur->next;
            cur->next = prev;
            prev=cur;
            cur = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        //finding mid first
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        while(fast!=nullptr && fast->next!=nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        //slow is pointing to mid node and reverse the second half
        slow = reverse(slow);

        //now traverse the orginal head (first half ) and the second half reverse form 
        while(head!=nullptr && slow!=nullptr){
            if(head->val != slow->val) return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};