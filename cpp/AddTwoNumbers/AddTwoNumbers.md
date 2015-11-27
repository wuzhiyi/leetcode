###Add Two Numbers
URL: https://leetcode.com/problems/add-two-numbers/</br>
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

__Input:__ (2 -> 4 -> 3) + (5 -> 6 -> 4)</br>
__Output:__ 7 -> 0 -> 8

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
	    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	        int x=0, y=0, carry=0, sum=0;
	        ListNode *h=NULL, **t=&h;
	        
	        while (l1!=NULL || l2!=NULL){
	            x = getValueAndMoveNext(l1);
	            y = getValueAndMoveNext(l2);
	            
	            sum = carry + x + y;
	            //新建结点
	            ListNode *node = new ListNode(sum%10);
	            *t = node;
	            t = (&node->next);
	            
	            carry = sum/10;
	        }
	        
	        if (carry > 0) {
	            ListNode *node = new ListNode(carry%10);
	            *t = node;
	        }
	        
	        return h;
	    }
	private:
	    int getValueAndMoveNext(ListNode* &l){
	        int x = 0;
	        if (l != NULL){
	            x = l->val;
	            l = l->next;
	        }
	        return x;
	    }
	};