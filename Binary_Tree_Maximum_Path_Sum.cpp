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
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int result = INT_MIN;
        int max_value = getMax(root, result);
        return max(max_value, result); // 这里也可以写return result; max_value 只有一个孩子，肯定小于等于 result
    }

    int getMax(TreeNode* root, int& result) {
        if (!root) return 0;
        int left = getMax(root->left, result);
        int right = getMax(root->right, result);
        int arch = left + right + root->val; //左右都算
        int single = max(root->val, root->val + max(left, right)); //只算一个孩子；
        result = max(result, max(arch, single)); // 上面两行和自己比，更新自己；
        return single; // return 只算一个孩子的？
    }
};
