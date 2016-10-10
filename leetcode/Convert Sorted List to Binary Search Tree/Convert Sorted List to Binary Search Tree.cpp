/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        int listLen = 1;
        ListNode *node = head;
        while (node->next != NULL) {
            listLen++;
            node = node->next;
        }
        return buildBST(head, listLen);
    }
private:
    TreeNode* buildBST(ListNode *head, int listLen) {
        if (head == NULL || listLen == 0) {
            return NULL;
        }
        int nodeCount = 0;
        ListNode *node = head;
        while (node->next != NULL && nodeCount != listLen / 2) {
            nodeCount++;
            node = node->next;
        }
        TreeNode *root = new TreeNode(node->val);
        root->left = buildBST(head, nodeCount);
        root->right = buildBST(node->next, listLen - 1 - nodeCount);
        return root;
    }
};
