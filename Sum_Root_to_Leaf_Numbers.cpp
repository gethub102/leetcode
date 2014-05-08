/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    int sumNumbers(TreeNode* root) {
        return sumNumbersRecursion(root, 0) ;
    }

    int sumNumbersRecursion(TreeNode* root, int parent) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return parent + root->val;
        }
        return sumNumbersRecursion(root->left, 10 * (parent + root->val)) + sumNumbersRecursion(root->right, 10 * (parent + root->val));
    }
};
