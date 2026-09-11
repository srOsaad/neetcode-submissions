/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */

public class Solution {
    public ListNode RemoveNthFromEnd(ListNode head, int n) {
        int count = 0;
        ListNode current = head;
        
        while(current != null) {
            count++;
            current = current.next;
        }

        if(count == n) {
            head = head.next;
            return head;
        }

        count -= ++n;

        current = head;

        while(count>0) {
            count--;
            current = current.next;
        }

        ListNode hold = current.next;
        current.next = null;

        if(hold.next != null) {
            current.next = hold.next;
        }

        return head;
    }
}
