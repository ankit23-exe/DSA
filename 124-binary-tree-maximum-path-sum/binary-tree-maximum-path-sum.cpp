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
    int maxSum =INT_MIN;

    int solve(TreeNode* root){
        if(root==nullptr) return 0;

        int left = solve(root->left);
        int right =solve(root->right);
        maxSum=max(maxSum,(left+right+root->val));
        maxSum=max(maxSum,(root->val));
        if(left<=0 && right<=0){
            return root->val;
        }
        maxSum=max(maxSum,(root->val + (left>right?left:right)));
        return root->val + (left>right?left:right);

    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};