/* 比较左右subtree的深度，然后递归返回该结点的最大深度
 */

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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (!root->left && !root->right) return 1;
        int left=1, right=1;
        if (root->left) {
            left += maxDepth(root->left);
        }
        if (root->right) {
            right += maxDepth(root->right);
        }
        return left>right ? left : right;
    }
};