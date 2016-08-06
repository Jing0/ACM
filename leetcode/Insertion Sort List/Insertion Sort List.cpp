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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *nodei = head;
        while (nodei != NULL) {
            int val = nodei->val;
            ListNode *lastnode;
            bool flag = true;
            for (ListNode *nodej = head; nodej != nodei; nodej = nodej->next) {
                if (val <= nodej->val && flag) {
                    ListNode *newnode = new ListNode(val);
                    if (nodej == head) {
                        newnode->next = nodej;
                        head = newnode;
                    } else {
                        lastnode->next = newnode;
                        newnode->next = nodej;
                    }
                    flag = false;
                }
                lastnode = nodej;
            }
            nodei = nodei->next;
            if (flag == false) {
                ListNode *t = lastnode->next;
                lastnode->next = lastnode->next->next;
                free(t);
            }
        }
        return head;
    }
};
