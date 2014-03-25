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
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* rightChild = root->right;
        TreeNode* leftChild = root->left;
        if (leftChild) {
            root->right = leftChild;
            root->left = NULL;
            flatten(leftChild);
            while (leftChild->right) {
                leftChild = leftChild->right;
            }
            leftChild->right = rightChild;
        }
        flatten(rightChild);
    }
};
