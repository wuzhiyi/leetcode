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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            k--;
            root = s.top()->right;
            if (k==0) return s.top()->val;
            s.pop();
        }
        return -1;
    }
};