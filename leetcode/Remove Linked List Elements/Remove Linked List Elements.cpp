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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return head;
        }
        queue<int> que;
        ListNode *node = head;
        while (node->next != NULL) {
            int nval = node->val;
            if (nval != val) {
                que.push(nval);
            }
            node = node->next;
        }
        if (node->val != val) {
            que.push(node->val);
        }
        
        if (que.empty()) {
            return NULL;
        }
        ListNode *newhead = new ListNode(0);
        node = newhead;
        while (que.size() > 1) {
            node->val = que.front();
            que.pop();
            node->next = new ListNode(0);
            node = node->next;
        }
        node->val = que.front();
        node->next = NULL;
        return newhead;
    }
};
