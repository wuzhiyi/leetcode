###Palindrome Linked List
URL: https://leetcode.com/problems/palindrome-linked-list/</br>
Given a singly linked list, determine if it is a palindrome.</br>
__Follow up:__</br>
Could you do it in O(n) time and O(1) space?

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
		//找到中位结点
	    ListNode* findMiddle(ListNode* head) {
	        ListNode *p1=head, *p2=head;
	        //p1右移一位同时p2右移两位，当p2指向末尾时，p1指向中位
	        while(p2 && p2->next){
	            p1 = p1->next;
	            p2 = p2->next->next;
	        }
	        return p1;
	    }
	    //翻转list
	    ListNode* reverseLink(ListNode* head) {
	        ListNode* p=NULL;
	        
	        while (head) {
	        	//每次循环，重新定义q=head->next;
	            ListNode* q = head->next;
	            head->next = p;
	            p = head;
	            head = q;
	        }
	        return p;
	    }
	    
	    bool isPalindrome(ListNode* head) {
	    	//找到list中位结点
	        ListNode* pMid = findMiddle(head);
	        //翻转中位结点右侧的list
	        ListNode* pRev = reverseLink(pMid); 
	        //逐个比较head和pRev
	        for(;head!=pMid; head=head->next, pRev=pRev->next) {
	            if (head->val != pRev->val) {
	                return false;
	            }
	        }
	        return true;
	    }
	};