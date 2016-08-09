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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *node;
        int carry = 0;
        while (l1 != NULL && l2 != NULL) {
            int sum = carry + l1->val + l2->val;
            if (sum > 9) {
                sum = sum % 10;
                carry = 1;
            } else {
                carry = 0;
            }
            
            if (head == NULL) {
                node = new ListNode(sum);
                head = node;
            } else {
                node->next = new ListNode(sum);
                node = node->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 != NULL) {
            l2 = l1;
        }
        while (l2 != NULL) {
            int sum = carry + l2->val;
            if (sum > 9) {
                sum = sum % 10;
                carry = 1;
            } else {
                carry = 0;
            }
            if (head == NULL) {
                node = new ListNode(sum);
                head = node;
            } else {
                node->next = new ListNode(sum);
                node = node->next;
            }
            l2 = l2->next;
        }
        if (carry) {
            node->next = new ListNode(1);
            node->next->next = NULL;
        }
        return head;
    }
};
