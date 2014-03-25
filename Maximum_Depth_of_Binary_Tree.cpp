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
    int maxDepth(TreeNode* root) {
        return maxDepthRecursion(root, 0);
    }

    int maxDepthRecursion(TreeNode* root, int level) {
        if (!root) return level;
        return max(maxDepthRecursion(root->left, level + 1), maxDepthRecursion(root->right, level + 1));
    }
};
