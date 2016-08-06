/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode insertionSortList(ListNode head) {
        ListNode nodei = head;
        while (nodei != null) {
            int val = nodei.val;
            ListNode lastNode = null;
            boolean flag = true;
            for (ListNode nodej = head; nodej != nodei; nodej = nodej.next) {
                if (val <= nodej.val && flag) {
                    ListNode newNode = new ListNode(val);
                    if (nodej == head) {
                        newNode.next = head;
                        head = newNode;
                    } else {
                        newNode.next = nodej;
                        lastNode.next = newNode;
                    }
                    flag = false;
                }
                lastNode = nodej;
            }
            nodei = nodei.next;
            if (flag == false) {
                lastNode.next = lastNode.next.next;
            }
        }
        return head;
    }
}
