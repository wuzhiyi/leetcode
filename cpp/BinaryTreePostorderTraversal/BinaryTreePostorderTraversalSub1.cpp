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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        vector<TreeNode*> stk;
        TreeNode *node = root;
        TreeNode *lastVisitNode = NULL;
        while (stk.size()>0 || node!=NULL) {
            if (node != NULL) {
                stk.push_back(node);
                node=node->left;
            } else {
                TreeNode *n = stk.back();
                if (n->right!=NULL && lastVisitNode!=n->right) {
                    node=n->right;
                } else {
                stk.pop_back();
                v.push_back(n->val);
                lastVisitNode=n;
                }
            }
        }
        return v;
    }
};