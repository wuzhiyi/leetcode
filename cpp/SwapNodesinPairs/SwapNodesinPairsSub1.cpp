/* 只交换相邻两个node的val
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
    ListNode* swapPairs(ListNode* head) {
        if (head==NULL) return head;
        ListNode *p1=head, *p2=head->next;
        while (p2) {
            int tmp = p1->val;
            p1->val = p2->val;
            p2->val = tmp;
            if (p2->next==NULL) return head;
            p1 = p2->next;
            p2 = p2->next->next;
            
        }
        return head;
    }
};