/* 三个指针,prev为已合并链表尾，p1,p2为待合并链表头
 * 关键步骤：static ListNode fakehead(0);
 */

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1,  *p2=l2;
	        static ListNode fakehead(0);
	        fakehead.next = p1;
	        ListNode *prev = &fakehead;
	    
	        while(p1 && p2){
	            if(p1->val < p2->val) {
	                prev = p1;
	                p1 = p1->next;
	            }else{
	                prev->next = p2;
	                p2 = p2->next;
	                prev = prev->next;
	                prev->next = p1;
	            }
	        }
	        if (p2){
	            prev->next = p2;
	        }
	        return fakehead.next;
    }
};