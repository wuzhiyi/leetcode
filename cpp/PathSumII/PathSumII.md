###Path Sum II
URL: https://leetcode.com/problems/path-sum-ii/</br>
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.</br>
For example:</br>
Given the below binary tree and `sum = 22`,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

	[
	   [5,4,11,2],
	   [5,8,4,5]
	]

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
	    vector<vector<int> > pathSum(TreeNode *root, int sum) {
	        vector<vector<int> > result;
	        vector<int> v;
	        generatePathSum(root, sum, v, result);
	        return result;
	    }
	    
	    void generatePathSum(TreeNode *root, int sum, vector<int> v, vector<vector<int> >& result) {
	        
	        if (root==NULL) {
	            return;
	        }
	        
	        if (root->left==NULL && root->right==NULL) {
	            if (root->val == sum){
	                v.push_back(root->val);
	                result.push_back(v);
	            }
	            return;
	        }
	        
	        v.push_back(root->val);
	        
	        if (root->left) {
	            generatePathSum(root->left, sum - root->val, v, result);
	        }
	        
	        if (root->right) {
	            generatePathSum(root->right, sum - root->val, v, result);
	        }
	    }
	};
