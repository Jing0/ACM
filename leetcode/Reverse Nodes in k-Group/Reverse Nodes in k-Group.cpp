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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *node = head, *rest;
        vector<ListNode *> vec;
        int i;
        for (i = 0; node != NULL && i < k; ++i) {
            vec.push_back(node);
            node = node->next;
        }
        if (node == NULL && i < k) {
            return head;
        }
        rest = node;
        for (int i = k - 1; i >= 0; --i) {
            if (i == k - 1) {
                head = node = vec.at(i);
            } else {
                node->next = vec.at(i);
                node = node->next;
            }
        }
        node->next = reverseKGroup(rest, k);
        return head;
    }
};
