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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> que;   // Using BFS search
        int maxsum =INT_MIN;
        int resultlevel=0;

        int currlevel=1;
        que.push(root);

        while(!que.empty()){
            int n = que.size();
            int sum =0;
            while(n>0){
                TreeNode* temp = que.front();
                que.pop();
                sum+=temp->val;

                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }
                n--;
            }
            if(sum>maxsum){
                maxsum=sum;
                resultlevel=currlevel;
            }
             currlevel++;
        }

        return resultlevel;
    }
};