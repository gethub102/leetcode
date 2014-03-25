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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder,
                        int preorder_begin, int preorder_end,
                        int inorder_begin, int inorder_end) {
        if (inorder_begin > inorder_end   || preorder_begin >  preorder_end) return NULL;
        else if (inorder_begin == inorder_end   || preorder_begin == preorder_end) {
            return new TreeNode(inorder[inorder_begin]);
        } else {
            TreeNode* root = new TreeNode(preorder[preorder_begin]);
            int gap = distance(inorder.begin() + inorder_begin,
                               find(inorder.begin() + inorder_begin, inorder.begin() + inorder_end, preorder[preorder_begin]));
            root->left = buildTree(preorder, inorder, preorder_begin + 1, preorder_begin + gap, inorder_begin, inorder_begin + gap - 1);
            root->right = buildTree(preorder, inorder, preorder_begin + gap + 1, preorder_end, inorder_begin + gap + 1, inorder_end);
            return root;
        }
    }
};
