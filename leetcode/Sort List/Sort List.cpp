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
    ListNode* sortList(ListNode* head) {
        list<int> li;
        ListNode *node = head;
        while (node != NULL) {
            li.push_back(node->val);
            node = node->next;
        }
        li.sort();
        node = head;
        while (node != NULL) {
            node->val = li.front();
            li.pop_front();
            node = node->next;
        }
        return head;
    }
};
