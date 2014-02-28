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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* tmp = new ListNode(0);
        result -> next = tmp;
        int digit;
        bool carry = false;
        while (l1 || l2) {
            digit = 0;
            tmp -> next = new ListNode(0);
            tmp = tmp-> next;
            if (l1) {
                digit += l1->val;
                l1 = l1 -> next;
            }
            if (l2) {
                digit += l2->val;
                l2 = l2 -> next;
            }
            if (carry) {
                digit ++;
            }
            if (digit >= 10) {
                digit -= 10;
                carry = true;
            } else {
                carry = false;
            }
            tmp -> val = digit;
        }
        if (carry) {
            tmp -> next = new ListNode(0);
            tmp = tmp-> next;
            tmp -> val = 1;
        }
        return result->next->next;
    }
};