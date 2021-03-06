/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
        if (!head || !head->next) return head;
        ListNode* p = new ListNode(0);
        p->next = head;
        head = p;
        while (p->next && p->next->next) {
            ListNode* q1 = p->next;
            ListNode* q2 = q1->next;
            q1->next = q2->next;
            q2->next = q1;
            p->next = q2;
            p = q1;
        }
        return head->next;
    }
};
