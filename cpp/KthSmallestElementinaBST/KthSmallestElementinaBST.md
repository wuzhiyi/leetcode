###Kth Smallest Element in a BST
URL: https://leetcode.com/problems/kth-smallest-element-in-a-bst/</br>
Given a binary search tree, write a function `kthSmallest` to find the __k__th smallest element in it.
####Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
####Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
####Hint:

1. Try to utilize the property of a BST.
2. What if you could modify the BST node's structure?
3. The optimal runtime complexity is O(height of BST).

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
	    // in-order travel - recursive way
	    // Wrong Answer
	    int kthSmallestHelper_recursive(TreeNode* root, int& k) {
	        if (root==NULL) return 0; //this behavior is undefined!
	        
	        //in-order travel
	        int result = kthSmallestHelper_recursive(root->left, k);
	        if (k==0) return result;
	        
	        k--;
	        if (k==0) return root->val;
	        
	        
	        return kthSmallestHelper_recursive(root->right, k);
	    }
	    // in-order travel - non-recursive way
	    int kthSmallestHelper_nonRecursive(TreeNode* root, int k){
	        stack<TreeNode*> s;
	        
	        while(!s.empty() || root){
	            
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