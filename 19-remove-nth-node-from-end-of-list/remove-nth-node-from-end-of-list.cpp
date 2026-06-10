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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int totalnode = 0;
        ListNode* temp = head;
        while(temp!=nullptr){
            totalnode++;
            temp=temp->next;
        }

        totalnode-=n;
        temp=head;
        if(totalnode ==0) return head->next;
        while(totalnode>1){
            temp=temp->next;
            totalnode--;
        }
        if(temp->next!=nullptr){
            temp->next = temp->next->next;
        }else{
            temp->next = nullptr;
        }
        

        return head;
    }
};