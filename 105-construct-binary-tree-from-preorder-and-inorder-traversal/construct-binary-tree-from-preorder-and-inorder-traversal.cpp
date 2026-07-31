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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int start,int end,int &idx){
        if(start>end) return nullptr;
        
        TreeNode* curNode = new TreeNode(preorder[idx]);
        //currNode ka index in inorder traversal
        int i;
        for(i=0;i<inorder.size();i++){
            if(preorder[idx]==inorder[i]) break;
        }
        idx++;
        // i is the index of element in inorder traversal
        curNode->left = solve(preorder,inorder,start,i-1,idx);
        curNode->right = solve(preorder,inorder,i+1,end,idx);

        return curNode;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        int idx =0;
        return solve(preorder,inorder,0,n-1,idx);
    }
};