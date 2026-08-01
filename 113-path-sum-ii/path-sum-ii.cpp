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
    vector<vector<int>>ans;
    vector<int>temp;
    void solve(int &curSum ,TreeNode* root, int targetSum){
        //base case
        if(root==nullptr) return;

        curSum+=root->val;
        temp.push_back(root->val);
        //main base case
        if(curSum==targetSum && root->left == nullptr && root->right == nullptr){
            ans.push_back(temp);
            return;
        }

        
        //going left and right
        solve(curSum,root->left,targetSum);
        if(root->left!=nullptr){
            temp.pop_back();
            curSum-=root->left->val;
        }

        solve(curSum,root->right,targetSum);
        if(root->right!=nullptr){
            temp.pop_back();
            curSum-=root->right->val;
        }
    
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return{};
        int csum=0;
        solve(csum,root,targetSum);

        return ans;
    }
};