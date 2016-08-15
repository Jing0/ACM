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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *node = head, *odd = NULL, *even = NULL;
		int count = 0;
		while (node != NULL) {
			ListNode *p = node->next;
			if (!count) {
				even = node;
			} else if (count == 1) {
				odd = node;
			} else if (count % 2) {
				ListNode *t = odd->next;
				odd->next = node;
				node->next = t;
				odd = odd->next;
			} else {
				ListNode *t = even->next;
				even->next = node;
				node->next = t;
				even = even->next;
			}
			count++;
			node = p;
		}
		if (count == 1) {
		    even->next = NULL;
		} else {
		    odd->next = NULL;
		}
		return head;
    }
};

