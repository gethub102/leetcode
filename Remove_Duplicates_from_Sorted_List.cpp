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
        ListNode* current = head;
        while (current) {
            while (current->next && current->next->val == current->val) {
                current ->next = current->next->next;
            }
            current = current ->next;
        }
        return head;
    }
};
