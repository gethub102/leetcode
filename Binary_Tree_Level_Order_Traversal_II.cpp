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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        levelOrderBottomRecursion(root, result, 0);
        return result;
    }

    void levelOrderBottomRecursion(TreeNode* root, vector<vector<int> >& result, int level) {
        if (!root) return;
        if (result.empty() || result.size() - level <= 0) {
            vector<int> currentLevel(1, root->val);
            if (result.empty()) result.push_back(currentLevel);
            else result.insert(result.begin(), currentLevel);
        } else {
            result[result.size() - level - 1].push_back(root->val);
        }
        levelOrderBottomRecursion(root->left, result, level + 1);
        levelOrderBottomRecursion(root->right, result, level + 1);
    }
};
