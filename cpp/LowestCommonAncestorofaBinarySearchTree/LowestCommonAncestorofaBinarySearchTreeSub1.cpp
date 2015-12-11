/* Wrong Answer
 * 但是我觉得这个解法思路很清晰代码简洁，还不知道错在哪
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root) {
            if (p->val>root->val && q->val>root->val) {
                root = root->right;
                continue;
            }
            if (p->val<root->val && q->val<root->val) {
                root = root->left;
                continue;
            }
            return root;
        }
        return NULL;
    }
};