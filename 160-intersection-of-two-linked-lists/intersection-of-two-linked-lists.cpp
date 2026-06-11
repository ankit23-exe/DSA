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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<pair<int,ListNode *>>list1;
        vector<pair<int,ListNode *>>list2;
        while(headA!=nullptr){
            list1.push_back({headA->val,headA});
            headA=headA->next;
        }
        while(headB!=nullptr){
            list2.push_back({headB->val,headB});
            headB=headB->next;
        }

        int i = list1.size()-1;
        int j = list2.size()-1;
        int ansidx=-1;

        bool found = false;
        while(i>=0 && j>=0){
            if(list1[i].second==list2[j].second){
                ansidx=i;
                i--;j--;
                found = true;
            }else{    
                break;
            }
        }
        
        if(found)
            return list1[ansidx].second;
        return nullptr;


    }
};