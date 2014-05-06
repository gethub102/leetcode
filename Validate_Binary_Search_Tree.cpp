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
    bool isValidBST(TreeNode* root) {
        return isValidBSTRecursion(root, INT_MIN, INT_MAX);
    }

    bool isValidBSTRecursion(TreeNode* root, int low, int high) {
        if (!root) {
            return true;
        }
        if (low < root->val && root->val < high) {
            return isValidBSTRecursion(root->left, low, root->val) && isValidBSTRecursion(root->right, root->val, high);
        } else {
            return false;
        }
    }
};
