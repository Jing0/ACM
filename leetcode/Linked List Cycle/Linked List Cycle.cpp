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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast != NULL) {
            if (fast->next != NULL && fast->next->next != NULL) {
                fast = fast->next->next;
            } else {
                break;
            }
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};
