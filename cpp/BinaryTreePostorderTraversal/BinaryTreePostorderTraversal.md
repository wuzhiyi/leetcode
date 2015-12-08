###Binary Tree Postorder Traversal
URL: https://leetcode.com/problems/binary-tree-postorder-traversal/</br>
Given a binary tree, return the _postorder_ traversal of its nodes' values.</br>
For example:</br>
Given binary tree `{1,#,2,3}`,

	   1
	    \
	     2
	    /
	   3

return `[3,2,1]`.</br>
__Note:__ Recursive solution is trivial, could you do it iteratively?

__Code:__

	struct TreeNode {
	    int val;
	    TreeNode *left;
	    TreeNode *right;
	    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	vector<int> postorderTraversal1(TreeNode *root);
	vector<int> postorderTraversal2(TreeNode *root);


	// We have two methods here.
	//   1) the first one acutally is pre-order but reversed the access order.
	//   2) the second one is the traditional one 

	vector<int> postorderTraversal(TreeNode *root) {
	    if (random()%2){
	        cout << "---method one---" << endl;
	        return postorderTraversal1(root);
	    }
	    cout << "---method two---" << endl;
	    return postorderTraversal2(root);
	}


	vector<int> postorderTraversal1(TreeNode *root) {
	    vector<int> v;
	    vector<TreeNode*> stack;
	    if (root) {
	        stack.push_back(root);
	    }
	    while (stack.size()>0){
	        TreeNode *n = stack.back();
	        stack.pop_back();
	        v.push_back(n->val);
	        if (n->left){
	            stack.push_back(n->left);
	        } 
	        if (n->right) {
	            stack.push_back(n->right);
	        }
	    }
	    std::reverse(v.begin(), v.end());  // the trick
	    return v;
	}

	// traditional and standard way.
	// using the stack to simulate the recursive function stack.
	vector<int> postorderTraversal2(TreeNode *root) {
	    vector<int> v;
	    vector<TreeNode*> stack;
	    TreeNode *node = root;
	    TreeNode *lastVisitNode = NULL;
	    while(stack.size()>0 || node!=NULL){

	        if (node != NULL){
	            // keep going the left
	            stack.push_back(node);
	            node = node->left;
	        }else{
	            TreeNode *n = stack.back();
	            // left way is finsised, keep going to the right way
	            if (n->right != NULL && lastVisitNode != n->right){
	                node = n->right;
	            }else{
	                // both left and right has been accessed.
	                stack.pop_back();
	                v.push_back(n->val);
	                lastVisitNode = n;
	            }
	        }
	    }
	    return v;
	}