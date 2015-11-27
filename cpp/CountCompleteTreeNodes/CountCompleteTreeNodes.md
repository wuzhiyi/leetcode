###Count Complete Tree Nodes
URL: https://leetcode.com/problems/count-complete-tree-nodes/</br>
Given a __complete__ binary tree, count the number of nodes.</br>
__Definition of a complete binary tree from [Wikipedia](https://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees)__:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2^h nodes inclusive at the last level h.

__Code:__

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
	    //return -1 if it is not.
	    int isCompleteTree(TreeNode* root) {
	        if (!root) return 0;

	        int cnt = 1;
	        TreeNode *left = root, *right = root;
	        for(; left && right; left=left->left, right=right->right) {
	            cnt *= 2;
	        }
	      
	        if (left!=NULL || right!=NULL) {
	            return -1;
	        }
	        return cnt-1;
	    }

	    int countNodes(TreeNode* root) {
	        int cnt = isCompleteTree(root);
	        if (cnt != -1) return cnt;
	        int leftCnt = countNodes(root->left);
	        int rightCnt = countNodes(root->right);
	        return leftCnt + rightCnt + 1;
	    }
	};