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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        stack<vector<int>> ansst;
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            int count = que.size();
            vector<int> ve;
            while (count--) {
                TreeNode *node = que.front();
                que.pop();
                ve.push_back(node->val);
                if (node->left != NULL) {
                    que.push(node->left);
                }
                if (node->right != NULL) {
                    que.push(node->right);
                }
            }
            if (!ve.empty()) {
                ansst.push(ve);
            }
        }
        while (!ansst.empty()) {
            ans.push_back(ansst.top());
            ansst.pop();
        }
        return ans;
    }
};
