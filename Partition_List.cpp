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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallNode = new ListNode(0);
        ListNode* largeNode = new ListNode(0);
        ListNode* smallNodeHead = smallNode;
        ListNode* largeNodeHead = largeNode;
        while (head) {
            ListNode* oldNext = head->next;
            if (head->val < x) {
                smallNode->next = head;
                smallNode = smallNode->next;
                smallNode->next = NULL; // cut loop
            } else {
                largeNode->next = head;
                largeNode = largeNode->next;
                largeNode->next = NULL; // cut loop
            }
            head = oldNext;
        }
        smallNode ->next = largeNodeHead->next;
        return smallNodeHead->next;
    }
};