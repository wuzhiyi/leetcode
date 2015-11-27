/* 我只写了 iterative reverse
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
    ListNode* reverseList(ListNode* head) {
        ListNode *h=NULL, *p=NULL;
        while (head) {
            p = head->next;
            head->next = h;
            h = head;
            head = p;
        }
        return h;
    }
};