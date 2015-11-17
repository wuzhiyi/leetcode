###Delete Node in a Linked List
URL: https://leetcode.com/problems/delete-node-in-a-linked-list/</br>
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.</br>
Supposed the linked list is `1 -> 2 -> 3 -> 4` and you are given the third node with value `3`, the linked list should become `1 -> 2 -> 4` after calling your function.

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
	    //becasue the deleted is not the tail.
	    //将该node->next的val赋值给当前node，然后node->next指向node->next->next
	    void deleteNode(ListNode* node) {
	        node->val = node->next->val;
	        node->next = node->next->next;
	    }
	};