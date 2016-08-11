/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *node, *lastnode;
        node = lastnode = head;
        while (node->next != NULL) {
            ListNode *tnode = node->next;
            node->next = tnode->next;
            tnode->next = node;
            if (lastnode == head) {
                head = tnode;
            } else {
                lastnode->next = tnode;
            }
            lastnode = node;
            if (node->next != NULL) {
                node = node->next;
            }
        }
        return head;
    }
};
