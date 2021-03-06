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
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while (true) {

            fast = fast->next;
            if (!fast) break;
            fast = fast->next;
            if (!fast) break;
            slow = slow -> next;
        }
        if (!slow) return;

        // reverse second half of link list
        // this is median node
        ListNode* cur = slow;
        // this is median->next node;
        ListNode* pre = slow->next;
        // median ->next point to NULL
        cur->next = NULL;
        // when we not reach the original list end
        while (pre != NULL) {
            // store median->next->next
            ListNode* temp = pre->next;
            // point median->next 's next to median
            pre->next = cur;
            // pointer move ,now cur is median->next;
            cur = pre;
            // pointer move, noew pre is median->next->next'
            pre = temp;
        } // loop, so the right part of list is totally reverse.

        // merge two lists
        ListNode* first = head;
        ListNode* second = cur; // finally pre is null, cur is the orignal end

        while (second && first && first != second) {
            ListNode* temp = second->next;
            // point 4->2
            second->next = first->next;
            // point 1->4
            first->next = second;
            // move first pointer from  the 1 in 1->4->2, to 2 in 1->4->2;
            first = second->next;
            // move second pointer from 4  to 3
            second = temp;
        }
    }
};
