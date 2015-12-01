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
    int minDepth(TreeNode* root) {
        if (root==NULL) return 0;
        if (root->left==NULL && root->right==NULL) return 1;
        int left = root->left!=NULL ? minDepth(root->left) : INT_MAX;
        int right = root->right!=NULL ? minDepth(root->right) : INT_MAX;
        return left < right ? left+1 : right+1;
    }
};