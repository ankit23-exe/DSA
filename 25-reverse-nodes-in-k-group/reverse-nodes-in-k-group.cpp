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
    ListNode* createLinkedList(vector<int>& v) {
        if (v.empty())
            return nullptr;

        ListNode* head = new ListNode(v[0]); // first element
        ListNode* temp = head;

        for (int i = 1; i < v.size(); i++) {
            temp->next = new ListNode(v[i]); // create next node
            temp = temp->next;               // move forward
        }

        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> v;
        ListNode* h = head;
        ListNode* t = head;

        while (h != nullptr) {
            v.push_back(h->val);
            h = h->next;
        }
        for (int i = 0; i < v.size() - (v.size() % k); i += k) {
            int start = i;
            int end = i + k - 1;
            while (start < end) {
                swap(v[start], v[end]);
                start++;
                end--;
            }
        }

         return createLinkedList(v);
    }
};