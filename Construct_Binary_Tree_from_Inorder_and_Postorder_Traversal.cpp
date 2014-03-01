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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder,
                        int inorder_begin, int inorder_end,
                        int postorder_begin, int  postorder_end) {
        if (inorder_begin > inorder_end   || postorder_begin >  postorder_end) return NULL;
        else if (inorder_begin == inorder_end || postorder_begin == postorder_end) {
            return new TreeNode(inorder[inorder_begin]);
        } else {
            TreeNode* root = new TreeNode(postorder[postorder_end]);
            int gap = distance(inorder.begin() + inorder_begin,
                               find(inorder.begin() + inorder_begin, inorder.begin() + inorder_begin + inorder_end, postorder[postorder_end]));
            root->left = buildTree(inorder, postorder, inorder_begin, inorder_begin + gap - 1, postorder_begin, postorder_begin + gap - 1);
            root->right = buildTree(inorder, postorder, inorder_begin + gap + 1, inorder_end, postorder_begin + gap, postorder_end - 1);
            return root;
        }
    }
};
