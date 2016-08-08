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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }
        vector<int> vec;
        ListNode *node = head;
        while (node != NULL) {
            vec.push_back(node->val);
            node = node->next;
        }
        int size = vec.size();
        k = k % size;
        node = head;
        for (int i = 0; i < size; ++i) {
            if (i < k) {
                node->val = vec.at(size - k + i);
            } else {
                node->val = vec.at(i - k);
            }
            node = node->next;
        }
        return head;
    }
};
