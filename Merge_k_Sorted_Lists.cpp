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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // special cases
        if (lists.empty()) return NULL;
        if (lists.size() == 1) return lists[0];
        // recursion
        if (lists.size() > 2) {
            ListNode* first = lists.back();
            lists.pop_back();
            ListNode* second = mergeKLists(lists);
            vector<ListNode*> two;
            two.push_back(first);
            two.push_back(second);
            return mergeKLists(two);
        }
        // merge 2 lists
        if (!lists[0] && !lists[1]) return NULL;
        if (lists[0] && !lists[1]) return lists[0];
        if (lists[1] && !lists[0]) return lists[1];
        ListNode* result = new ListNode(0);
        ListNode* newNode = new ListNode(0);
        result->next = newNode;
        ListNode* first = lists[0];
        ListNode* second = lists[1];
        while (first && second) {
            if (first->val < second -> val) {
                newNode -> next = new ListNode(first->val);
                newNode = newNode->next;
                first = first->next;
            } else {
                newNode -> next = new ListNode(second->val);
                newNode = newNode->next;
                second = second->next;
            }
        }
        while (first) {
            newNode -> next = new ListNode(first->val);
            newNode = newNode->next;
            first = first->next;
        }
        while (second) {
            newNode -> next = new ListNode(second->val);
            newNode = newNode->next;
            second = second->next;
        }
        return result->next->next;
    }
};