/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> childs;
        for(auto &d:descriptions){
            TreeNode* root = nullptr;
            if(!mp.count(d[0])){
                root = new TreeNode(d[0]);
            }else{
                root = mp[d[0]];
            }
            TreeNode* kid = nullptr;
            if(d[2]){
                root->left=mp.count(d[1])?mp[d[1]]:(kid = new TreeNode(d[1]));
            }else{
                root->right=mp.count(d[1])?mp[d[1]]:(kid = new TreeNode(d[1]));
            }
            if(!mp.count(d[1]))
                mp[d[1]] = kid;
            childs.insert(d[1]);
            mp[d[0]] = root;

        }

        for(auto &p:mp){
            if(!childs.count(p.first)){
                return p.second;
            }
        }
        return 0;
    }
};