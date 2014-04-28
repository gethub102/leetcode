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
        if (!root) {
            return result;
        }
        // Create an empty stack and push root to it
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);

        /* Pop all items one by one. Do following for every popped item
           a) print it
           b) push its right child
           c) push its left child
        Note that right child is pushed first so that left is processed first */
        while (!nodeStack.empty()) {
            // Pop the top item from stack and print it
            TreeNode* node = nodeStack.top();
            result.push_back(node -> val);
            nodeStack.pop();

            // Push right and left children of the popped node to stack
            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }
        return result;
    }
};
