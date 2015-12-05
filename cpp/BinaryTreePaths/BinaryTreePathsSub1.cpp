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
private:
    vector<string> TreePaths;
    void DFS(TreeNode* node, string ans) {
        ans += "->" + to_string(node->val);
        if (node->left==NULL && node->right==NULL) {
            TreePaths.push_back(ans);
        } else {
            if (node->left != NULL) {
                DFS(node->left, ans);
            }
            if (node->right != NULL) {
                DFS(node->right, ans);
            }
        }
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root) {
            DFS(root, "");
            for (int i=0; i<TreePaths.size(); i++) {
                TreePaths[i].erase(TreePaths[i].begin(), TreePaths[i].begin()+2);
            }
        }
        return TreePaths;
    }
};