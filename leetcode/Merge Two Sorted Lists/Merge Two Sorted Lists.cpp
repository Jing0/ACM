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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }
        ListNode *lastnode, *head;
        if (l1->val < l2->val) {
            head = lastnode = l1;
            l1 = l1->next;
        } else {
            head = lastnode = l2;
            l2 = l2->next;
        }
        while (l1 != NULL && l2 != NULL) {
            ListNode *node;
            if (l1->val < l2->val) {
                node = l1;
                l1 = l1->next;
            } else {
                node = l2;
                l2 = l2->next;
            }
            lastnode->next = node;
            lastnode = node;
        }
        if (l1 == NULL) {
            l1 = l2;
        }
        lastnode->next = l1;
        return head;
    }
};
