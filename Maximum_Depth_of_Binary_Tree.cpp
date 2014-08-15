/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// first one
class Solution {
  public:
    int maxDepth(TreeNode* root) {
        return maxDepthRecursion(root, 0);
    }

    int maxDepthRecursion(TreeNode* root, int level) {
        if (!root) {
            return level;
        }
        return max(maxDepthRecursion(root->left, level + 1), maxDepthRecursion(root->right, level + 1));
    }
};

// second, recursion rewrite

class Solution {
  public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

class Solution {
  public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        int result = 0;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* current  = myQueue.front();
                myQueue.pop();
                if (current->left) {
                    myQueue.push(current->left);
                }
                if (current->right) {
                    myQueue.push(current->right);
                }
            }
            result++;
        }
        return result;
    }
};
