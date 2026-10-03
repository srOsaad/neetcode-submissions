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
    public ListNode MergeTwoLists(ListNode list1, ListNode list2) {
        ListNode answer = null, point = null;

        while (list1 != null && list2 != null) {
            ListNode node = new ListNode();
            if (list1.val < list2.val) {
                node.val = list1.val;
                list1 = list1.next;
            }
            else {
                node.val = list2.val;
                list2 = list2.next;
            }
            if(answer == null) {
                answer = node;
                point = answer;
                continue;
            }
            point.next = node;
            point = point.next;
        }

        if(list1 != null) {
            if(answer == null) {
                return list1;
            }

            point.next = list1;
        }
        else if(list2 != null) {
            if(answer == null) {
                return list2;
            }

            point.next = list2;
        }
        return answer;
    }
}