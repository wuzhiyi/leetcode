###Reverse Nodes in k-Group
URL: https://leetcode.com/problems/reverse-nodes-in-k-group/</br>
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.</br>
If the number of nodes is not a multiple of _k_ then left-out nodes in the end should remain as it is.</br>
You may not alter the values in the nodes, only nodes itself may be changed.</br>
Only constant memory is allowed.

For example,</br>
Given this linked list: `1->2->3->4->5`</br>
For _k_ = 2, you should return: `2->1->4->3->5`</br>
For _k_ = 3, you should return: `3->2->1->4->5`

__Code:__

	#include <stdio.h>
	#include <stdlib.h>
	#include <iostream>
	using namespace std;

	struct ListNode {
	    int val;
	    ListNode *next;
	    ListNode(int x) : val(x), next(NULL) {}
	};

	ListNode *reverseList(ListNode *&head, int k);

	ListNode *reverseKGroup(ListNode *head, int k) {

	    if (k<=0) return head;
	    ListNode fake(0);
	    fake.next = head;
	    ListNode* p = &fake;

	    while(p){
	        p->next = reverseList(p->next, k);
	        for(int i=0; p && i<k; i++){
	            p = p->next;
	        }
	    }

	    return fake.next;
	}

	ListNode *reverseList(ListNode *&head, int k){
	    ListNode* pEnd=head;
	    while (pEnd && k>0){
	        pEnd = pEnd->next;
	        k--;
	    }
	    if (k>0) return head;

	    ListNode *pHead=pEnd, *p=head;
	    while(p != pEnd){
	        ListNode *q = p->next;
	        p->next = pHead;
	        pHead = p;
	        p = q;
	    }
	    return pHead;
	}

	void printList(ListNode* h)
	{
	    while(h!=NULL){
	        printf("%d ", h->val);
	        h = h->next;
	    }
	    printf("\n");
	}

	ListNode* createList(int a[], int n)
	{
	    ListNode *head=NULL, *p=NULL;
	    for(int i=0; i<n; i++){
	        if (head == NULL){
	            head = p = new ListNode(a[i]);
	        }else{
	            p->next = new ListNode(a[i]);
	            p = p->next;
	        }
	    }
	    return head;
	}


	int main(int argc, char** argv)
	{
	    int a[] = {1,2,3,4,5,6,7,8,9,10};
	    ListNode* pList = createList(a, sizeof(a)/sizeof(int));

	    int k =2;
	    if (argc>1){
	        k = atoi(argv[1]);
	    }

	    pList = reverseKGroup(pList, k);
	    printList(pList);
	    
	    return 0;
	}