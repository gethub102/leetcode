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
    void recoverTree(TreeNode* root) {
        TreeNode* f1 = NULL, *f2 = NULL;
        TreeNode*  current, *pre, *parent = NULL;
        // 如果 root 空， return
        if (root == NULL)return;
        // 计数用的
        bool found = false;
        // 当前是 root
        current = root;
        while (current) {
            // 如果左孩空，那就走右孩子了
            if (current->left == NULL) {
                // 右孩子应该大，找错误的
                if (parent && parent->val > current->val) {
                    if (!found) {
                        f1 = parent;
                        found = true;
                    }
                    f2 = current;
                }
                // 没事的话，current 赋值给 parent，current 走到右孩子
                parent = current;
                current = current->right;
                // 如果左孩子不空
            } else {
                /* Find the inorder predecessor of current */
                // 先找左孩子，然后一直访问右孩子，直到最后
                pre = current->left;
                // pre->right != current 看后文照应
                while (pre->right != NULL && pre->right != current)
                    pre = pre->right;

                /* Make current as right child of its inorder predecessor */
                // 如果没有建立这个 root->left->right->right->right->right->right 指向 root 的指针
                if (pre->right == NULL) {
                    pre->right = current;
                    current = current->left;
                }

                /* Revert the changes made in if part to restore the original
                tree i.e., fix the right child of predecssor */
                // 已经建立了，绕一圈跑回来了
                else {
                    // 去掉这个临时的指针
                    pre->right = NULL;
                    // 刚才加上指针所以左变右了，所以判断条件一样
                    if (parent->val > current->val) {
                        if (!found) {
                            f1 = parent;
                            found = true;
                        }
                        f2 = current;
                    }
                    parent = current;
                    current = current->right;
                } /* End of if condition pre->right == NULL */
            } /* End of if condition current->left == NULL*/
        } /* End of while */

        if (f1 && f2) swap(f1->val, f2->val);
    }
};
