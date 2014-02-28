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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderTraversalRecursion(root, result);
        return result;
    }

    void postorderTraversalRecursion(TreeNode* root, vector<int>& result) {
        if (!root) return;
        postorderTraversalRecursion(root->left, result);
        postorderTraversalRecursion(root->right, result);
        result.push_back(root->val);
    }
};
