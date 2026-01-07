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
    long SUM=0;
    long maxp=0;
    int findsum(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int leftsum =findsum(root->left);
        int rightsum=findsum(root->right);

        int sum =root->val+leftsum+rightsum;

        return sum;
    }

    long findmaxp(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int leftsum=findmaxp(root->left);
        int rightsum=findmaxp(root->right);
        long s1 = root->val+leftsum+rightsum;
        long s2 = SUM-s1;
        long product = s1*s2;
        maxp =max(maxp,product);

        return s1;
    }

    long maxProduct(TreeNode* root) {
        SUM=findsum(root);

        findmaxp(root);

        return maxp % (1000000007);

    }
};