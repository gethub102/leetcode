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
        if (!head || !head->next)return head;
        ListNode* p = head->next;
        // 1st and 2nd has Duplicates
        if (head->val == p->val) {
            while (head->val == p->val) {
                p = p->next;
                if (!p)break;
            }
            return deleteDuplicates(p);
        }
        // 1st and 2nd no Duplicates
        head->next = deleteDuplicates(head->next);
        return head;
    }
};