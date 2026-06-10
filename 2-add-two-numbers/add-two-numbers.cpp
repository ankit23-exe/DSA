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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carr = 0;
        ListNode* prev = nullptr;


        while(temp1!=nullptr && temp2!=nullptr){
            int d1 = temp1->val;
            int d2 = temp2->val;
            int sum = d1+d2+carr;
            if(sum>9){
                temp1->val=sum-10;
                carr = 1;
            }else{
                temp1->val=sum;
                carr=0;
            }
            prev= temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=nullptr){
            int d1 = temp1->val;
            int sum = d1+carr;
            if(sum>9){
                temp1->val=sum-10;
                carr = 1;
            }else{
                temp1->val=sum;
                carr=0;
            }
            prev=temp1;
            temp1=temp1->next;
        }
        
        temp1=temp2;
        prev->next = temp1;

        while(temp1!=nullptr){
            int d1 = temp1->val;
            int sum = d1+carr;
            if(sum>9){
                temp1->val=sum-10;
                carr = 1;
            }else{
                temp1->val=sum;
                carr=0;
            }
            prev=temp1;
            temp1=temp1->next;
        }


        // while(temp2!=nullptr){
        //     int d2 = temp2->val;
        //     int sum = d2+carr;
        //     if(sum>9){
        //         temp1->next=new ListNode(sum-10);
        //         carr = 1;
        //     }else{
        //         temp1->next=new ListNode(sum);
        //         carr=0;
        //     }
        //     prev=temp1;
        //     temp1=temp1->next;
        //     temp2=temp2->next;
        // }


        if(carr){
            prev->next = new ListNode(1);
        }
        
        

        return l1;

    }
};