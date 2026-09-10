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
    public void ReorderList(ListNode head) {
        List<int> arr = [];
        ListNode current = head;
        while (current != null) {
            arr.Add(current.val);
            current = current.next;
        }

        if(arr.Count<3) {return;}
        if(arr.Count == 3) {
            head.next.next.next = head.next;
            head.next = head.next.next;
            head.next.next.next = null;
            return;
        }
        
        int addSize = arr.Count/2;
        
        current = head;

        int last = arr.Count-1;
        while(addSize>0) {
            //Console.WriteLine("Running");
            ListNode h1 = current.next;
            ListNode node =  new ListNode(arr[last], h1);
            current.next = node;
            addSize--;
            last--;
            if(addSize == 0) {
                current = current.next;
                if(arr.Count%2 == 1) {
                    current = current.next;
                }
                current.next = null;
            }
            else{
                current = current.next.next;
            }
        }

    }
}
