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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        vector<int> currentPath;
        pathSumRecursion(result, currentPath, root, sum);
        return result;
    }

    void pathSumRecursion(vector<vector<int> >& result, vector<int> currentPath, TreeNode* root, int sum) {
        if (!root) return;
        if (root->val == sum && !(root->left) && !(root->right)) {
            currentPath.push_back(root->val);
            result.push_back(currentPath);
            return;
        } else {
            currentPath.push_back(root->val);
            pathSumRecursion(result, currentPath, root->left, sum - root->val);
            pathSumRecursion(result, currentPath, root->right, sum - root->val);
        }
    }
};
