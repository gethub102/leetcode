/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// first recursion
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
        ListNode* first = lists[0];
        ListNode* second = lists[1];
        if (!first && !second) return NULL;
        if (first && !second) return first;
        if (!first && second) return second;
        ListNode* newNode = new ListNode(0);
        ListNode* result = newNode;
        while (first && second) {
            if (first->val < second -> val) {
                newNode -> next = first;
                first = first->next;
            } else {
                newNode -> next = second;
                second = second->next;
            }
            newNode = newNode->next;
        }
        newNode->next = first ? first : second;
        return result->next;
    }
};

// second use heap

struct compare {
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
  public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        // create min heap
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                minHeap.push(lists[i]);
            }
        }
        ListNode* dummyNode = new ListNode(0);
        ListNode* currentNode = dummyNode;
        while (!minHeap.empty()) {
            ListNode* currentMin = minHeap.top();
            minHeap.pop();
            currentNode->next =  currentMin;
            if (currentMin->next) {
                minHeap.push(currentMin->next);
            }
            currentNode = currentNode->next;
        }
        return dummyNode->next;
    }
};
