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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            int count = que.size();
            for (int i = 0; i < count; ++i) {
                TreeNode *node = que.front();
                que.pop();
                if (i == count - 1) {
                    ans.push_back(node->val);
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
