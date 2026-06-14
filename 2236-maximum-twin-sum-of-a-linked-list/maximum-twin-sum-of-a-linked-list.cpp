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
        ListNode* nxt = nullptr;
        ListNode* prev = nullptr;
        while(cur!=nullptr){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            prev = slow;
            slow=slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        //now the second portion is with the slow 
        //we will reverse it 
        slow = reverse(slow);
        int ans = INT_MIN;
        while(head!=nullptr && slow!=nullptr){
             ans = max(ans,head->val+slow->val);
            head= head->next;
            slow = slow->next;
        }

        return ans;
           
    }
};