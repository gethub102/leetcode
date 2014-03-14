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
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        int result = 0;
        if (root->left) {
            root->left->val = root->left->val + 10 * (root->val);
            result += sumNumbers(root->left);
        }
        if (root->right) {
            root->right->val = root->right->val + 10 * (root->val);
            result += sumNumbers(root->right);
        }
        return result;
    }
};