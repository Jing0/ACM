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
        if (head == NULL) {
            return NULL;
        }
        set<int> s;
        vector<int> ve;
        ListNode *node = head;
        while (1) {
            int nval = node->val;
            if (!s.count(nval)) {
                ve.push_back(nval);
                s.insert(nval);
            }
            if (node->next == NULL) {
                break;
            }
            node = node->next;
        }
        int size = ve.size();
        ListNode *newhead = new ListNode(0);
        node = newhead;
        for (int i = 0; i < size; ++i) {
            node->val = ve.at(i);
            if (i < size - 1) {
                node->next = new ListNode(0);
                node = node->next;
            } else {
                node->next = NULL;
            }
        }
        return newhead;
    }
};
