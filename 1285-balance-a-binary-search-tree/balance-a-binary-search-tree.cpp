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
    vector<int> values;
    void traversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        values.push_back(root->val);
        traversal(root->left);
        traversal(root->right);
    }
    TreeNode* buildBST(vector<int> &v,int s,int e){
        if(s>e){
            return nullptr;
        }
        int mid = s + (e-s)/2;
        TreeNode* curr= new TreeNode(v[mid]);
        curr->left = buildBST(v,s,mid-1);
        curr->right= buildBST(v,mid+1,e);

        return curr;
    }

    TreeNode* balanceBST(TreeNode* root) {
        traversal(root);
        sort(values.begin(),values.end());
        

        int e = values.size()-1;
        
        return buildBST(values,0,e);
    }
};