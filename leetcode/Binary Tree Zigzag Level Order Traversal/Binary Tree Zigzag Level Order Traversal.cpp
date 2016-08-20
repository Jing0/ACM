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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode *> que;
        stack<TreeNode *> st;
        int count;
        que.push(root);
        bool even = true;
        while (!que.empty()) {
           int count = que.size();
           vector<int> vec;
           while (count--) {
               TreeNode *node = que.front();
               que.pop();
               vec.push_back(node->val);
               if (even) {
                   if (node->left != NULL) {
                       st.push(node->left);
                   }
                   if (node->right != NULL) {
                       st.push(node->right);
                   }
               } else {
                   if (node->right != NULL) {
                       st.push(node->right);
                   }
                   if (node->left != NULL) {
                       st.push(node->left);
                   }
               }
           }
           ans.push_back(vec);
           while (!st.empty()) {
               que.push(st.top());
               st.pop();
           }
           even = !even;
        }
        return ans;
    }
};
