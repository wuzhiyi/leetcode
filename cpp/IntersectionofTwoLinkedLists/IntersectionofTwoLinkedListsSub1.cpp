/* 先求两个list长度差，然后开始判断
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
private:
    int getListLength(ListNode *head) {
        ListNode *p = head;
        int cnt = 0;
        while (p) {
            p = p->next;
            cnt++;
        }
        return cnt;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = getListLength(headA);
        int len2 = getListLength(headB);
        int gap;
        ListNode *p1, *p2;
        if (len1 < len2) {
            swap(headA, headB);
        }
        gap = abs(len1-len2);
        for (int i=0; i<gap; i++) {
            headA = headA->next;
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};