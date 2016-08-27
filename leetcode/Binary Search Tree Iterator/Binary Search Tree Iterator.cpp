/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        this->root = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return root != NULL;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node, *parent;
        node = root;
        parent = NULL;
        while (node->left != NULL) {
            parent = node;
            node = node->left;
        }
        int ans = node->val;
        if (parent == NULL) {
            root = node->right;
        } else {
            parent->left = node->right;
        }
        return ans;
    }
private:
    TreeNode *root;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
