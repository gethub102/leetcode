/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode* root) {
        while (root) {
            TreeLinkNode* ptr = root;
            while (ptr) {
                if (ptr->left) ptr->left->next = ptr->right;
                if (ptr->right  && ptr->next) ptr->right->next = ptr->next->left;
                ptr = ptr->next;
            }
            root = root->left;
        }
    }
};