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
        ListNode* smallNodeHead = new ListNode(0);
        ListNode* largeNodeHead = new ListNode(0);
        ListNode* smallNode = new ListNode(0);
        ListNode* largeNode = new ListNode(0);
        smallNodeHead ->next = smallNode;
        largeNodeHead ->next = largeNode;
        while (head) {
            if (head->val < x) {
                smallNode->next = new ListNode(head->val);
                smallNode = smallNode->next;
            } else {
                largeNode->next = new ListNode(head->val);
                largeNode = largeNode->next;
            }
            head = head->next;
        }
        smallNode ->next = largeNodeHead->next->next;
        return smallNodeHead->next->next;
    }
};