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
    int sumOfLeftLeaves(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        ans = 0;
        addLeftLeaves(root, false);
        return ans;
    }
private:
    int ans;
    void addLeftLeaves(TreeNode *node, bool isLeft) {
        if (node->left == NULL && node->right == NULL && isLeft) {
            ans += node->val;
            return;
        }
        if (node->left != NULL) {
            addLeftLeaves(node->left, true);
        }
        if (node->right != NULL) {
            addLeftLeaves(node->right, false);
        }
    }
};
