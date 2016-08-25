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
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> all, dup;
        ListNode *node = head;
        while (node != NULL) {
            int val = node->val;
            if (all.count(val)) {
                dup.insert(val);
            } else {
                all.insert(val);
            }
            node = node->next;
        }
        node = head;
        ListNode *prenode = NULL;
        while (node != NULL) {
            int val = node->val;
            if (dup.count(val)) {
                if (prenode == NULL) {
                    head = head->next;
                } else {
                    prenode->next = node->next;
                }
            } else {
                prenode = node;
            }
            node = node->next;
        }
        return head;
    }
};
