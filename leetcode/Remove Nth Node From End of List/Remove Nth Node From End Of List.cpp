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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode *> vec;
        ListNode *node = head;
        while (node != NULL) {
            vec.push_back(node);
            node = node->next;
        }
        int size = vec.size();
        if (size == 1 && n == 1) {
            return NULL;
        } else if(n == size) {
            head = vec.at(1);
            //free(vec.at(0));
        } else {
            vec.at(size - 1 - n)->next = vec.at(size - n)->next;
            free(vec.at(size - n));
        }
        return head;
    }
};
