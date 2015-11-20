###Maximum Depth of Binary Tree
URL: https://leetcode.com/problems/maximum-depth-of-binary-tree/</br>
Given a binary tree, find its maximum depth.</br>
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

__Code:__

	/**
	 * Definition for binary tree
	 * struct TreeNode {
	 *     int val;
	 *     TreeNode *left;
	 *     TreeNode *right;
	 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	 * };
	 */
	class Solution {
	public:
	    int maxDepth(TreeNode *root) {
	        if (root==NULL){
	            return 0;
	        }
	        if (!root->left && !root->right){
	            return 1;
	        }
	        int left=1, right=1;
	        if (root->left){
	            left += maxDepth(root->left);
	        }
	        if (root->right){
	            right += maxDepth(root->right);
	        }
	        return left>right?left:right;
	    }
	    
	};