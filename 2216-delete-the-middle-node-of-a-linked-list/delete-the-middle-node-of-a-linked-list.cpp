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
    ListNode* deleteMiddle(ListNode* head) {
        int count =0;
        ListNode* temp = head;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        count/=2;
        if(count==0) return head->next;
        temp = head;
        int k = 0;
        ListNode* prev = nullptr;
        while(k<count){
            k++;
            prev = temp;
            temp=temp->next;
        }
        prev->next=prev->next->next;

        return head;
    }
};