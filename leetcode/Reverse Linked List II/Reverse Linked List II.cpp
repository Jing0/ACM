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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *node, *pivot, *lastnode;
        node = lastnode = head;
        pivot = NULL;
        vector<ListNode*> vec;
        for (int i = 0; i < n; ++i) {
            if (i == m - 2) {
                pivot = node;
            } else if (i > m - 1) {
                lastnode->next = node->next;
                if (pivot == NULL) {
                    node->next = head;
                    head = node;
                } else {
                    ListNode *tmp = pivot->next;
                    pivot->next = node;
                    node->next = tmp;
                }
            }
            if (i <= m - 1) {
                lastnode = node;
                node = node->next;
            } else {
                node = lastnode->next;
            }
        }
        return head;
    }
};
