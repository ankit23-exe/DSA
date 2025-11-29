/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Map from original node to its copy
        unordered_map<Node*, Node*> mp;

        // 1) Create all new nodes and store in map
        Node* cur = head;
        while (cur) {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }

        // 2) Assign next and random pointers
        cur = head;
        while (cur) {
            Node* copyNode = mp[cur];
            copyNode->next = cur->next ? mp[cur->next] : nullptr;
            copyNode->random = cur->random ? mp[cur->random] : nullptr;
            cur = cur->next;
        }

        // Head of the copied list
        return mp[head];
    }
};
