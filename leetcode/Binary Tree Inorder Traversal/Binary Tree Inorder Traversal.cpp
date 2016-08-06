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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        traversal(root, vec);
        return vec;
    }
private:
    void traversal(TreeNode *node, vector<int> &vec) {
        if (node == NULL) {
            return;
        }
        if (node->left) {
            traversal(node->left, vec);
        }
        vec.push_back(node->val);
        traversal(node->right, vec);
    }
};
