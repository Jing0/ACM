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
    bool isBalanced(TreeNode* root) {
        if (height(root) == -1) {
            return false;
        }
        return true;
    }
private:
    int height(TreeNode *node) {
        if (node == NULL) {
            return 0;
        }
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight < 0 || rheight < 0 || lheight - rheight > 1 || rheight - lheight > 1) {
            return -1;
        }
        return max(lheight, rheight) + 1;
    }
};
