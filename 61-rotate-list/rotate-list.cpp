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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return nullptr;
        ListNode* temp = head;
        int size =0;
        while(temp!=nullptr){
            size++;
            temp=temp->next;
        }
        k%=size;
        if(k==0) return head;
        temp = head;
        int t = size-k;
        ListNode* newhead = nullptr;
        while(t>1){
            t--;
            temp= temp->next;
        }
        newhead = temp->next;
        temp->next=nullptr;

        temp = newhead;
        
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = head;
        return newhead;
        
    }
};