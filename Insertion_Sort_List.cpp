/*
Sort a linked list using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* dummyNode = new ListNode(INT_MIN);
        while (head) {
            ListNode* next = head->next;
            head->next = NULL;
            // for each node
            ListNode* current = dummyNode;
            while (current) {
                if (!current -> next) {
                    current->next = head;
                    break;
                } else if (current->val <= head->val && head->val <= current->next->val) {
                    head->next = current->next;
                    current->next = head;
                    break;
                } else {
                    current = current->next;
                }
            }
            // go to next
            head = next;
        }
        return dummyNode->next;
    }
};
