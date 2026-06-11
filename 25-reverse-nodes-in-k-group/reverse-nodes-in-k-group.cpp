class Solution {
public:
    ListNode* kNode(ListNode* head, int k) {
        k--;
        ListNode* temp = head;

        while (temp != nullptr && k > 0) {
            temp = temp->next;
            k--;
        }

        return temp;
    }

    ListNode* kreverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* previousNode = nullptr;
        ListNode* nexthNode = nullptr;
        ListNode* kthNode = nullptr;

        while (temp != nullptr) {

            kthNode = kNode(temp, k);

            if (kthNode == nullptr) {

                
                if (previousNode)
                    previousNode->next = temp;

                return head;
            }

            nexthNode = kthNode->next;
            kthNode->next = nullptr;

            ListNode* newHead = kreverse(temp);

            if (temp == head) {

                
                head = newHead;

            } else {

                if (previousNode)
                    previousNode->next = newHead;   
            }

            
            temp->next = nexthNode;

            previousNode = temp;
            temp = nexthNode;
        }

        return head;
    }
};