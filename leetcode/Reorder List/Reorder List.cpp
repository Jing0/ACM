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
    void reorderList(ListNode* head) {
        vector<int> vec;
        ListNode *node = head;
        while (node != NULL) {
            vec.push_back(node->val);
            node = node->next;
        }
        node = head;
        int size = vec.size();
        for (int count = 0; node != NULL; ++count) {
            if (count % 2 == 0) {
                node->val = vec.at(count / 2);
            } else {
                node->val = vec.at(size - 1 - count / 2);
            }
            node = node->next;
        }
    }
};
