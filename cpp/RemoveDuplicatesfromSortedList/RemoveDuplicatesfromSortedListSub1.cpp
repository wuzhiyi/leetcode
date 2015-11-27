/* 判断，如果p.val = p.next.val, p右移两位，否则，p右移1位
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p;
        p = head;
        while (p && p->next) {
            if (p->val == p->next->val) {
                p->next = p->next->next;
                continue;
            }
            p = p->next;
        }
        return head;
    }
};