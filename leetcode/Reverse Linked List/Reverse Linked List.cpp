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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        stack<int> st;
        ListNode* node = head;
        while (1) {
            st.push(node->val);
            if (node->next == NULL) {
                break;
            }
            node = node->next;
        }
        ListNode* newhead = new ListNode(0);
        node = newhead;
        while (1) {
            node->val = st.top();
            st.pop();
            if (st.empty()) {
                node->next = NULL;
                break;
            }
            node->next = new ListNode(0);
            node = node->next;
        }
        return newhead;
    }
};
