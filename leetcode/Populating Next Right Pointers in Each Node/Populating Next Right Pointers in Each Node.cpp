/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }
        queue<TreeLinkNode *> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            TreeLinkNode *lastnode = NULL;
            for (int i = 0; i < size; ++i) {
                TreeLinkNode *node = que.front();
                que.pop();
                if (!i) {
                    lastnode = node;
                } else if (i < size - 1) {
                    lastnode->next = node;
                    lastnode = node;
                } else if (i == size - 1) {
                    if (lastnode != NULL) {
                        lastnode->next = node;
                    }
                    node->next = NULL;
                }
                if (node->left != NULL) {
                    que.push(node->left);
                }
                if (node->right != NULL) {
                    que.push(node->right);
                }
            }
        }
    }
};
