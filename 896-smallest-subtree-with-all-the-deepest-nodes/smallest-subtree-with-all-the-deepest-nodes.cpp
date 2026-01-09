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
    int maxdept=0;

    void deptfinder(TreeNode* root,int d){
        if(root==nullptr){
            return;
        }
        maxdept=max(maxdept,d);
        deptfinder(root->left,d+1);
        deptfinder(root->right,d+1);
    }

    TreeNode* lca_with_deepnode(TreeNode* root,int maxd,int d){
        if(root==nullptr){
            return nullptr;
        }
        if(d==maxd){   //current ka dept == maxdept
            return root;
        }
        TreeNode* left=lca_with_deepnode(root->left,maxd,d+1);
        TreeNode* right=lca_with_deepnode(root->right,maxd,d+1);
        if(left!=nullptr && right!=nullptr){
            return root;
        }
        return left==nullptr?right:left;

    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        deptfinder(root,0);
        return lca_with_deepnode(root,maxdept,0);

    }
};