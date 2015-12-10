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
    TreeNode* buildTree(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        TreeNode *node = new TreeNode(nums[(start+end)/2]);
        node->left = buildTree(nums, start, (start+end)/2-1);
        node->right = buildTree(nums, (start+end)/2+1, end);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size()==0) return NULL;
        return buildTree(nums, 0, nums.size()-1);
    }
};