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
    void flatten(TreeNode* root) {
        while (root != NULL && root->left == NULL) {
            root = root->right;
        }
        if (root == NULL) {
            return;
        }
        TreeNode *node = root;
        stack<TreeNode *> st;
        while (node->left != NULL) {
            st.push(node);
            node = node->left;
        }
        TreeNode *lastroot = node;
        while (!st.empty()) {
            TreeNode *parent = st.top();
            st.pop();
            TreeNode *right = parent->right;
            parent->left = NULL;
            parent->right = lastroot;
            while (node->right != NULL) {
                node = node->right;
            }
            node->right = right;
            lastroot = parent;
            flatten(lastroot->right);
        }
    }
};
