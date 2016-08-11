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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return check(root->left, root->right);
    }
private:
    bool check(TreeNode *lt, TreeNode *rt) {
        if (lt == NULL && rt == NULL) {
            return true;
        }
        if (lt == NULL || rt == NULL || (lt->val != rt->val)) {
            return false;
        }
        return check(lt->left, rt->right) && check(lt->right, rt->left);
    }
};
