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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        ListNode *nodeA = headA, *nodeB = headB;
        int lenA, lenB;
        lenA = lenB = 1;
        while (nodeA->next != NULL) {
            nodeA = nodeA->next;
            lenA++;
        }
        while (nodeB->next != NULL) {
            nodeB = nodeB->next;
            lenB++;
        }
        if (nodeA != nodeB) {
            return NULL;
        }
        nodeA = headA;
        nodeB = headB;
        if (lenA > lenB) {
            int count = lenA - lenB;
            while (count--) {
                nodeA = nodeA->next;
            }
        } else if (lenB > lenA) {
            int count = lenB - lenA;
            while (count--) {
                nodeB = nodeB->next;
            }
        }
        while (nodeA != nodeB) {
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        return nodeA;
    }
};
