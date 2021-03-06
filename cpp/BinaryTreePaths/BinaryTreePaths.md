###Binary Tree Paths
URL: https://leetcode.com/problems/binary-tree-paths/</br>
Given a binary tree, return all root-to-leaf paths.</br>
For example, given the following binary tree:

	   1
	 /   \
	2     3
	 \
	  5

All root-to-leaf paths are:

	["1->2->5", "1->3"]

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
	    vector<string> TreePaths;
	    void DFS(TreeNode* node, string answer)
	    {
	        answer += "->" + to_string(node->val);
	        if(node->left == NULL && node->right == NULL)
	            TreePaths.push_back(answer);
	        else
	        {
	            if(node->left != NULL)
	                DFS(node->left, answer);
	            if(node->right != NULL)
	                DFS(node->right, answer);
	        }
	    }
	    vector<string> binaryTreePaths(TreeNode* root) {
	        if(root != NULL)
	        {
	            DFS(root, "");
	            for(int i = 0; i < TreePaths.size(); i++)
	                TreePaths[i].erase(TreePaths[i].begin(), TreePaths[i].begin() + 2);
	        }
	        return TreePaths;
	    }
	};