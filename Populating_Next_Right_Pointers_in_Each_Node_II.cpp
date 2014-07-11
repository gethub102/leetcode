/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/
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
        if (!root) {
            return;
        }
        // assume we have build this level's next, now work on next level
        TreeLinkNode* current = root->next;
        while (current) {
            if (current->left) {
                current = current->left;
                break;
            }
            if (current->right) {
                current = current->right;
                break;
            }
            current = current->next;
        }
        if (root->right) {
            root->right->next = current;
        }
        if (root->left) {
            root->left->next = root->right ? root->right : current;
        }
        // first right, then left!!!
        connect(root->right);
        connect(root->left);
    }
};
