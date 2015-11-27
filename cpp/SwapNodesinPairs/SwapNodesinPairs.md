###Swap Nodes in Pairs
URL: https://leetcode.com/problems/swap-nodes-in-pairs/</br>
Given a linked list, swap every two adjacent nodes and return its head.

For example,</br>
Given `1->2->3->4`, you should return the list as `2->1->4->3`.

Your algorithm should use only constant space. You may __not__ modify the values in the list, only nodes itself can be changed.

__Code:__

	/**
	 * Definition for singly-linked list.
	 * struct ListNode {
	 *     int val;
	 *     ListNode *next;
	 *     ListNode(int x) : val(x), next(NULL) {}
	 * };
	 */
	class Solution {
	public:
	    Solution(){
	        srand(time(NULL));
	    }
	    /*
	     * Here we have two ways to solve this problem:
	     * 1) keep the list's nodes no change. only swap the data in the list node.
	     * 2) swap the list node physically.
	     */
	    /*just swap the node's value instead of node*/
	    ListNode *swapPairs1(ListNode *head) {
	        for (ListNode *p = head; p && p->next; p = p->next->next) {
	            int n = p->val;
	            p->val = p->next->val;
	            p->next->val = n;
	        }
	        return head;
	    }
	    /*swap the list nodes physically*/ 
	    ListNode *swapPairs2(ListNode *head) {
	        ListNode *h = NULL;
	        //using `*p` to traverse the linked list
	        for (ListNode *p = head; p && p->next; p = p->next) {
	            //`n` is `p`'s next node, and swap `p` and `n` physcially
	            ListNode *n = p->next;
	            p->next = n->next;
	            n->next = p;
	            //using `h` as `p`'s previous node
	            if (h){
	                h->next = n;
	            }
	            h=p;
	            
	            //determin the really 'head' pointer
	            if (head == p){
	                head = n;
	            }
	        }
	        
	        return head;
	    }
	};