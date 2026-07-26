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
    ListNode* mergeTwoList(ListNode* l1,ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;

        if(l1->val<l2->val){
            l1->next = mergeTwoList(l1->next,l2);
            return l1;
        }else{
            l2->next = mergeTwoList(l1,l2->next);
            return l2;
        }
        
    }
    ListNode* splitAndMerge(int s, int e,vector<ListNode*>& lists){
        if(e-s==0) return lists[s];
        if(e-s+1==2) return mergeTwoList(lists[s],lists[e]);

        int mid = s+(e-s)/2;
        ListNode* part1 = splitAndMerge(s,mid,lists);
        ListNode* part2 = splitAndMerge(mid+1,e,lists);
        return mergeTwoList(part1,part2);

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return nullptr;
        int s =0;
        int e = n-1;

        return splitAndMerge(s,e,lists);
        
    }
};