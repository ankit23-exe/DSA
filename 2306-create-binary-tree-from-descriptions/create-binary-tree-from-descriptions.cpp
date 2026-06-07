/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childs;

        for (auto& d : descriptions) {
            int p_val = d[0];
            int c_val = d[1];

            TreeNode* p = nullptr;
            TreeNode* c = nullptr;

            p = mp.count(p_val) ? mp[p_val] : new TreeNode(p_val);
            c = mp.count(c_val) ? mp[c_val] : new TreeNode(c_val);

            mp[p_val] = p;
            mp[c_val] = c;

            if (d[2]) {
                p->left = c;
            } else {
                p->right = c;
            }

            childs.insert(c_val);
        }

        for (auto& p : mp) {
            if (!childs.count(p.first)) {
                return p.second;
            }
        }
        return new TreeNode(1);
    }
};