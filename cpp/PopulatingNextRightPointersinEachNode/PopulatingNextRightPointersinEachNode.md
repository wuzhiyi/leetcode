###Populating Next Right Pointers in Each Node
URL: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/</br>
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to `NULL`.</br>
Initially, all next pointers are set to `NULL`.
####Note:

- You may only use constant extra space.
- You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,</br>
Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

__Code:__

	/**
	 * Definition for binary tree with next pointer.
	 */
	struct TreeLinkNode {
	    int val;
	    TreeLinkNode *left, *right, *next;
	    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	    TreeLinkNode() : val(0), left(NULL), right(NULL), next(NULL) {}
	};


	void connect(TreeLinkNode *root) {

	    if (root==NULL){
	        return;
	    }
	    if (root->left && root->right){
	        root->left->next = root->right;
	    }
	    if (root->next && root->right){
	        root->right->next = root->next->left;
	    }
	    connect(root->left);
	    connect(root->right);

	}

	void connect1(TreeLinkNode *root) {

	    if (root==NULL){
	        return;
	    }

	    vector<TreeLinkNode*> v;    
	    v.push_back(root);
	    int i = 0;
	    
	    while (i < v.size()){
	        if (v[i]->left){
	            v.push_back(v[i]->left);
	        }
	        if (v[i]->right) {
	            v.push_back(v[i]->right);
	        }
	        i++;
	    }

	    i=1;
	    while(i<v.size()){
	        for (int j=i-1; j<2*(i-1); j++){
	           v[j]->next = v[j+1]; 
	        }
	        i *= 2; 
	    }

	}

	void connect2(TreeLinkNode *root) {

	    if (root==NULL){
	        return;
	    }
	    
	    vector<TreeLinkNode*> v;

	    v.push_back(root);
	    
	    while(v.size()>0){
	        
	        if (root->left && root->right && root->left->next == NULL ) {
	            root->left->next = root->right;
	            
	            if (root->next){
	                root->right->next = root->next->left;
	            }
	            
	            v.push_back(root->right);
	            v.push_back(root->left);
	        }
	        root=v.back();
	        v.pop_back();
	    }
	}

	void connect3(TreeLinkNode *root) {
	    if(root == NULL) return;

	    queue<TreeLinkNode*> q;
	    TreeLinkNode *prev, *last;
	    prev = last = root;

	    q.push(root);
	    while(!q.empty()) {
	        TreeLinkNode* p = q.front();
	        q.pop();

	        prev->next = p;
	        if(p->left ) q.push(p->left);
	        if(p->right) q.push(p->right);

	        if(p == last) { // meets last of current level
	            // now, q contains all nodes of next level
	            last = q.back();
	            p->next = NULL; // cut down.
	            prev = q.front();
	        }
	        else {
	            prev = p;
	        }
	    }
	}

	// constant space
	// key point: we can use `next` pointer to represent
	//      the buffering queue of level order traversal.
	void connect4(TreeLinkNode *root) {
	    if(root == NULL) return;

	    TreeLinkNode *head, *tail;
	    TreeLinkNode *prev, *last;

	    head = tail = NULL;
	    prev = last = root;

	#define push(p) \
	    if(head == NULL) { head = tail = p; } \
	    else { tail->next = p; tail = p; }

	    push(root);
	    while(head != NULL) {
	        TreeLinkNode* p = head;
	        head = head->next; // pop

	        prev->next = p;
	        if(p->left ) push(p->left);
	        if(p->right) push(p->right);

	        if(p == last) {
	            last = tail;
	            p->next = NULL; // cut down.
	            prev = head;
	        }
	        else {
	            prev = p;
	        }
	    }
	#undef push
	}