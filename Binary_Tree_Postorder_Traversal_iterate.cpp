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
        if (!root) {
            return result;
        }
        stack<TreeNode* > nodeStack;
        TreeNode* ptr = root;
        TreeNode* temp;
        bool flags;
        do {
            while (ptr != NULL) {
                nodeStack.push(ptr);
                ptr = ptr->left;
            }
            temp = NULL;
            flags = true;

            while (flags && !nodeStack.empty()) {
                ptr = nodeStack.top();
                if (ptr->right == temp) {
                    result.push_back(ptr->val);
                    nodeStack.pop();
                    temp = ptr;
                } else {
                    ptr = ptr->right;
                    flags = false;
                }
            }
        } while (!nodeStack.empty());
        return result;
    }
};
