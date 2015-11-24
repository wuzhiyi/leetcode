###Rotate List
URL: https://leetcode.com/problems/rotate-list/</br>
Given a list, rotate the list to the right by _k_ places, where _k_ is non-negative.

For example:</br>
Given `1->2->3->4->5->NULL` and _k_ = `2`,</br>
return `4->5->1->2->3->NULL`.

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
	    ListNode *rotateRight(ListNode *head, int k) {
	        if (!head || k<=0){
	            return head;
	        }
	        
	        //find the length of List
	        int len=1;
	        ListNode *p=head;
	        while( p->next != NULL ){
	            p = p->next;
	            len++;
	        }
	        //connect the tail to head
	        p->next = head;
	        //find the left place (take care the case - k > len)
	        k = len - k % len;
	        
	        //find the place
	        for(int i=0; i<k; i++){
	            p = p->next;
	        }
	        
	        //break the list
	        head = p->next;
	        p->next = NULL;
	        
	        return head;
	        
	    }
	};