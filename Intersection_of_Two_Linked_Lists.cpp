/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) {
            return NULL;
        }
        ListNode* current = headA;
        while (current->next) {
            current = current->next;
        }
        current->next = headB; // create a cycle
        ListNode* slow = headA;
        ListNode* fast = headA;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        if (!fast || !fast->next) {
            current->next = NULL; // restore back
            return NULL;
        }
        slow = headA;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        current->next = NULL; // restore back
        return slow;
    }
};
