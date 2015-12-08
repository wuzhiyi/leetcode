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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        vector<TreeNode*> stk;
        if (root) stk.push_back(root);
        while (stk.size()>0) {
            TreeNode* n = stk.back();
            v.push_back(n->val);
            stk.pop_back();
            if (n->right) {
                stk.push_back(n->right);
            }
            if (n->left) {
                stk.push_back(n->left);
            }
        }
        return v;
    }
};