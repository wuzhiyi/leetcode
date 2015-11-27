/* 三个模块：找中点，翻转和比较
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
    ListNode* findMid(ListNode* head) {
        ListNode *p1=head, *p2=head;
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* tmp = NULL;
        while (head) {
            ListNode *suc = head->next;
            head->next = tmp;
            tmp = head;
            head = suc;
        }
        return tmp;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* pmid = findMid(head);
        ListNode* pr = reverseList(pmid);
        ListNode* pl = head;
        for (; pl != pmid; pl=pl->next, pr=pr->next) {
            if (pl->val != pr->val) {
                return false;
            }
        }
        return true;
    }
};