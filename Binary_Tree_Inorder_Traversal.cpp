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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTraversalRecursion(root, result);
        return result;
    }

    void inorderTraversalRecursion(TreeNode* root, vector<int>& result) {
        if (!root)return;
        inorderTraversalRecursion(root->left, result);
        result.push_back(root->val);
        inorderTraversalRecursion(root->right, result);
    }
};
