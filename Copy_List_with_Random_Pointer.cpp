/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
  public:
    RandomListNode* copyRandomList(RandomListNode* head) {
        if (!head) return NULL;
        RandomListNode* current = head;
        // 1->2->3
        // to 1->1->2->2->3->3
        while (current) {
            RandomListNode* insert = new RandomListNode(current->label);
            insert -> next = current->next;
            current->next = insert;
            current = insert->next;
        }
        // copy the random
        current = head;
        while (current) {
            current->next->random = current->random ? current->random->next : NULL; // important! random may be NULL
            current =  current->next->next;
        }
        // now ,de-merge this list to two, one is original, the other is return;
        current = head;
        RandomListNode* second = new RandomListNode(0);
        RandomListNode* result = second;
        while (current) {
            second->next = current->next;
            second = second->next;
            current->next = current->next->next;
            current = current->next;
        }
        return result->next;
    }
};


// rewrite

class Solution {
  public:
    RandomListNode* copyRandomList(RandomListNode* head) {
        if (!head) {
            return NULL;
        }
        RandomListNode* current  = head;
        while (current) {
            RandomListNode* nextNode = current->next;
            RandomListNode* newNode = new RandomListNode(current->label);
            current->next = newNode;
            newNode->next = nextNode;
            current = nextNode;
        }
        current = head;
        while (current) {
            current->next->random = current->random ? current->random->next : NULL;
            current = current->next->next;
        }
        current = head;
        RandomListNode* result = current->next;
        while (current) {
            RandomListNode* nextNode = current->next->next;
            current->next->next = current->next->next ? current->next->next->next : NULL;
            current->next = nextNode;
            current = current->next;
        }
        return result;
    }
};

