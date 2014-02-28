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
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        levelOrderRecursion(result, root, 0);
        return result;
    }

    void levelOrderRecursion(vector<vector<int> >& result, TreeNode* root, int level) {
        if (!root) return;
        if (result.size() <= level) {
            vector<int> levels;
            levels.push_back(root->val);
            result.push_back(levels);
        } else {
            result[level].push_back(root->val);
        }
        levelOrderRecursion(result, root->left, level + 1);
        levelOrderRecursion(result, root->right, level + 1);
    }
};