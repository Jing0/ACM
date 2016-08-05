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
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return true;
        }
        vector<int> ve;
        ListNode *node = head;
        do {
            int nval = node->val;
            ve.push_back(nval);
            node = node->next;
        } while (node != NULL);
        int size = ve.size();
        for (int i = 0; i < size / 2; ++i) {
            if (ve.at(i) != ve.at(size - 1 -i)) {
                return false;
            }
        }
        return true;
    }
};
