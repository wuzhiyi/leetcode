###Merge Two Sorted Lists
URL: https://leetcode.com/problems/merge-two-sorted-lists/</br>
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

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
	    //解法1:将list2合并到list1
	    ListNode *mergeTwoSortedLists1(ListNode* head1, ListNode* head2) {
	        ListNode *p1 = head1,  *p2=head2;
	        //定义静态数据成员dummy作为伪链表头
	        static ListNode dummy(0);
	    
	        dummy.next = p1;
	        //prev指针指向新链表头dummy
	        ListNode *prev = &dummy;
	    
	        while(p1 && p2){
	        	//比较p1,p2指向元素大小，然后合并到list1
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
	        //合并list2剩下的结点
	        if (p2){
	            prev->next = p2;
	        }
	    	//返回真链表头
	        return dummy.next;
	    }

	    //解法2:将list1和list2合并成一个新的list
	    ListNode *mergeTwoSortedLists2(ListNode *l1, ListNode *l2) {
	        ListNode *l=NULL, *p=NULL;
	        
	        while (l1!=NULL && l2!=NULL) {
	        	//定一个temp指针
	            ListNode *temp = NULL;
	            if (l1->val < l2-> val){
	                temp = l1;
	                l1=l1->next;
	            }else{
	                temp = l2;
	                l2=l2->next;
	            }
	            if (l==NULL){
	                l = p = temp;
	            }else{
	                p->next = temp;
	                p = p->next;
	            }
	        }
	        
	        ListNode* rest = l1 ? l1 :l2;
	        //合并剩下的元素
	        l = mergeTheRest(rest, l, p);
	       
	        return l;
	    }

	    ListNode* mergeTheRest(ListNode* l, ListNode*head, ListNode* tail) {
	        if (l) {
	            if (head && tail) {
	                tail->next = l;
	            }else{
	                head = l;
	            }
	        }
	        return head;
	    }

	    //解法3
	    ListNode *mergeTwoSortedLists3(ListNode *l1, ListNode *l2) {
	        ListNode *head = NULL;
	        ListNode **pTail = &head;
	        while (l1 != NULL && l2 != NULL) {
	            if (l1->val < l2->val) {
	                *pTail = l1;
	                l1 = l1->next;
	            } else {
	                *pTail = l2;
	                l2 = l2->next;
	            }
	            pTail = &(*pTail)->next;
	        }
	        *pTail = (l1 != NULL ? l1 : l2);
	        return head;
	    }

	};