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
    vector<string> ans;
    void traversal(string temp,TreeNode* root){

        if (!root) return;
        temp.push_back(root->val + '0');  

        if (!root->left && !root->right) {
            ans.push_back(temp);
            return;
        }
        traversal(temp,root->left);
        traversal(temp,root->right);

    }
    int sumRootToLeaf(TreeNode* root) {
        string temp= "";
        traversal(temp,root);
        int finalans =0;
        for(auto &digi:ans){
            int n = digi.size();
            int k =0;
            int num =0;
            for(int i=n-1;i>=0;i--){
                if(digi[i]=='1'){
                    num +=pow(2,k);
                }
                k++;
            }
            finalans +=num;
        }

        return finalans;
    }
};