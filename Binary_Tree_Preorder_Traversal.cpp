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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderTraversalRecursion(root, result);
        return result;
    }

    void preorderTraversalRecursion(TreeNode* root, vector<int>& result) {
        if (!root) return;
        result.push_back(root->val);
        preorderTraversalRecursion(root->left, result);
        preorderTraversalRecursion(root->right, result);
    }
};
