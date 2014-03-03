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
        ListNode* result = new ListNode(0);
        result -> next = head;
        while (head && head ->next) {
            while (head && head ->next && head ->val == head->next->val) {
                head -> next = head->next -> next;
            }
            head = head -> next;
        }
        return result ->next;
    }
};
