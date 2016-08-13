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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lastnode, *node, *pivot;
        lastnode = NULL;
        node = head;
        while (node != NULL) {
            if (node->val >= x) {
                break;
            }
            lastnode = node;
            node = node->next;
        }
        pivot = lastnode;
        while (node != NULL) {
            if (node->val < x) {
                lastnode->next = node->next;
                if (pivot == NULL) {
                    pivot = node;
                    pivot->next = head;
                    head = pivot;
                } else {
                    ListNode *tmp = pivot->next;
                    pivot->next = node;
                    node->next = tmp;
                    pivot = pivot->next;
                }
                node = lastnode->next;
            } else {
                lastnode = node;
                node = node->next;
            }
        }
        return head;
    }
};
