###Construct Binary Tree from Preorder and Inorder Traversal
URL: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/</br>
Given preorder and inorder traversal of a tree, construct the binary tree.

####Note:
You may assume that duplicates do not exist in the tree.

####解法1
__Code:__

	struct TreeNode {
	    int val;
	    TreeNode *left;
	    TreeNode *right;
	    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	TreeNode *buildTree(vector<int>& preorder, int& preidx, vector<int>& inorder);

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	    int preidx=0;
	    return buildTree(preorder, preidx, inorder);
	}

	TreeNode *buildTree(vector<int>& preorder, int& preidx, vector<int>& inorder) {

	    if (preorder.size()<=0 || inorder.size()<=0 ) return NULL;

	    TreeNode *root = new TreeNode(preorder[preidx]);
	    if (inorder.size()==1){
	        return root;
	    }

	    int i;
	    for(i=0; i<inorder.size(); i++){
	        if (inorder[i] == preorder[preidx]){
	            break;
	        }
	    }

	    //error: not found
	    if (i == inorder.size()) return NULL;

	    if (preidx+1 >= preorder.size()){
	        return root;
	    }

	    
	    vector<int> v(inorder.begin(), inorder.begin()+i);
	    if (v.size()>0) {
	        preidx++;
	        root->left = buildTree(preorder, preidx, v);
	    }

	    v.clear();
	    v.assign(inorder.begin()+i+1, inorder.end());
	    if (v.size()>0) {
	        preidx++;
	        root->right = buildTree(preorder, preidx, v);
	    }

	    return root;
	}

####解法2

	class Solution {
	public:
	    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	        // Start typing your C/C++ solution below
	        // DO NOT write int main() function
	        if (preorder.size() <= 0)
	            return NULL;
	            
	        if (preorder.size() != inorder.size())
	            return NULL;
	            
	        TreeNode* root = new TreeNode(0);
	        root = buildTree(preorder, 0, preorder.size()-1, inorder,0, preorder.size()-1);
	        
	        return root;
	    }
	    
	    
	    TreeNode* buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd){
	        if (preEnd < preStart )
	            return NULL;
	            
	        TreeNode* root = new TreeNode(0);
	        root->val = preorder.at(preStart);
	        if (preEnd== preStart)    
	    		return root;
	            
	        int i;
	        for(i = 0; i < inorder.size(); i++){
	            if (inorder.at(inStart+i) == root->val)
	                break;
	        }
	        
	        root->left  = buildTree(preorder, preStart+1, preStart+i,inorder,inStart, inStart + i-1);
	        root->right = buildTree(preorder, preStart+1+i, preEnd,inorder,inStart+ i+1, inEnd);
	        return root;
	    }
	};