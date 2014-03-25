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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        zigzagLevelOrderRecursion(result, root, 0);
        return result;
    }

    void zigzagLevelOrderRecursion(vector<vector<int> >& result, TreeNode* root, int level) {
        if (!root) return;
        if (result.size() <= level) {
            vector<int> levels;
            levels.push_back(root->val);
            result.push_back(levels);
        } else {
            if (level % 2 == 0)result[level].push_back(root->val);
            else result[level].insert(result[level].begin(), root->val);
        }
        zigzagLevelOrderRecursion(result, root->left, level + 1);
        zigzagLevelOrderRecursion(result, root->right, level + 1);
    }
};
