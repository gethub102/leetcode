/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* current = result;
        bool carry =  false;
        while (l1 || l2) {
            int digit = 0;
            if (l1) {
                digit += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                digit += l2->val;
                l2 = l2->next;
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
            current->next = new ListNode(digit);
            current = current->next;
        }
        if (carry) {
            current -> next = new ListNode(1);
        }
        return result -> next;
    }
};
