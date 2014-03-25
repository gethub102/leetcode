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
    ListNode* rotateRight(ListNode* head, int k) {
        int length = 0;
        ListNode* originalHead = new ListNode(0);
        ListNode* result = new ListNode(0);
        originalHead -> next = head;
        while (head) {
            length++;
            head = head->next;
        }
        if (length == 0) return originalHead -> next;
        k = k % length;
        if (k == 0) return originalHead -> next;
        int index = length - k;
        head = originalHead -> next;
        int i = 0;
        while (head) {
            if (!head->next) {
                head->next = originalHead -> next;
                break;
            }
            i++;
            if (i == index) {
                result->next = head->next;
                head->next = NULL;
                head = result->next;
            } else {
                head = head->next;
            }

        }
        return result->next;
    }
};
