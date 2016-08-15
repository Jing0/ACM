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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) {
            return ans;
        }
        rootToLeaf(root, root, "");
        return ans;
    }
private:
    vector<string> ans;
    void rootToLeaf(TreeNode *root, TreeNode *node, string path) {
        if (node == root) {
            path = path + to_string(node->val);
        } else {
            path = path + "->" + to_string(node->val);
        }
        if (node->left == NULL && node->right == NULL) {
            ans.push_back(path);
            return;
        }
        if (node->left != NULL) {
            rootToLeaf(root, node->left, path);
        }
        if (node->right != NULL) {
            rootToLeaf(root, node->right, path);
        }
    }
};
