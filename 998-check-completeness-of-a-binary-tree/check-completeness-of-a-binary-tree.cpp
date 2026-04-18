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
    int count(TreeNode* root){
        if(root ==nullptr) return 0;

        return 1 + count(root->left) + count(root->right);
    }
    bool dfs(int i,TreeNode* root,int totalnodes){
        if(root ==nullptr) return true;
        if(i>totalnodes) return false;

        return dfs(2*i,root->left,totalnodes) &&
               dfs(2*i+1,root->right,totalnodes);
    }
    bool isCompleteTree(TreeNode* root) {
        int totalnodes = count(root);
        int i=1;
        return dfs(i,root,totalnodes);
    }
};