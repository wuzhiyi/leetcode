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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        vector<int> v;
        if (root) {
            v.push_back(root->val);
            vv.push_back(v);
        }
        vector<vector<int>> vv_left, vv_right;
        if (root && root->left) {
            vv_left = levelOrder(root->left);
        }
        if (root && root->right) {
            vv_right = levelOrder(root->right);
        }
        
        for (int i=0; i<vv_left.size() || i<vv_right.size(); i++) {
            if (i<vv_left.size() && i<vv_right.size()) {
                vv_left[i].insert(vv_left[i].end(), vv_right[i].begin(), vv_right[i].end());
                vv.push_back(vv_left[i]);
            } else if (i<vv_left.size()) {
                vv.push_back(vv_left[i]);
            } else {
                vv.push_back(vv_right[i]);
            }
        }
        return vv;
    }
};