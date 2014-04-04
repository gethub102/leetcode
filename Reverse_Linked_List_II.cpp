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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        int index = 0;
        ListNode* p = new ListNode(0);
        ListNode* q = p;
        p->next = head;
        ListNode* pre = NULL;
        ListNode* end = NULL;
        while (p) {
            if (index == m - 1) pre = p;
            if (index == n) {
                end = p;
                break;
            }
            index++;
            p = p->next;
        }
        reverseListNodeFromTo(pre, end);
        return q->next;
    }

    /*
    *  for 1->2->3->4->5
    *  input (listnode(1),listnode(4))
    *   return 1->4->3-2->5
    */

    void reverseListNodeFromTo(ListNode* pre, ListNode* end) {
        ListNode* first = pre->next;
        ListNode* second = pre->next->next;
        first->next = end-> next;
        while (second != end) {
            ListNode* new_second = second->next;
            second->next = first;
            first = second;
            second = new_second;
        }
        pre->next = end;
        second->next = first;
    }
};
