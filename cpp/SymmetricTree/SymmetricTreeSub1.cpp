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
    bool isSymmetric(TreeNode* root) {
        if (root==NULL) return true;
        return isSymmetricLR(root->left, root->right);
    }
    
    bool isSymmetricLR(TreeNode* p, TreeNode* q) {
        if (p==NULL && q==NULL) return true;
        if (p==NULL || q==NULL) return false;
        return p->val == q->val &&
               isSymmetricLR(p->left, q->right) &&
               isSymmetricLR(p->right, q->left);
    }
};