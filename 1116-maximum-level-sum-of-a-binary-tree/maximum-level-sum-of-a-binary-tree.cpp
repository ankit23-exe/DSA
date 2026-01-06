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
    map<int,int> mp;  //level-> sum;

    void inorder(TreeNode* root, int level){
        if(!root){
            return ;
        }
        mp[level]+=root->val;
        inorder(root->left,level+1);
        inorder(root->right,level+1);
        
    }
    int maxLevelSum(TreeNode* root) {

        inorder(root,1);
        int maxsum=INT_MIN;
        int resultlevel=0;
        for(auto it:mp){
            if(it.second>maxsum){
                maxsum=it.second;
                resultlevel=it.first;
            }
        }

        return resultlevel;

    }
};