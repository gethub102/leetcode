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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mid = getMiddle(head);
        ListNode* right = mid->next;
        mid->next = NULL;
        return mergeList(sortList(head), sortList(right));
    }

    ListNode* getMiddle(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeList(ListNode* left, ListNode* right) {
        ListNode* current = new ListNode(0);
        ListNode* result = current;
        while (left && right) {
            if (left->val < right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }
        current->next = left ? left : right;
        return result->next;
    }
};
