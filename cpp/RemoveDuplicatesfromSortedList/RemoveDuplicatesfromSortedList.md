###Remove Duplicates from Sorted List
URL: https://leetcode.com/problems/remove-duplicates-from-sorted-list/</br>
Given a sorted linked list, delete all duplicates such that each element appear only _once_.</br>
For example,</br>
Given `1->1->2`, return `1->2`.</br>
Given `1->1->2->3->3`, return `1->2->3`.

__Code:__

	#include <stdio.h>

	//定义struct ListNode
	struct ListNode {
	    int val;
	    ListNode *next;
	    ListNode(int x) : val(x), next(NULL) {}
	};

	ListNode *deleteDuplicates(ListNode *head) {
	    for (ListNode *p=head; p && p->next;) {
	    	//如果p与p->next值相同，删除p->next
	        if (p->val == p->next->val){
	            p->next = p->next->next;
	            continue;
	        }
	        p=p->next;
	    }
	    return head;
	}

	//打印
	void printList(ListNode* h) {
	    while(h!=NULL){
	        printf("%d ", h->val);
	        h = h->next;
	    }
	    printf("\n");
	}

	//输入sorted array构建成linked list
	ListNode* createList(int a[], int n) {
	    ListNode *head=NULL, *p=NULL;
	    for(int i=0; i<n; i++){
	        if (head == NULL) {
	            head = p = new ListNode(a[i]);
	        }else{
	            p->next = new ListNode(a[i]);
	            p = p->next;
	        }
	    }
	    return head;
	}


	int main()
	{
	    int a[]={1,1,2,3,3};
	    int b[]={1,1,1};

	    printList(deleteDuplicates(createList(a, sizeof(a)/sizeof(int))));	//1
	    printList(deleteDuplicates(createList(b, sizeof(b)/sizeof(int))));
	    return 0;
	}

###1 sizeof()

Syntax:

	sizeof(type)		//(1)
	sizeof expression	//(2)
	//Both versions return a constant of type std::size_t.

####n = sizeof(a)/sizeof(int);

sizeof 函数的功能是求字节数， 检测的是系统为 (int) 中的类型、变量分配的内存空间的字节数.

####32位/64位系统变量所占空间总结：

| sizeof() 		|32 bit|64 bit|
|:------------:	|:-----:|:-----:|
|char 			|1|1|
|short	 		|2|2|
|int 			|4|4|
|long 			|4|4|
|long long 		|8|8|
|float 			|4|4|
|double			|8|8|
|long double 	|8|8|
|wchar_t		|2|2|
|bool 			|1|1|
|char* 			|4|8|
|bool*			|4|8|
|short*	 		|4|8|
|int* 			|4|8|
|long* 			|4|8|
|long long*		|4|8|
|float* 		|4|8|
|double*		|4|8|
|long double* 	|4|8|
|wchar_t*		|4|8|