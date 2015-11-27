/* 需要初始化一个fakehead
 * 然后两个指针p1,p2, p2先右移n位，然后再同时右移
 * 这样当p2指向末尾元素时，p1指向目标元素
 * 需要注意的是返回head->next;
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fakehead;
        fakehead->next = head;
        head = fakehead;
        ListNode *p1 = fakehead, *p2 = fakehead;
        for (int i=0; i<n; i++) {
            p2 = p2->next;
        }
        while(p2->next != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return head->next;
    }
};