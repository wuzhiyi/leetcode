###Remove Nth Node From End of List
URL: https://leetcode.com/problems/remove-nth-node-from-end-of-list/</br>
Given a linked list, remove the _n_th node from the end of list and return its head.</br>
For example,</br>

	Given linked list: 1->2->3->4->5, and n = 2.
	After removing the second node from the end, the linked list becomes 1->2->3->5.

__Note:__
Given _n_ will always be valid.
Try to do this in one pass.

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
	    ListNode *removeNthFromEnd(ListNode *head, int n) {
	    	//判断是否为空list，或n是否有效
	        if (head==NULL || n<=0){
	            return NULL;
	        }
	        ListNode fakeHead(0);
	        fakeHead.next=head;
	        head=&fakeHead;
	        
	        ListNode *p1, *p2;
	        //p1,p2指向fakehead
	        p1=p2=head;
	        //p2右移n位
	        for(int i=0; i<n; i++){
	            if (p2==NULL) return NULL;
	            p2=p2->next;
	        }
	        //p1，p2同时右移，直到p2指向末尾元素，此时p1指向倒数第n个元素
	        while (p2->next!=NULL){
	            p2=p2->next;
	            p1=p1->next;
	        }
	        //删除p1指向的元素
	        p1->next = p1->next->next;
	        return head->next;
	    }
	};
