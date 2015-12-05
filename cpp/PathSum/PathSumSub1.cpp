/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root==NULL) return false;
        if (root->left==NULL && root->right==NULL) return root->val==sum;
        
        if (root->left) {
            root->left->val += root->val;
            if (hasPathSum(root->left, sum)) {
                return true;
            }
        }
        if (root->right) {
            root->right->val += root->val;
            if (hasPathSum(root->right, sum)) {
                return true;
            }
        }
        
        return false;
    }
};