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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> que;
        vector<vector<int>> ans;
        que.push(root);
        int count;
        while (!que.empty()) {
            vector<int> ve;
            count = que.size();
            while (count--) {
                TreeNode *node = que.front();
                que.pop();
                if (node != NULL) {
                    ve.push_back(node->val);
                    if (node->left) {
                        que.push(node->left);
                    }
                    if (node->right) {
                        que.push(node->right);
                    }
                }
            }
            if (ve.size()) {
                ans.push_back(ve);
            }
        }
        return ans;
    }
};
