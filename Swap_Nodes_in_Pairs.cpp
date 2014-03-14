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