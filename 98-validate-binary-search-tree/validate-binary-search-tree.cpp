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
    bool check(TreeNode* root,long long min, long long max){
        if(root==nullptr) return true;
        if(root->val>=max) return false;
        if(root->val<=min) return false;
        if(check(root->left,min,root->val) && check(root->right,root->val,max))
            return true;
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return check(root->left,LLONG_MIN,root->val) && check(root->right,root->val,LLONG_MAX);
    }
};