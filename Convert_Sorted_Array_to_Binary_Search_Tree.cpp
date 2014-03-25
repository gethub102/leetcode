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
    TreeNode* sortedArrayToBST(vector<int>& num) {
        TreeNode* root = NULL;
        sortedArrayToBSTRecursion(num, 0, num.size() - 1, root);
        return root;
    }

    void sortedArrayToBSTRecursion(vector<int>& num, int begin, int end, TreeNode*& root) {
        if (begin > end) return;
        root = new TreeNode(num[(begin + end) / 2]);
        sortedArrayToBSTRecursion(num, begin, (begin + end) / 2 - 1, root->left);
        sortedArrayToBSTRecursion(num, (begin + end) / 2 + 1, end, root->right);
    }
};
