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
    vector<vector<int>> solve(TreeNode* root){
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> temp;
            while(size--){
                auto f = que.front();
                que.pop();
                temp.push_back(f->val);
                if(f->left!=nullptr){
                    que.push(f->left);
                }
                if(f->right!=nullptr){
                    que.push(f->right);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return{};
        //vector<vector<int>> ans;
        
        return solve(root);
    }
};