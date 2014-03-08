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
        if (!root) return true;
        vector<int> inorder;
        isValidBSTinorder(root,  inorder);
        for (int i = 0; i < inorder.size() - 1; i++) {
            if (inorder[i] >= inorder[i + 1]) return false;
        }
        return true;
    }

    void isValidBSTinorder(TreeNode* root, vector<int>& inorder) {
        if (!root) return;
        isValidBSTinorder(root->left, inorder);
        inorder.push_back(root->val);
        isValidBSTinorder(root->right, inorder);
    }
};