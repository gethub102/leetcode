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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* tmp = new ListNode(0);
        head -> next = tmp;
        if (!l1 && !l2) return NULL;
        else if (l1 && !l2) return l1;
        else if (!l1 && l2) return l2;
        else {
            while (l1 && l2) {
                tmp -> next = new ListNode(0);
                tmp = tmp -> next;
                if (l1->val < l2->val) {
                    tmp->val = l1->val;
                    l1 = l1-> next;
                } else {
                    tmp->val = l2->val;
                    l2 = l2 -> next;
                }
            }
            while (l1) {
                tmp -> next = new ListNode(l1->val);
                tmp = tmp -> next;
                l1 = l1->next;
            }
            while (l2) {
                tmp -> next = new ListNode(l2->val);
                tmp = tmp -> next;
                l2 = l2->next;
            }
            return head->next->next;
        }
    }
};
