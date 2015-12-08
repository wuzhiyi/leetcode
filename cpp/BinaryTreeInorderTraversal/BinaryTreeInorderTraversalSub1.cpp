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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        vector<TreeNode*> stk;
        while (stk.size()>0 || root!=NULL) {
            if (root != NULL) {
                stk.push_back(root);
                root=root->left;
            } else {
                if (stk.size()>0) {
                    root = stk.back();
                    stk.pop_back();
                    v.push_back(root->val);
                    root=root->right;
                }
            }
        }
        return v;
    }
};