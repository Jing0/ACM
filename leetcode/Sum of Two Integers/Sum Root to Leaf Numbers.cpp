/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode *> que;
        que.push(root);
        int ans = 0;
        while (!que.empty()) {
            int count = que.size();
            while (count--) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left == NULL && node->right == NULL) {
                    ans += node->val;
                }
                if (node->left != NULL) {
                    node->left->val += node->val * 10;
                    que.push(node->left);
                }
                if (node->right != NULL) {
                    node->right->val += node->val * 10;
                    que.push(node->right);
                }
            }
        }
        return ans;
    }
};
