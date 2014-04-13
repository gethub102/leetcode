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
        return isBSTHelper(root, INT_MIN, INT_MAX);
    }

    bool isBSTHelper(TreeNode* p, int low, int high) {
        if (!p) return true;
        if (low < p->val && p->val < high)
            return isBSTHelper(p->left, low, p->val) &&
                   isBSTHelper(p->right, p->val, high);
        else
            return false;
    }
};
