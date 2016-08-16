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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        return rootToLeaf(root, 0, sum);
    }
private:
    bool rootToLeaf(TreeNode *node, int sum, int target) {
        sum = sum + node->val;
        if (node->left == NULL && node->right== NULL) {
            return sum == target;
        }
        if (node->left != NULL) {
            if (rootToLeaf(node->left, sum, target)) {
                return true;
            }
        }
        if (node->right != NULL) {
            if (rootToLeaf(node->right, sum, target)) {
                return true;
            }
        }
        return false;
    }
};
