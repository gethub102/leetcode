/*
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
class Solution {
  public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTRecursion(root, INT_MIN, INT_MAX);
    }

    bool isValidBSTRecursion(TreeNode* root, int low, int high) {
        if (!root) {
            return true;
        }
        if (low < root->val && root->val < high) {
            return isValidBSTRecursion(root->left, low, root->val) && isValidBSTRecursion(root->right, root->val, high);
        } else {
            return false;
        }
    }
};
