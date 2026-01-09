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
    
    pair<int,TreeNode*> lca_with_deepnode(TreeNode* root){
        if(root==nullptr){
            return {0,nullptr};
        }
       
        pair<int,TreeNode*> left=lca_with_deepnode(root->left);
        pair<int,TreeNode*> right=lca_with_deepnode(root->right);
        if(left.first == right.first){
            return {left.first+1,root};
        }
        if(left.first>right.first){
            return {left.first+1,left.second};
        }else{
             return {right.first+1,right.second};
        }

    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        ;
        return lca_with_deepnode(root).second;

    }
};