/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//version 1 recursion
class Solution {
  public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTraversalRecursion(root, result);
        return result;
    }

    void inorderTraversalRecursion(TreeNode* root, vector<int>& result) {
        if (!root) {
            return;
        }
        inorderTraversalRecursion(root->left, result);
        result.push_back(root->val);
        inorderTraversalRecursion(root->right, result);
    }
};

// version 2 iterator
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
        stack<TreeNode*> myStack;
        TreeNode* current = root;
        while (current || !myStack.empty()) {
            if (current) {
                myStack.push(current->right);
                myStack.push(current);
                current = current->left;
            } else {
                result.push_back(myStack.top()->val);
                myStack.pop();
                current = myStack.top();
                myStack.pop();
            }
        }
        return result;
    }
};

// version 3 morris
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
        if (!root) {
            return result;
        }
        TreeNode* current = root, *prev = NULL;
        while (current) {
            if (!current->left) {
                result.push_back(current->val);
                current = current->right;
            } else {
                prev = current->left;
                while (prev->right && prev->right != current) {
                    prev = prev->right;
                }
                if (!prev->right) {
                    prev->right = current;
                    current = current->left;
                } else {
                    prev->right = NULL;
                    result.push_back(current->val);
                    current = current->right;
                }
            }
        }
        return result;
    }
};
