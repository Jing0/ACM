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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return ans;
        }
        vector<int> vec;
        rootToLeaf(root, vec, 0, sum);
        return ans;
    }
private:
    vector<vector<int>> ans;
    void rootToLeaf(TreeNode *node, vector<int> vec, int sum, int target) {
        sum = sum + node->val;
        vec.push_back(node->val);
        if (node->left == NULL && node->right== NULL && sum == target) {
            ans.push_back(vec);
            return;
        }
        if (node->left != NULL) {
            rootToLeaf(node->left, vec, sum, target);
        }
        if (node->right != NULL) {
            rootToLeaf(node->right, vec, sum, target);
        }
    }
};
