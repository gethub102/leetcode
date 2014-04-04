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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode* result = new ListNode(INT_MIN);
        result -> next = head;
        ListNode* toMove = head->next;
        head->next = NULL;
        while (toMove) {
            ListNode* toMoveNext = toMove->next;
            ListNode* tmp = result;
            while (tmp) {
                if (toMove->val >= tmp->val && (tmp->next == NULL || tmp->next->val >= toMove->val)) {
                    toMove ->next = tmp->next;
                    tmp->next = toMove;
                    break;
                }
                tmp = tmp->next;
            }
            toMove = toMoveNext;
        }
        return result->next;
    }
};
