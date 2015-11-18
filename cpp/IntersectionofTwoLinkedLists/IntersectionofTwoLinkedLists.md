###Intersection of Two Linked Lists
URL: https://leetcode.com/problems/intersection-of-two-linked-lists/</br>
Write a program to find the node at which the intersection of two singly linked lists begins.</br>
For example, the following two linked lists:</br>

	A:          a1 → a2
	                   ↘
	                     c1 → c2 → c3
	                   ↗            
	B:     b1 → b2 → b3

begin to intersect at node c1.

__Notes:__

- If the two linked lists have no intersection at all, return `null`.
- The linked lists must retain their original structure after the function returns.
- You may assume there are no cycles anywhere in the entire linked structure.
- Your code should preferably run in O(n) time and use only O(1) memory.

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
	        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

	            //计算两条list的长度
	            int lenA = getListLength(headA);
	            int lenB = getListLength(headB);

	            //判断list长度至少为1
	            if (lenA<=0 || lenB<=0 ) return NULL;

	            //使listA为较长list
	            if (lenA < lenB){
	                swap(headA, headB);
	            }

	            //移动headA，使剩下的listA和listB长度相同
	            for (int i=0; i<abs(lenA-lenB); i++){			//1
	                headA = headA->next;
	            }

	            //同时移动指针headA,headB，直到相等，即为目标结点
	            while (headA != headB){
	                headA = headA->next;
	                headB = headB->next;
	            }
	            return headA;
	        }
	    private:
	    	//计算list长度
	        inline int getListLength(ListNode *head){
	            int len=0;
	            while(head!=NULL){
	                head = head->next;
	                len++;
	            }
	            return len;
	        }
	};

###1 std::abs(std::complex)

头文件：`<complex>`

语法：

	template<class T>
	T abs( const complex<T>& z);

如果没有 errors，返回 z 的绝对值。

