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
        if (!root) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> currentLevel;
            int currentSize = q.size();
            for (int i = 0; i < currentSize; i++) {
                TreeNode* currentNode = q.front();
                currentLevel.push_back(currentNode->val);
                if (currentNode->left)q.push(currentNode->left);
                if (currentNode->right)q.push(currentNode->right);
                q.pop();
            }
            result.push_back(currentLevel);
        }
        return result;
    }
};
