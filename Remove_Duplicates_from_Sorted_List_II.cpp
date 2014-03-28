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
        if (head->val == p->val) {
            while (head->val == p->val) {
                p = p->next;
                if (!p)break;
            }
            return deleteDuplicates(p);
        }
        head->next = deleteDuplicates(head->next);
        return head;
    }
};
