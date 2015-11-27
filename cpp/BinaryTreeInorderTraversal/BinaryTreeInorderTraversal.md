###Binary Tree Inorder Traversal
URL: https://leetcode.com/problems/binary-tree-inorder-traversal/</br>
Given a binary tree, return the inorder traversal of its nodes' values.</br>
For example:</br>
Given binary tree `{1,#,2,3}`,

	   1
	    \
	     2
	    /
	   3

return `[1,3,2]`.</br>
__Note:__ Recursive solution is trivial, could you do it iteratively?</br>
confused what `"{1,#,2,3}"` means? > read more on how binary tree is serialized on OJ.

####OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.</br>
Here's an example:

	   1
	  / \
	 2   3
	    /
	   4
	    \
	     5

The above binary tree is serialized as `"{1,2,3,#,#,4,#,#,5}"`.

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
	    vector<int> inorderTraversal(TreeNode *root) {
	        vector<TreeNode*> stack;
	        vector<int> v;
	        
	        while(stack.size()>0 || root!=NULL){
	            if (root!=NULL){
	                stack.push_back(root);
	                root = root->left;
	            }else{
	                if (stack.size()>0) {
	                    root = stack.back();
	                    stack.pop_back();
	                    v.push_back(root->val);
	                    root = root->right;
	                }
	            }
	        }
	        return v;
	    }
	};