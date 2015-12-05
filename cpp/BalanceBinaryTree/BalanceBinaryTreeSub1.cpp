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
    int treeDepth(TreeNode* root){
        if (root==NULL) return 0;
        int left = 1, right = 1;
        left += treeDepth(root->left);
        right += treeDepth(root->right);
        return left>right ? left : right;
    }
    
    bool isBalanced(TreeNode* root) {
        if (root==NULL) return true;
        int left = treeDepth(root->left);
        int right = treeDepth(root->right);
        if (left-right>1 || left-right<-1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};