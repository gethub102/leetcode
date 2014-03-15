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
    int minDepth(TreeNode* root) {
        return minDepthRecursion(root, 0);
    }

    int minDepthRecursion(TreeNode* root, int level) {
        if (!root) return level;
        if (!root->left && !root->right) return level + 1;
        if (!root->left && root->right) return minDepthRecursion(root->right, level + 1);
        if (root->left && !root->right) return minDepthRecursion(root->left, level + 1);
        else return min(minDepthRecursion(root->left, level + 1), minDepthRecursion(root->right, level + 1));
    }
};