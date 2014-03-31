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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;
        int index = 0;
        ListNode* p = head;
        while (p) {
            index++;
            p = p->next;
        }
        if (index < k) return head;
        ListNode* result = new ListNode(0);
        result -> next = head;
        ListNode* previous = result;
        ListNode* q = head;
        index = 0;
        while (q) {
            index = (index + 1) % k;
            if (index == 0) {
                ListNode* tmp = q->next;
                ListNode* new_previous = previous->next;
                reverseFrom(previous, q);
                previous = new_previous;
                q = tmp;
            } else {
                q = q->next;
            }
        }
        return result->next;
    }
    /**
     *   for (0)->1->2->3->x
     *   input 0,3
     *    return (0)->3->2->1->x
     **/
    void reverseFrom(ListNode* previous, ListNode* end) {
        ListNode* new_end = previous->next;
        ListNode* the_x = end->next;
        ListNode* first = previous->next;
        ListNode* second = previous->next->next;
        while (second != end) {
            ListNode* new_second = second->next;
            second->next = first;
            first = second;
            second = new_second;
        }
        second->next = first;
        previous->next = second;
        new_end->next = the_x;
    }
};
