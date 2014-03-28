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
    vector<TreeNode*> generateTrees(int n) {
        return generateTreesRecursion(1, n);
    }

    vector<TreeNode*>  generateTreesRecursion(int begin, int end) {
        vector<TreeNode*> result;
        if (begin > end) {
            result.push_back(NULL);
            return result;
        }
        for (int i = begin; i <= end; i++) {
            vector<TreeNode*> leftSubtrees = generateTreesRecursion(begin, i - 1);
            vector<TreeNode*> rightSubtrees = generateTreesRecursion(i + 1, end);
            for (int j = 0; j < leftSubtrees.size(); j++) {
                for (int k = 0; k < rightSubtrees.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftSubtrees[j];
                    root->right = rightSubtrees[k];
                    result.push_back(root);
                }
            }
        }
    }
};
