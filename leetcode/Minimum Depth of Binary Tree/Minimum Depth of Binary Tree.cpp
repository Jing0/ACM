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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int ans = 0;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            int count = que.size();
            ans++;
            while (count--) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left == NULL && node->right == NULL) {
                    return ans;
                }
                if (node->left != NULL) {
                    que.push(node->left);
                }
                if (node->right != NULL) {
                    que.push(node->right);
                }
            }
        }
        return ans;
    }
};

